#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

key_t key = 1234;

int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);