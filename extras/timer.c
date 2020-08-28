#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <termios.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <pthread.h> 

int keyboardhit(void) 
{ 
    struct termios oldt, newt; 
    int ch; 
    int oldf; 
  
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt; 
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); 
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); 
  
    ch = getchar(); 
  
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    fcntl(STDIN_FILENO, F_SETFL, oldf); 
  
    if (ch != EOF) { 
        ungetc(ch, stdin); 
        return 1; 
    } 
  
    return 0; 
}


int hour = 0, minute = 0, second = 0, flag = 1;

int printData(void) {
	system("printf \"\033c\"");
	printf("1. Start   2. Stop   3. Reset   4. Exit\n");
	printf("---------------------------------------\n");
	printf("              %d : %d : %d\n", hour, minute, second);
	printf("---------------------------------------\n");
}

int counter(void) {
	while (!keyboardhit() && flag == 0) {
		if (minute > 59) {
			++hour;
			minute = 0;
		}
		if (second > 59) {
			++minute;
			second = 0;
		}
		delay(1000);
		printData();
		second += 1;
	}
	selection();
}

int selection(void) {
	switch(getchar()) {
		case 49:
			flag = 0;
			break;
		case 50:
			flag = 1;
			break;
		case 51:
			flag = 1;
			hour = minute = second = 0;
			printData();
			break;
		case 52:
			flag = 1;
			exit(0);
			break;
	}
}

int delay(ms) {
	ms *= 1000;
	clock_t tDelay = ms + clock();
	while (tDelay > clock());
}

int main(void) {
	system("printf \"\033c\"");
	printf("Enter 1 to start\n");
	while(1) {
		counter();
	}

	return 0;
}
