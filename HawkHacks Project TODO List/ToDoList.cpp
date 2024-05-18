#include "ToDoList.h"

ToDoList::ToDoList()
{

}

ToDoList::~ToDoList()
{

}

void ToDoList::showMenu()
{
	cout << "********************************" << endl;
	cout << "Welcome to my To-do List!" << endl;
	cout << "Enter 1 to create a new task" << endl;
	cout << "Enter 2 to delete a task" << endl;
	cout << "Enter 3 to modify a task" << endl;
	cout << "Enter 4 to see all your tasks" << endl;
	cout << "Enter 5 to clear all your tasks" << endl;
	cout << "Enter other to quit the applet" << endl;
	cout << "********************************" << endl;

	cout << endl; //For seperation
}