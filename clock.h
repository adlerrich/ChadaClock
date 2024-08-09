#ifndef CLOCK_H
#define CLOCK_H
#include <string>

class Clock {
	private:
		int hour;
		int minute;
		int second;

		void IncrementHour();
		void IncrementMinute();
		void IncrementSecond();
		std::string Format12HourTime();
		int ValidateClockInput(std::string inputParameter);
		void PrintTime(std::string amOrPm = "");

	public:
		void PrintClock();
		void IncrementClock(int option);
		void GetInitialClock();
};

#endif
