#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *newrealloc(void *ptr, size_t newsize) {
	void *newptr;
	if (ptr == NULL) {
		newptr = malloc(newsize);
	} 
	else if (newsize == 0) {
		free(ptr);
	}
	else {
		newptr = malloc(newsize);
		newptr = memcpy(newptr, ptr, newsize);
		free(ptr);
	}
	return newptr;
}

int main() {
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		*(a1+i)=100;
		printf("%d ",*(a1+i));
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2 using new function
	a1 = newrealloc(a1, n2*sizeof(int));

	if (n2 > n1) {
		for (int i = n1; i<n2; i++)
			*(a1+i) = 0;
	}
	
	for(i=0; i<n2;i++){
		printf("%d ", *(a1+i));
	}
	printf("\n");
	
	return 0;

}