#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ALL_PAGES 1000


//return -1 if page is not in array, or index if page is in array
int is_contained(int page, int* array, int size) {
	int index = -1;
	for (int i = 0; i<size; i++) {
		if (array[i] == page)
			index = i;
	}
	return index;
}

//find index of mimum value in the array
int find_min(unsigned char* array, int size) {
	int i_min = 0;
	for (int i = 1; i < size; i++) {
		if (array[i] < array[i_min])
			i_min = i;
	}
	return i_min;
}

//return index of the first empty cell in array, or -1 otherwise
int has_empty(int* array, int size) {
	int n = -1;
	for (int i = 0; i < size; i++) {
		if (array[i] == 0)
			return i;
	}
	return n;
}

int main() {

	//Read number for page frame
	printf("Enter page frame: \n");
	int pf;
	scanf("%d", &pf);

	//table - for counters (32 bits)
	unsigned char* table = (unsigned char*)calloc(pf, sizeof(unsigned char));

	//pages - for numbers of pages that are in memory
	int* pages = (int*)calloc(pf, sizeof(int));

	printf("Enter name of the file which contains the page references: \n");
	char file_name[30];
	scanf("%s", file_name);

	FILE* fp;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	int hit = 0;
	int miss = 0;

	if (pf > ALL_PAGES)
		pf = ALL_PAGES;

	for (int i = 0; i < ALL_PAGES; i++) {
		int n, index;
		fscanf(fp, "%d", &n);
		for (int j = 0; j < pf; j++) {
			table[j] = table[j]/2;
		}
		if (is_contained(n, pages, pf) == -1) {
			miss++; 
			if (has_empty(pages, pf) != -1) {
				pages[has_empty(pages, pf)] = n;
				table[is_contained(n, pages, pf)] = 128;
			}
			else {
				pages[find_min(table, pf)] = n;
				table[find_min(table, pf)] = 128;
			}
			
		}
		else {
			hit++;
			table[is_contained(n, pages, pf)] = table[is_contained(n, pages, pf)] + 128;
		}
		
	}

	printf("Hit = %d, Miss = %d. Hit/Miss ratio is %f.\n", hit, miss, (float)hit/(float)miss);

}