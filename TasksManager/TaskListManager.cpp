#include <iostream>
#include "TaskListManager.h"

int TaskListManager::s_id = 0;

void TaskListManager::addTask(const std::string & name)
{
	auto par = std::pair<int, Task>(s_id, Task(s_id, name));
	m_taskCollection.insert(par);
	std::cout << "Elemento agregado con ID " << s_id << std::endl;
	s_id++;
}

void TaskListManager::removeTask(int id)
{
	auto it = m_taskCollection.find(id);

	if (it != m_taskCollection.end())
	{
		m_taskCollection.erase(it);
		std::cout << "Elemento removido con exito." << std::endl;
	}
	else
	{
		std::cout << "Elemento no encontrado." << std::endl;
	}
}

void TaskListManager::setTaskAsCompleted(int id)
{
	auto it = m_taskCollection.find(id);

	if (it != m_taskCollection.end())
	{
		it->second.setCompleted(true);
		std::cout << "Elemento modificado con exito." << std::endl;
	}
	else
	{
		std::cout << "Elemento no encontrado." << std::endl;
	}
}

void TaskListManager::showAllTasks()
{
	for (auto it : m_taskCollection)
	{
		it.second.printTask();
	}
}



