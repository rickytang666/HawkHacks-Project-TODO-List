#include "ToDoList.h"

ToDoList::ToDoList()
{

}

ToDoList::~ToDoList()
{
	cout << "See you again. I hope you enjoyed my To-do list :)" << endl;
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


void ToDoList::searchTask(const string& input)
{
	// Clear previous search results
	m_SearchResults.clear();

	for (auto it = m_TasksList.begin(); it != m_TasksList.end(); ++it)
	{
		string taskNameLower = it->m_Name;
		string searchStringLower = input;

		// Convert task name and search string to lower case for case-insensitive search
		std::transform(taskNameLower.begin(), taskNameLower.end(), taskNameLower.begin(), ::tolower);
		std::transform(searchStringLower.begin(), searchStringLower.end(), searchStringLower.begin(), ::tolower);

		if (taskNameLower.find(searchStringLower) != string::npos)
		{
			// Store the iterator of the matching task in m_SearchResults
			m_SearchResults.push_back(it);
		}
	}
}


void ToDoList::deleteTask()
{
	string input = "";
	cout << "Enter the name of the task you wanna delete: " << endl;
	cin.ignore();
	getline(cin, input);

	this->searchTask(input); // searching

	if (!this->m_SearchResults.empty())
	{
		for (int i = 0; i < m_SearchResults.size(); ++i)
		{
			cout << i + 1 << " : ";
			m_SearchResults[i]->display_task();
		}

		cout << endl;

		int choice = 0;

		cout << "What would you like to delete?  ";

		cin >> choice;

		if (choice <= 0 || choice > m_SearchResults.size())
		{
			cout << "Deletion failed because of invalid input" << endl;
		}
		else
		{
			this->m_TasksList.erase(m_SearchResults[choice - 1]);
			cout << "Success" << endl;
		}
	}
}


void ToDoList::modifyTask()
{
	string input = "";
	cout << "Enter the name of the task you want to modify: " << endl;
	cin.ignore();
	getline(cin, input);

	this->searchTask(input); // searching

	if (!this->m_SearchResults.empty())
	{
		for (int i = 0; i < m_SearchResults.size(); ++i)
		{
			cout << i + 1 << " : ";
			m_SearchResults[i]->display_task();
		}

		cout << endl;

		int choice = 0;

		cout << "Which task would you like to modify?  ";

		cin >> choice;

		if (choice <= 0 || choice > m_SearchResults.size())
		{
			cout << "Modification failed because of invalid input" << endl;
		}
		else
		{
			// Modify the selected task
			string newName;
			int newStarChoice;
			string newDueDate;

			cout << "Enter the new name of the task: ";
			cin.ignore();
			getline(cin, newName);

			cout << "Enter the new importance of the task (1 for starred, otherwise not starred): ";
			cin >> newStarChoice;
			cin.ignore();

			int duedate_confirm = 0;
			cout << "Does it have a due date? (Press 1 to confirm, otherwise deny)  ";
			cin >> duedate_confirm;
			cin.ignore();

			if (duedate_confirm != 1)
			{
				newDueDate = "No due date";
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
					newDueDate = "No due date";
				}
				else
				{
					newDueDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
				}
			}

			// Update the task
			(*m_SearchResults[choice - 1]).m_Name = newName;
			(*m_SearchResults[choice - 1]).m_Stared = (newStarChoice == 1);
			(*m_SearchResults[choice - 1]).m_DueDate = newDueDate;

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

void ToDoList::clearTasks()
{
	int confirm = 0;
	cout << "Are you sure you want to do that? This operation is irreversible" << endl;
	cout << "Press 1 to confirm and press other to deny:  ";
	cin >> confirm;

	if (confirm == 1)
	{
		if (this->m_TasksList.empty())
		{
			cout << "You don't have any tasks!" << endl;
		}
		else
		{
			this->m_TasksList.clear();
			cout << "Cleared" << endl;
		}
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
			this->deleteTask();
		}
		else if (choice == 3)
		{
			this->modifyTask();
		}
		else if (choice == 4)
		{
			this->displayTasks();
		}
		else if (choice == 5)
		{
			this->clearTasks();
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