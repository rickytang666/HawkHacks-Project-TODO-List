#include "Task.h"

Task::Task(string name, int star_choice, string duedate)
{
    this->m_Name = name;
    this->m_DueDate = duedate;
    
    if (star_choice == 1)
    {
        this->m_Stared = true;
    }
    else
    {
        this->m_Stared = false;
    }
}

string Task::get_importance()
{
    if (this->m_Stared)
    {
        return STAR;
    }
    else
    {
        return NORMAL;
    }
}

void Task::display_task()
{
    cout << get_importance() << " Task: " << this->m_Name << "     Due: " << this->m_DueDate << endl;
}