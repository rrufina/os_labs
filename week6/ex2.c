#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int fd[2];
	pid_t pid;

	char string_in[] = "Operating Systems";
	char string_out[100];

	if (pipe(fd) < 0)
		exit(1);

	pid = fork();

	if (pid < 0)
		exit(1);
	else {
		if (pid == 0) {
			close(fd[0]);
			write(fd[1], string_in, strlen(string_in));
		}

		else if (pid > 0) {
			close(fd[1]);
			read(fd[0], string_out, strlen(string_in));
			printf("string_out = %s\n", string_out);
		}
	}
}