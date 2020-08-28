#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int hour = 0, minute = 0, second = 0, flag = 0;

void printData() {
	system("printf \"\033c\"");
	printf("1. Start   2. Stop   3. Reset   4. Exit\n");
	printf("---------------------------------------\n");
	printf("              %d : %d : %d\n", hour, minute, second);
	printf("---------------------------------------\n");
}

void counter() {
	printData();
	while (!hitkb() && flag == 0) {
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
}	

void delay(ms) {
	current = clock();
	while (clock() - current < ms);
}

int main() {
	
	printData();

	return 0;
}
