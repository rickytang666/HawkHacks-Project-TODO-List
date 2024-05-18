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

void ToDoList::addTask()
{
	// enter the name
	string name = "";
	cout << "Enter the name of the task:  " << endl;
	cin.ignore();  // Ignore any leftover newline character in the input buffer
	getline(cin, name);

	// enter the importance
	int star_choice = 0;
	cout << "Is this task starred? (Press 1 to confirm, otherwise deny)  ";
	cin >> star_choice;
	cin.ignore();  // Ignore the newline character left by cin >>

	// enter the due date
	int duedate_confirm = 0;
	cout << "Does it have a due date? (Press 1 to confirm, otherwise deny)  ";
	cin >> duedate_confirm;
	cin.ignore();  // Ignore the newline character left by cin >>

	if (duedate_confirm != 1)
	{
		this->m_TasksList.push_back(Task(name, star_choice));
		cout << "Success" << endl;
	}
	else
	{
		int year, month, day;
		cout << "Enter the due date year (YYYY): ";
		cin >> year;
		cout << "Enter the due date month (MM): ";
		cin >> month;
		cout << "Enter the due date day (DD): ";
		cin >> day;

		// Check if the inputs are valid
		if (cin.fail() || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		{
			cin.clear(); // clear the error state of cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the line
			cout << "Invalid input. Setting due date to 'No due date'.\n";
			this->m_TasksList.push_back(Task(name, star_choice));
		}
		else
		{
			string duedate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
			this->m_TasksList.push_back(Task(name, star_choice, duedate));
			cout << "Success" << endl;
		}
	}
	
}


void ToDoList::updateTasks()
{
	sort(this->m_TasksList.begin(), this->m_TasksList.end(), CompareTasks());
}


void ToDoList::displayTasks()
{

	if (!this->m_TasksList.empty())
	{
		cout << "In total there are " << this->m_TasksList.size() << " tasks in your list" << endl;

		cout << endl;

		for (Task& t : this->m_TasksList)
		{
			t.display_task();
		}
	}
	else
	{
		cout << "Your list is empty" << endl;
	}

}


void ToDoList::runApp()
{
	while (true)
	{
		this->showMenu();

		int choice = 0;

		cout << "Enter your choice  ";

		cin >> choice;

		cout << endl; // seperation

		if (choice == 1)
		{
			this->addTask();

		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

		}
		else if (choice == 4)
		{
			this->displayTasks();
		}
		else if (choice == 5)
		{

		}
		else
		{
			break;
		}

		this->updateTasks();

		system("pause");
		system("cls");

	}
}