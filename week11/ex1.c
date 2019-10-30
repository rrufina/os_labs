#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main() {
	struct stat buf;
	char* str;
	int fd = open("ex1.txt", O_RDWR);
	fstat (fd, &buf);
	if (fd == -1) {
		exit(1);
	}
	void* map = mmap(NULL, buf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED) {
		exit(1);
	} 
	str = "This is a nice day";
	size_t len_str = 18;
	ftruncate(fd, len_str);
	memcpy(map, str, len_str);
	close(fd);
	return 0;
}