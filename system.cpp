#include "system.hpp"

void System::init(int &set_n, int &set_a, int &set_dt, int &set_finished) {
	n = set_n;
	a = set_a;
	dt = set_dt;
	finished = set_finished;
	
	status.push_back(0);
	status.push_back((a / n) + dt);
	status.push_back(0);

	for (int i = 3; i <= n; ++i) {
		status.push_back(-1);
	}

	status.push_back(0);
	
}

void System::update() {
	
}

int System::getFinished() {
	return finished;
}
