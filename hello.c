#include <stdio.h>
#include <pthread.h>

void *display(void *thread)
{
	long tid = (long)thread;
	printf("Hello World! I am thead %ld\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[3];
	long i;
	int th;
	for(i=0; i<3; i++){
		th = pthread_create(&threads[i], NULL, display, (void *)i);
	}
	if (th > 0) {
		printf("unable to create theread, error_code=%d\n", th);
	}
	pthread_exit(NULL);
}
