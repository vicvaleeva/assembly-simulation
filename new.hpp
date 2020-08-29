#include <iostream>
using namespace std;

class New {
	int n;
	int a;
	int dt;
	int finished;

public: 
	New(int set_n, int set_a, int set_dt, int set_finished);
	void update(int time);
	int getFinished();
};