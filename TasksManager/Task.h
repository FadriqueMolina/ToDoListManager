#pragma once
#include <iostream>

class Task
{
public:
	Task(int id,std::string name, bool isCompleted = false):
		m_id(id),
		m_name(name),
		m_isCompleted(isCompleted)
	{}

	void setCompleted(bool completed) { m_isCompleted = completed; }

	void printTask()
	{
		std::string completed = m_isCompleted ? "YES" : "NO";
		std::cout << "Id: " << m_id << "   Completed: " << completed << "   Name: " << m_name << std::endl;
	}

private:
	int m_id;
	std::string m_name;
	bool m_isCompleted;
};