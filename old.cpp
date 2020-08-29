#include "old.hpp"

Old::Old(int set_n, int set_a, int set_dt, int set_finished) {
	n = set_n;
	a = set_a;
	dt = set_dt;
	finished = set_finished;
}

void Old::update(int time) {
	if (((time - (a + dt * (n + 1))) % ((a / n) + dt) == 0) && time >= (a + dt * (n + 1))) {
		++finished;
	}
}

int Old::getFinished() {
	return finished;
}