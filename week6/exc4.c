#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
	switch(sig) {
	case SIGKILL:
		printf("SIGKILL signal was used\n");
		break;
	case SIGSTOP:
		printf("SIGSTOP signal was used\n");
		break;
	case SIGUSR1:
		printf("SIGUSR signal was used\n");
		break;
	}
}

int main() {
	signal(SIGKILL, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGUSR1, signal_handler);
	while(1)
		sleep(1);
}