char *shared_memory;

shared_memory = (char *)shmat(shmid, NULL, 0);