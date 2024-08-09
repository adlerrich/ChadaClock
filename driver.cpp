#include "clock.h"
#include "menu.h"
#include <iostream>

using namespace std;

int main() {
	Clock clock;
	Menu menu;
	int userInput;

	clock.GetInitialClock();
	do {
		clock.PrintClock();
		cout << endl;
		cout << endl;
		menu.DisplayMenu();
		userInput = menu.GetMenuInput();
		clock.IncrementClock(userInput);
	} while (userInput != 4);
}
