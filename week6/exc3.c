#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
	if (sig == SIGINT)
		printf("SIGINT signal was used\n");
}

int main() {
	signal(SIGINT, signal_handler);
	while(1)
		sleep(1);
}