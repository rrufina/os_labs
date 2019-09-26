#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main() {
	pid_t pid;

	pid = fork();

	if (pid < 0)
		exit(1);
	else {
		if (pid > 0) {
			sleep(10);
			kill(pid, SIGTERM);
		}

		else if (pid == 0) {
			while(1) {
				printf("I'm alive\n");
				sleep(1);
			}
		}
	}
}
