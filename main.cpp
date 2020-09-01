#include <iostream>
#include <vector>
#include <ctime>
#include <sys/ioctl.h>
#include <termios.h>
#include "system.hpp"

using namespace std;

int kbhit() {
	static bool inited = false;
	int left;

	if (!inited) {
		termios t;
		tcgetattr(0, &t);
		t.c_lflag &= ~ICANON;
		tcsetattr(0, TCSANOW, &t);
		setbuf(stdin, NULL);
		inited = true;
	}

	ioctl(0, FIONREAD, &left);

	return left;
}

void selection() {
	if (getc(stdin) == 49) {
		exit(0);
	}
}

int n_o, a_o, dt_o, n_n, a_n, dt_n;

System oldsys;
vector<System> newsys;

int hour = 0, minute = 0, second = 0;

void delay(int ms) {
	ms *= 20;
	clock_t timeDelay = ms + clock();
	while(clock() < timeDelay);
}

int getFinishedNew(vector<System> &v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i].getFinished();
	}

	return sum;
}

void printData() {
	system("printf \"\033c\"");
	cout << "\n\n";
	cout << "   OLD: N = " << n_o << ", a = " << a_o << ", t = " << dt_o << "\n";
	cout << "   NEW: N = " << n_n << ", a = " << a_n << ", t = " << dt_n << "\n";
	cout << "\n\n\n" << "        old" << "          new" << "             time\n\n";
	cout << "        " << oldsys.getFinished() << "          " << getFinishedNew(newsys) << "          ";
	cout << hour << " : " << minute << " : " << second << "\n\n\n";
	if (oldsys.getFinished() > 0) {
		double nw = getFinishedNew(newsys) * 1.0;
		double ol = oldsys.getFinished() * 1.0;
		double ratio = nw / ol;
		cout << "   Current ratio (new / old): " << ratio << "\n";
	}
	cout << "\n   Press 1 to stop and exit\n\n";
}

void cycle() {
	while(!kbhit()) {
		printData();
		delay(1000);
		++second;
		oldsys.update();
		for (int i = 0; i < newsys.size(); ++i) {
			newsys[i].update();
		}
		if (second > 59) {
			++minute;
			second = 0;
		}	

		if (minute > 59) {
			++hour;
			minute = 0;
		}
		
	}
	selection();
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
	cout << "\n\n";
	oldsys.init(n_o, a_o, dt_o);
	for (int i = 0; i < n_n; ++i) {
		System element;
		element.init(1, a_n, dt_n);
		newsys.push_back(element);
	}
	cycle();

	return 0;
}
