#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int fd[2];
	char string_in[] = "Operating Systems";
	char string_out[100];

	if (pipe(fd) < 0)
		exit(1);

	write(fd[1], string_in, strlen(string_in));
	read(fd[0], string_out, strlen(string_in));
	printf("string_out = %s\n", string_out);
}