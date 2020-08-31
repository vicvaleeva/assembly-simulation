#include <iostream>
#include <ctime>
#include "old/old.hpp"
#include "new/new.hpp"

using namespace std;

int n_o, a_o, dt_o, finished_o, n_n, a_n, dt_n, finished_n;
Old oldsys;
New newsys;
int hour = 0, minute = 0, second = 0;

void delay(int ms) {
	ms *= 1000;
	clock_t timeDelay = ms + clock();
	while(clock() < timeDelay);
}

void printData() {
	system("printf \"\033c\"");
	cout << "\n\n\n" << "        " << oldsys.getFinished() << "          " << newsys.getFinished() << "          ";
	cout << hour << " : " << minute << " : " << second << "\n\n\n";
}

void cycle() {
	while(true) {
		int current_time = hour * 3600 + minute * 60 + second;
		oldsys.update(current_time);
		newsys.update(current_time);

		printData();
		++second;
		
		if (second > 59) {
			++minute;
			second = 0;
		}	

		if (minute > 59) {
			++hour;
			minute = 0;
		}
		
	}
}

int main() {

	system("printf \"\033c\"");

	cout << "Enter parameters for the OLD system:\n";
	cout << "Number in crew: ";
	cin >> n_o;
	cout << "\n";
	cout << "Total operation time: ";
	cin >> a_o;
	cout << "\n";
	cout << "Single handover time: ";
	cin >> dt_o;
	cout << "\n";
	cout << "Number of products finished: ";
	cin >> finished_o;
	cout << "\n";
	cout << "#########################################";
	cout << "\n\n";
	cout << "Enter parameters for the NEW system:\n";
	cout << "Number in crew: ";
	cin >> n_n;
	cout << "\n";
	cout << "Total operation time: ";
	cin >> a_n;
	cout << "\n";
	cout << "Single handover time: ";
	cin >> dt_n;
	cout << "\n";
	cout << "Number of products finished: ";
	cin >> finished_n;
	cout << "\n\n";

	oldsys.init(n_o, a_o, dt_o, finished_o);
	newsys.init(n_n, a_n, dt_n, finished_n);

	cycle();

	return 0;
}
