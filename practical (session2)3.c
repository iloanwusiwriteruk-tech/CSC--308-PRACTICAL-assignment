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