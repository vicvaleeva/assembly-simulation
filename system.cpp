#include "system.hpp"

void System::init(int &set_n, int &set_a, int &set_dt, int &set_finished) {
	n = set_n;
	a = set_a;
	dt = set_dt;
	finished = set_finished;
}

void System::update() {
	
}

int System::getFinished() {
	return finished;
}
