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