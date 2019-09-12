#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
   for (int i = 0; i < 5; i++) {
      fork();
      sleep(5);
   }
}

/*
After the first iteration we can see 2 processes: parent and child. 
After the second iteration it will be 4 processes, because each previous process has new child.
After the third iteration it will be 8 processes.
And so on, on each next iteration the number of processes will be doubled.
*/
