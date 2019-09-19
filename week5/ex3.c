#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX 100000 

int counter = 0;
int cond_pro = 0;
int cond_con = 1;

//function for producer that increases counter by 1
void *producer(void *args) {
	while(1) {
		if (cond_pro == 0) {
			while (counter < MAX) {
				++counter;
			}
			cond_pro = 1;
			cond_con = 0;
		}
		while (cond_pro == 1) {}
	}
}

//function for consumer that reduces counter by 1
void *consumer(void *args) {
	while (1) {
		if (cond_con == 0) {
			while (counter != 0) {
				--counter;
			}
			cond_pro = 0;
			cond_con = 1;
		}
		while (cond_con == 1) {}
	}	
}

int main() {
	pthread_t id[2];
	pthread_create(&id[0], NULL, producer, NULL);
	pthread_create(&id[1], NULL, consumer, NULL);
	while (1) {
		printf("Counter is %d\n", counter);
		sleep(1);
	}
	pthread_exit(NULL);
}

/*
'cond_pro' and 'cond_con' take the value 0, if they are ready for operation,
and take the value 1, if they are waiting.
*/