#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

void Menu::DisplayMenu() {
	cout << "************************" << endl;
	cout << "* 1 Add one hour       *"<< endl;
	cout << "* 2-Add one minute     *" << endl;
	cout << "* 3-Add one second     *" << endl;
	cout << "* 4-Exit program       *" << endl;
	cout << "************************" << endl;
	cout << endl;
	cout << "Menu Option: ";
}

int Menu::GetMenuInput() {
	int userInput;
	cin >> userInput;
		
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> userInput;
	}

	cout << endl;
	return userInput;
}

