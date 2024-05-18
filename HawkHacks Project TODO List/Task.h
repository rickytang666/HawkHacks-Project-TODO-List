#pragma once

// include necessary libraries and packages
#include<iostream>
#include<string>

// namespace

using namespace std;

// Constants

#define STAR "★"
#define NORMAL "●"

// class

class Task
{
public:

	// constructor
	Task(string name, int star_choice, string duedate = "No due date");

	// get the star part of the task
	string get_importance();

	// display the whole task
	void display_task();

	// members
	string m_Name; // name of the task
	string m_DueDate; // due date of the task
	bool m_Stared; //determine if the task is super important

};