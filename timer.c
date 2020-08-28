#include <stdio.h>
#include <stdlib.h>

int hour = 0, minute = 0, second = 0, flag = 0;

void printData() {
	system("printf \"\033c\"");
	printf("1. Start   2. Stop   3. Reset   4. Exit\n");
	printf("---------------------------------------\n");
	printf("              %d : %d : %d\n", hour, minute, second);
	printf("---------------------------------------\n");
}

int main(void) {
	
	printData();

	return 0;
}
