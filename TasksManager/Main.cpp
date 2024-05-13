#include <conio.h>
#include <iostream>
#include <string>
#include "TaskListManager.h"

using namespace std;

void pauseAndClearConsole()
{
    system("pause");
    system("cls");
}

int main()
{
    int option = 0;
    bool salir = false;
    string taskToAdd;
    int taskId = -1;

    while (salir == false)
    {
        cout << "Elige la opcion:" << endl;
        cout << "1) Agregar tarea" << endl;
        cout << "2) Completar una tarea" << endl;
        cout << "3) Mostrar la lista de tareas" << endl;
        cout << "4) Salir" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Escribe la tarea: ";
            cin.ignore();
            getline(cin, taskToAdd);
            cout << "" << endl;
            TaskListManager::getInstance()->addTask(taskToAdd);
            break;
        case 2:
            cout << "Escribe el Id de la tarea: ";
            cin >> taskId;
            cout << "" << endl;
            TaskListManager::getInstance()->setTaskAsCompleted(taskId);
            break;
        case 3:
            TaskListManager::getInstance()->showAllTasks();
            break;
        case 4:
            salir = true;
            break;
        default:
            cout << "Opcion erronea, intenta de nuevo." << endl;
            break;
        }
        pauseAndClearConsole();
    }
    
    cout << "Hasta luego" << endl;

}
