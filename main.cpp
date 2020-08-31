#include <iostream>
#include <ctime>
#include "old/old.hpp"
#include "new/new.hpp"

using namespace std;

int n_o, a_o, dt_o, finished_o, n_n, a_n, dt_n, finished_n;
Old oldsys;
New newsys;
int hour = 0, minute = 0, second = 0;
int stoptimeOld, stoptimeNew;
bool isOldStopped, isNewStopped;

void delay(int ms) {
	ms *= 20;
	clock_t timeDelay = ms + clock();
	while(clock() < timeDelay);
}

void printData() {
	system("printf \"\033c\"");
	cout << "\n\n";
	cout << "   OLD: N = " << n_o << ", a = " << a_o << ", t = " << dt_o << ", finished " << finished_o << "\n";
	cout << "   NEW: N = " << n_n << ", a = " << a_n << ", t = " << dt_n << ", finished " << finished_n << "\n";
	cout << "\n\n\n" << "        old" << "          new" << "             time\n\n";
	cout << "        " << oldsys.getFinished() << "          " << newsys.getFinished() << "          ";
	cout << hour << " : " << minute << " : " << second << "\n\n\n";
	if (oldsys.getFinished() > 0) {
		double nw = (newsys.getFinished() - finished_n) * 1.0;
		double ol = (oldsys.getFinished() - finished_o) * 1.0;
		double ratio = nw / ol;
		cout << "   Current ratio (old / new): " << ratio << "\n";
	}
	cout << "\n   Press Ctrl+Z to exit\n";
}

void cycle() {
	while(true) {
		int current_time = hour * 3600 + minute * 60 + second;
		oldsys.update(current_time);	
		newsys.update(current_time);

		printData();
		delay(1000);
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
