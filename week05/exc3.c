#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <signal.h>

#define MAX_SIZE 100

int count = 0;
int consumer_sleep = 0;
int producer_sleep = 0;

void *producer(void *vargp) {
    while (1) {
	if (count == MAX_SIZE) { 
            printf("Producer goes to sleep\n");
	    producer_sleep = 1;
	    while (producer_sleep);
	    printf("Producer woke up\n");
	}

        printf("Produced an item. Number of items now is: %d\n", ++count);
	
	if (count == 1 && consumer_sleep) {
	    printf("Producer wake consumer\n");
            consumer_sleep = 0;
        }
    }
}

void *consumer(void *vargp) {
    while (1) {
	if (count == 0) {
	    printf("Consumer goes to sleep\n");
	    consumer_sleep = 1;
	    while (consumer_sleep);
	    printf("Consumer woke up\n");
	}

        printf("Consumed an item. Number of items now is: %d\n", --count);

	if (count == MAX_SIZE - 1 && producer_sleep) {
	    printf("Consumer wake producer\n");
            producer_sleep = 0;
        }
    }
}


int main() {
    printf("Max size of buffer is %d\n", MAX_SIZE);

    pthread_t producer_id;
    pthread_t consumer_id;

    pthread_create(&producer_id, NULL, producer, NULL);

    pthread_create(&consumer_id, NULL, consumer, NULL);
    pthread_join(producer_id, NULL);
}
