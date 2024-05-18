#pragma once

// include the necessary libraries

#include<iostream>
#include<vector>
#include<algorithm>
#include "Task.h"
#include "CompareTasks.cpp"

//namespace

using namespace std;

//Classes

class ToDoList
{
public:

	//constructor

	ToDoList();

	//destructor

	~ToDoList();

	// the function for showing menu to user

	void showMenu();

	// Adding a task

	void addTask();

	// Search for task given a keyword

	void searchTask(const string& input);

	// delete task given a keyword

	void deleteTask();

	// modify task

	void modifyTask();

	// Display all the tasks
	
	void displayTasks();

	// Update the tasks (Sorting them)
	
	void updateTasks();

	// the main function to run the app
	
	void runApp();

	// members
	vector<Task> m_TasksList;
	vector<vector<Task>::iterator> m_SearchResults;

};