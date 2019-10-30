#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main() {
	struct stat buf_src, buf_dst;
	//char *src, *dst;

	//for source file
	int fd_src = open("ex1.txt", O_RDWR);

	if (fd_src == -1) {
		exit(1);
	}

	fstat(fd_src, &buf_src);

	void *src = mmap(NULL, buf_src.st_size, PROT_READ, MAP_SHARED, fd_src, 0);
	if (src == MAP_FAILED) {
		exit(1);
	}

	//for destination file
	int fd_dst = open("ex1.memcpy.txt", O_CREAT| O_RDWR | O_TRUNC);
	if (fd_dst == -1) {
		exit(1);
	}

	fstat(fd_dst, &buf_dst);

	void * dst = mmap(NULL, buf_src.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_dst, 0);
	if (dst == MAP_FAILED) {
		exit(1);
	} 

	ftruncate(fd_dst, buf_src.st_size);

	memcpy(dst, src, buf_src.st_size);

	return 0;
}