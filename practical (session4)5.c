shmdt(shared_memory);

shmctl(shmid, IPC_RMID, NULL);