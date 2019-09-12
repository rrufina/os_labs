#include <sys/types.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>
int main()
{
   int n = 10;
   int pid;
   pid = fork();
   if (pid == 0) {
   	printf("Hello from parent [%d - %d]\n", pid, n);
   }
   else if (pid > 0) {
   	printf("Hello from child [%d - %d]\n", pid, n);
   }
   else if (pid < 0) {
   	printf("Error");
   }
}

/*
Parent always has the same id, 
but id for childs are different, 
because every time we create a new process.
*/
