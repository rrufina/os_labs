#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g = 0;
pthread_mutex_t mutex;

void *thread_func(void *vararg) {
	pthread_mutex_lock(&mutex); 
		++g;
		printf("Hello! I am a thread number %d\n", g);
	pthread_mutex_unlock(&mutex);
}

int main() {
	int n = 10;
	pthread_t id;
	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < n; i++) {
		pthread_create(&id, NULL, thread_func, (void *)&id);
	}
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
}