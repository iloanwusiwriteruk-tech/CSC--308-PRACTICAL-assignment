pthread_t producerThread;
pthread_t consumerThread;

pthread_create(&producerThread, NULL, producer, NULL);
pthread_create(&consumerThread, NULL, consumer, NULL);

pthread_join(producerThread, NULL);
pthread_join(consumerThread, NULL);