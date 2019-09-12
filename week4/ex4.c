#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define STR_LEN INT_MAX

int main() {
	char * s = (char *)malloc(sizeof(char)*STR_LEN); 
	int state = 1;
	while (state != 0) {
		fgets(s, STR_LEN, stdin);
		s[strlen(s)-1] = '\0';

		if (strcmp(s, "exit") == 0) {    // the command 'exit' is used to finish working
			state = 0;	
		}
		else {
			*(s + strlen(s)) = ' ';
			*(s + strlen(s) + 1 ) = '&'; // we add " &" to make it possible to execute 
			*(s + strlen(s) + 2) = '\0'; // commands with parameters
			
			system(s);
			s[0] = '\0';
		}
	}
	return 0;
}