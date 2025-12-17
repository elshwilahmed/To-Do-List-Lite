#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
	int id;
	string name;
	string description = "";
	bool isComplete;
	static int cnt;
};
int Task::cnt = 0;
void ResetScreen() {
	system("cls");
}

char ReadChar(string s) {
	char c;
	do {
		cout << s;
		cin >> c;
	} while (tolower(c) != 'y' && tolower(c) != 'n');
	return tolower(c);
}

short ReadChoice() {
	short number;
	do {
		while (!(cin >> number)) {
			cout << "Please Enter Number Not Character: ";
			cin.clear();
			cin.ignore();
		}
	} while (number > 3 || number < 1);
	return number;
}

int ReadID(vector<Task>& Tasks) {
	int ID;
	do {
		while (!(cin >> ID)) {
			cout << "Please Enter Number Not Character: ";
			cin.clear();
			cin.ignore();
		}
	} while (ID<0 || ID > Tasks.size());
	return ID;
}

void PrintTask(Task task) {
	cout << "\n______________________________________\n";
	cout << "\nTask ID: " << task.id;
	cout << "\nTask Name: " << task.name << '\n';
	if (!task.description.empty())
		cout << "Description: " << task.description << '\n';
	string completed;
	(task.isComplete) ? completed = "Done" : completed = "Not Done!";
	cout << "Task Statue: " << completed << '\n';
	cout << "\n______________________________________\n";
}

bool TObool(char Statue) {
	return Statue == 'y';
}

void AddTask(vector<Task>& Tasks) {
	Task NewTask; Task::cnt++;
	NewTask.id = Task::cnt;
	cout << "\nEnter Task Name\n";
	cin.ignore();
	getline(cin, NewTask.name);
	char optional = ReadChar("Do You Want Add Describtion?(y/n) ");
	if (TObool(optional)) {
		string des;
		cout << "Describtion: ";
		cin.ignore(); getline(cin, des);
		NewTask.description = des;
	}
	char TaskStatue = ReadChar("Is completed(y/n)?");
	NewTask.isComplete = TObool(TaskStatue);
	Tasks.push_back(NewTask);
}

void DisplayTasks(const vector<Task>& Tasks) {
	if (Tasks.empty()) {
		cout << "NO Tasks\n";
		return;
	}
	for (auto& task : Tasks) {
		PrintTask(task);
	}
}

void MarkTaskComplete(vector<Task>& Tasks) {
	cout << "Enter Task Id: ";
	int ID = ReadID(Tasks);

	for (auto& task : Tasks) {
		if (task.id == ID) {
			task.isComplete = true;
			break;
		}
	}
}

void DoOperation(short choice, vector<Task>& Tasks) {
	switch (choice) {
	case 1:
		AddTask(Tasks);
		break;

	case 2:
		DisplayTasks(Tasks);
		break;

	case 3:
		MarkTaskComplete(Tasks);
		break;
	}
}

void StartProgram() {
	char again = ' ';
	vector<Task> Tasks;
	do {
		ResetScreen();
		cout << "Operations: \n";
		cout << "1.Add Task\n";
		cout << "2.Display all Tasks\n";
		cout << "3.Mark Task Complete\n";
		cout << "Choose Your Operation: ";
		short choice = ReadChoice();

		DoOperation(choice, Tasks);


		again = ReadChar("Do You Want Any Operation again??(y/n) ");
	} while (again == 'y');
}
int main()
{
	StartProgram();

	return 0;
}

