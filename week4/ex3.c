#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define STR_LEN INT_MAX

int main() {
	char * s = (char *)malloc(sizeof(char)*STR_LEN); 
	int state = 1;
	while (state != 0) {
		scanf("%s", s);
		if (strcmp(s, "exit") == 0) {
			state = 0;
		}
		else {
			system(s);
		}
	}
	return 0;
}