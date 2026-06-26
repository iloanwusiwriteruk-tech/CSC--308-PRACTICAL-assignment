#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

void* increment_without_mutex(void* arg) {
    for(int i = 0; i < 100000; i++) {
        counter++;
    }
    return NULL;
}

void* increment_with_mutex(void* arg) {
    for(int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    counter = 0;
    pthread_create(&t1, NULL, increment_without_mutex, NULL);
    pthread_create(&t2, NULL, increment_without_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Without Mutex: %d\n", counter);

    counter = 0;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, increment_with_mutex, NULL);
    pthread_create(&t2, NULL, increment_with_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("With Mutex: %d\n", counter);

    pthread_mutex_destroy(&mutex);

    return 0;
}