#include<stdio.h>
#include<limits.h>
#include<float.h>

int main() {
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("Maximum value for integer is %d, size of it is %lu\n", a, sizeof(a));
	printf("Maximum value for float is %f, size of it is %lu\n", b, sizeof(b));
	printf("Maximum value for double is %f, size of it is %lu\n", c, sizeof(c));
}
