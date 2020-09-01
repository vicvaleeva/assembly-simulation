#include "system.hpp"

void System::init(int set_n, int &set_a, int &set_dt) {
	n = set_n;
	a = set_a;
	dt = set_dt;
	finished = 0;
	
	status.push_back(0);
	status.push_back((a / n) + dt);
	if (n != 1) status.push_back(0);

	for (int i = 3; i <= n; ++i) {
		status.push_back(-1);
	}

	status.push_back(-273);
	
}

void System::update() {
	for (int i = 1; i <= n; ++i) {
		if (status[i] != 0 && status[i] != -1) {
			--status[i];	
			if (i == n && status[i] == 0) ++finished;
		}
	}
	for (int i = n; i >= 1; --i) {
		if (status[i] == 0 && status[i - 1] == 0) {
			double r = ((double) rand() / (RAND_MAX));
			if (r <= 0.01) {
				status[i] += a;
			} else {
				status[i] = (a / n) + dt;
				if (status[i + 1] == -1) status[i + 1] = 0;
			}
		}
	}
}

int System::getFinished() {
	return finished;
}
