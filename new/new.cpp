#include "new.hpp"

void New::init(int set_n, int set_a, int set_dt, int set_finished) {
	n = set_n;
	a = set_a;
	dt = set_dt;
	finished = set_finished;
}

void New::update(int time) {
	if (time % (a + 2 * dt) == 0 && time != 0) {
		finished += n;
	}
}

int New::getFinished() {
	return finished;
}
