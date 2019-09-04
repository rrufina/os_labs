#include <stdio.h>

void quick_sort(int* arr, int first, int last) {
	int i = first;
	int j = last;
	int x = *(arr+(first+last)/2);
	do {
		while (*(arr+i) < x)
			i++;
		while (*(arr+j) > x)
			j--;
		if (i<=j) {
			if (*(arr+i) > *(arr+j)) {
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		quick_sort(arr, i, last);
	if (first < j) 
		quick_sort(arr, first, j);
}

int main() {
	int a[10] = {12, 56, 123, 456, 2, 466, 34, 100, 99, 1};
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}