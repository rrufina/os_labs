#include<stdio.h>
#include<string.h>

int main() {
	printf("Enter the string: \n");
	char str[100];
	gets(str);
	for (int i = strlen(str)-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}