#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter array size:\n");
	scanf("%d", &n);
	int *arr = malloc(n*sizeof(int));
	for (int i = 0; i<n; i++) {
		*(arr+i) = i; 
	}
	printf("Array of size %d contains: ", n);
	for (int i = 0; i<n; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n");
	free(arr);
	return 0;
}