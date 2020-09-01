#include <iostream>
#include <ctime>
#include "system.hpp"

using namespace std;

int n_o, a_o, dt_o, finished_o, n_n, a_n, dt_n, finished_n;
Old oldsys;
New newsys;
int hour = 0, minute = 0, second = 0;
int stoptimeOld, stoptimeNew;
bool oldStopped = false, newStopped = false;

void delay(int ms) {
	ms *= 2;
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

bool changed(int &a, int &b) {
	return a == b ? false : true;
}

bool defect(bool &flag, int &stoptime, int &current, int &a, int &oldValue, int &newValue, double chance) {
	if (flag == false) {
		double r = ((double) rand() / (RAND_MAX));
		if (r <= chance) {
			flag = true;
			stoptime = current + a * 2;
		}	
	}
	if ((flag == true) && (changed(oldValue, newValue))) {
		if (current < stoptime) {
			return true;
		} else {
			flag = false;
			return false;
		}
	}

	return false;
}

void cycle() {
	while(true) {
		int current_time = hour * 3600 + minute * 60 + second;
		int oldsys_old = oldsys.getFinished();
		oldsys.update(current_time);	
		int oldsys_new = oldsys.getFinished();

		int newsys_old = newsys.getFinished();
		newsys.update(current_time);
		int newsys_new = newsys.getFinished();
		
		if (defect(oldStopped, stoptimeOld, current_time, a_o, oldsys_old, oldsys_new, 0.02)) oldsys.defectObserved();

		if (defect(newStopped, stoptimeNew, current_time, a_n, newsys_old, newsys_new, 0.02)) newsys.defectObserved();

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
