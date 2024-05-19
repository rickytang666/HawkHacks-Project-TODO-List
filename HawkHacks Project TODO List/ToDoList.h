#pragma once

// include the necessary libraries

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Task.h"
#include "CompareTasks.cpp"
#include "CheckDateValidity.cpp"

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

	// mark a task done

	void markDone();

	// Display all the tasks
	
	void displayTasks();

	// filter out certain types of tasks
	void filterTasks();

	// Update the tasks (Sorting them)
	
	void updateTasks();

	// clear all the tasks

	void clearTasks();

	// the main function to run the app
	
	void runApp();

	// members
	vector<Task> m_TasksList;
	vector<vector<Task>::iterator> m_SearchResults;

};