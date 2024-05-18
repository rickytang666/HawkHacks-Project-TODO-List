#include "Task.h"

class CompareTasks
{
public:

    bool compareDates(const string& d1, const string& d2) const
    {
        
        // Split the dates by "-"
        stringstream ss1(d1);
        stringstream ss2(d2);
        vector<int> date1, date2;
        string temp;

        while (getline(ss1, temp, '-')) 
        {
            date1.push_back(stoi(temp));
        }

        while (getline(ss2, temp, '-'))
        {
            date2.push_back(stoi(temp));
        }

        // Compare the dates
        return date1 < date2;
    }

	bool operator() (const Task& task1, const Task& task2) const
	{
        // First, compare based on completion
        if (task1.m_Completed != task2.m_Completed)
        {
            return task1.m_Completed < task2.m_Completed;
        }

        // then compare based on importance
        if (task1.m_Stared != task2.m_Stared) 
        {
            return task1.m_Stared > task2.m_Stared;  // Starred tasks come first
        }

        // If importance is the same, compare based on due date
        if (task1.m_DueDate != task2.m_DueDate) 
        {
            return compareDates(task1.m_DueDate, task2.m_DueDate);  // Earlier due dates come first
        }

        // If due dates are also the same, compare based on name
        return task1.m_Name < task2.m_Name;  // Alphabetically earlier names come first

	}

};