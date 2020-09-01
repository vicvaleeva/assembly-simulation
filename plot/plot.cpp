#include <iostream>
#include <vector>
#include <ctime>
#include <sys/ioctl.h>
#include <termios.h>
#include <fstream>
#include <iterator>
#include <string>
#include "../class/system.hpp"

using namespace std;

int n_o = 6, a_o = 232, dt_o = 5, n_n = 6, a_n = 232, dt_n = 5;

System oldsys;
vector<System> newsys;

vector<double> ratios;

int second = 0;

int getFinishedNew(vector<System> &v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i].getFinished();
	}

	return sum;
}

void addRatio() {
	if (oldsys.getFinished() > 0) {
		double nw = getFinishedNew(newsys) * 1.0;
		double ol = oldsys.getFinished() * 1.0;
		double ratio = nw / ol;
		ratios.push_back(ratio);
	} else {
		ratios.push_back(0);
	}
}

void cycle() {
	while(second <= 28800) {
		addRatio();
		++second;
		oldsys.update();
		for (int i = 0; i < newsys.size(); ++i) {
			newsys[i].update();
		}
	}
	
	ofstream outFile("text/results.txt");
	for (const auto &e : ratios) outFile << e << "\n";
	
}

int main() {
	oldsys.init(n_o, a_o, dt_o);
	for (int i = 0; i < n_n; ++i) {
		System element;
		element.init(1, a_n, dt_n);
		newsys.push_back(element);
	}
	cycle();

	return 0;
}
