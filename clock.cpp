#include <iostream>
#include <limits>
#include <string>
#include "clock.h"

using namespace std;

void Clock::IncrementHour() {
	this->hour = (this->hour + 1) % 24;
}

void Clock::IncrementMinute() {
	if (this->minute == 59) {
		IncrementHour();
	}

	this->minute = (this->minute + 1) % 60;
}

void Clock::IncrementSecond() {
	if (this->second == 59) {
		IncrementMinute();
	}

	this->second = (this->second + 1) % 60;
}

string Clock::Format12HourTime() {
	if (this->hour == 0 || this->hour == 12) {
		return "12";
	} else if ((this->hour % 12) > 9) {
		return  to_string(this->hour % 12);
	} else {
		return "0" + to_string(this->hour % 12);
	}
}

// prints the clock itself, default parameter is "" to jump straight to 24 clock
void Clock::PrintTime(string amOrPm) {
	// add a 0 to the beginning of the string if parameters are less than ten to maintain formatting
	string hour;
	string minute = (this->minute < 10) ? "0" + to_string(this->minute) : to_string(this->minute);
	string second = (this->second < 10) ? "0" + to_string(this->second) : to_string(this->second);

	// if amOrPm is not default value, then add it to the print statement, and correctly format hour 
	// for either 24 or 12 hour format
	if (amOrPm != "") {
		hour = Clock::Format12HourTime();
		cout << "*  " << hour << ":" << minute << ":" << second << amOrPm << "  *";
	} else {
		// 24 hour needs no formatting beyond the initial checks
		hour = (this->hour < 10) ? "0" + to_string(this->hour) : to_string(this->hour);
		cout << "*     " << hour << ":" << minute << ":" << second << "     *" << endl;
	}
}

void Clock::PrintClock() {
	string timeTwelveHour = (this->hour > 11) ? " P M " : " A M ";

	cout << "*******************\t********************" << endl;
	cout << "*  12-Hour Clock  *\t*   24-Hour Clock  * " << endl;
	PrintTime(timeTwelveHour);
	cout << "\t";
	PrintTime();
	cout << "*******************\t********************" << endl;
}

// options defined in menu.cpp
void Clock::IncrementClock(int option) {
	switch (option) {
		case 1:
			IncrementHour();
			break;
		case 2:
			IncrementMinute();
			break;
		case 3:
			IncrementSecond();
			break;
		case 4:
			break;
		default:
			cout << "Invalid input, please choose 1, 2, 3, or 4" << endl;
			cout << endl;
	}
}

	
int Clock::ValidateClockInput(string inputParameter) {
	int validatedInput;
	cout << inputParameter;
	cin >> validatedInput;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please provide an integer." << endl;
		cout << inputParameter;
		cin >> validatedInput;
	}

	return validatedInput;
}

void Clock::GetInitialClock() {

	int hour = Clock::ValidateClockInput("Input Hours: ");
	int minute = Clock::ValidateClockInput("Input Minutes: ");
	int second = Clock::ValidateClockInput("Input Seconds: ");

	this->hour = hour % 24;
	this->minute = minute % 60;
	this->second = second % 60;
	cout << endl;
}

