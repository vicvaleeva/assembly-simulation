#include <iostream>
#include <ctime>
#include <sys/ioctl.h>
#include <termios.h>

using namespace std;

int _kbhit() {
    static bool inited = false;
    int left;

    if (!inited) {
        termios t;
        tcgetattr(0, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(0, TCSANOW, &t);
        setbuf(stdin, NULL);
        inited = true;
    }

    ioctl(0, FIONREAD, &left);

    return left;
}


int hour = 0, minute = 0, second = 0, flag = true;

void delay(int ms) {
	ms *= 1000;
	clock_t tDelay = ms + clock();
	while (clock() < tDelay);
}

void printData() {
	system("printf \"\033c\"");
	cout << "1. Start   2. Stop   3. Reset   4. Exit\n";
	cout << "---------------------------------------\n";
	cout << "              " << hour << " : " << minute << " : " << second << "\n";
	cout << "---------------------------------------\n";
}

void selection() {
	switch(getc(stdin)) {
		case 49:
			flag = false;
			break;
		case 50:
			flag = true;
			--second;
			printData();
			break;
		case 51:
			flag = true;
			hour = minute = second = 0;
			printData();
			break;
		case 52:
			flag = true;
			exit(0);
			break;
	}
}

void counter() {
	while (!_kbhit() && flag == false) {
		if (minute > 59) {
			++hour;
			minute = 0;
		}
		if (second > 59) {
			++minute;
			second = 0;
		}
		printData();
		delay(1000);
		++second;
	}
	selection();
	printData();
}



int main() {
	while(1) counter();
	return 0;
}