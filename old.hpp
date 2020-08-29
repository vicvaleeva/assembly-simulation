#include <iostream>
using namespace std;

class Old {
	int n;
	int a;
	int dt;
	int finished;

public: 
	System(int set_n, int set_a, int set_dt, int set_finished);
	void update();
};