#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

void *hello_from_thread(void *vargp) {
    printf("Hello from thread #%d\n", *((int*) vargp));
    pthread_exit(NULL);
}


int main() {
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; ++i) {
	printf("Creating thread #%d\n", i);

	pthread_t thread_id;
        pthread_create(&thread_id, NULL, hello_from_thread, (void*) &i);
	pthread_join(thread_id, NULL); 
    }
}
