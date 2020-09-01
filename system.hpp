#include <iostream>
#include <vector>

using namespace std;

class System {
	int n;
	int a;
	int dt;
	int finished;
	vector<int> status;

public:
	void init(int &set_n, int &set_a, int &set_dt, int &set_finished);
	void update();
	int getFinished();

};