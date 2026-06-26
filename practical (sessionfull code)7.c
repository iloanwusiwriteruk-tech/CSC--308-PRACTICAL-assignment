#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

int in = 0;
int out = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void *producer(void *arg)
{
    int item;

    for(item = 1; item <= 10; item++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;

        printf("Producer produced %d\n", item);

        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item;

    for(int i = 1; i <= 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];

        printf("Consumer consumed %d\n", item);

        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(2);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t producerThread;
    pthread_t consumerThread;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("\nProducer-Consumer Simulation Completed Successfully.\n");

    return 0;
}