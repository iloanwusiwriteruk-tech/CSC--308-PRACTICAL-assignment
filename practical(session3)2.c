void *process(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&semaphore);

    printf("Thread %d entered the critical section.\n", id);

    sleep(2);

    printf("Thread %d leaving the critical section.\n", id);

    sem_post(&semaphore);

    return NULL;
}