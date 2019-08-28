#include<stdio.h>

void rsu_triangle(int n) {
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

void right_triangle(int n) {
	for (int h = 0; h < n; h++) {
		for (int w = 0; w < n; w++) {
			if (w <= h) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void isosceles_triangle(int n) {
	int t;
	for (int h = 0; h < n; h++) {
		if (h >= (n+1)/2 ) {
			t = n-1-h;
		}
		else {
			t = h;
		}
		for (int w = 0; w < (n+1)/2; w++) {
			if (w <= t) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(int argc, char **argv) {
	int n;
	sscanf(argv[1], "%d", &n);
	rsu_triangle(n);
	printf("\n");
	right_triangle(n);
	printf("\n");
	isosceles_triangle(n);
}