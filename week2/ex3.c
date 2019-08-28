#include<stdio.h>

int main(int argc, char **argv) {
	int n;
	sscanf(argv[1], "%d", &n);
	for (int h = 0; h < n; h++) {
		for (int w = 0; w < 2*n-1; w++) {
			if ((w >= n-1-h) && (w <= n-1+h)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}	
}