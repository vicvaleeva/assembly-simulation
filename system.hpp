class System {
	int n;
	int a;
	int dt;
	int type;
	int finished = 0;

public: 
	AssemblySystem(int set_n, int set_a, int set_dt, int set_type);
	void update();
};