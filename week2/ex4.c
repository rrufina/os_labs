#include<stdio.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	printf("Enter two integers:\n");
	int a, b;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
}