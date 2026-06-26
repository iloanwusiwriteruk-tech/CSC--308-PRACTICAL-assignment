sem_t mutex;
sem_t empty;
sem_t full;

sem_init(&mutex, 0, 1);
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&full, 0, 0);