#include <stdio.h>
#include <unistd.h>
#define MAX_SIZE 5

int main() {
	setvbuf(stdout, NULL, _IOLBF, MAX_SIZE);
	
	printf("H");\
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);

	return 0;
}