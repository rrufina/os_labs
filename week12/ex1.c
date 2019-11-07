#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int rand;
	if ((rand = open("/dev/random", O_RDONLY)) < 0) {
		printf("ne nashel");
		exit(1);
	}
	else {
		char string[20];
		ssize_t result = read(rand, string, sizeof(string));
		printf("%s", string);
	}
	close(rand);
}
