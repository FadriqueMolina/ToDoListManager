#pragma once
#include "Task.h"
#include <memory>
#include <map>

class TaskListManager
{
public:
	static std::shared_ptr<TaskListManager> getInstance() {
		static std::shared_ptr<TaskListManager> instance(new TaskListManager);
		return instance;
	}

	TaskListManager(const TaskListManager&) = delete;
	TaskListManager& operator=(const TaskListManager&) = delete;

	void addTask(const std::string& name);

	void removeTask(int id);

	void setTaskAsCompleted(int id);

	void showAllTasks();

private:
	static int s_id;
	TaskListManager() = default;
	std::map<int, Task> m_taskCollection;
};