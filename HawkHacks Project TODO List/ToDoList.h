#pragma once

// include the necessary libraries

#include<iostream>

//namespace

using namespace std;

//Constants

#define STAR "★"
#define NOMRAL "●"

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

};