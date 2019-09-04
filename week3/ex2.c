void bubble_sort (int* arr, int len) {
	int i, j;
	for (i= 0; i < len-1; i++) {
		for (j = 0; j < len; j++) {
			if (*(arr+j) < *(arr+j-1)) {
				int temp = *(arr+j);
				*(arr+j) = *(arr+j-1);
				*(arr+j-1) = temp;
			}
		}
	}
}

int main() {}
