#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = 1234;

    int shmid;

    char *shared_memory;

    /* Step 1: Create shared memory */
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    if(shmid == -1)
    {
        printf("Failed to create shared memory.\n");
        return 1;
    }

    /* Step 2: Attach shared memory */
    shared_memory = (char *)shmat(shmid, NULL, 0);

    if(shared_memory == (char *)-1)
    {
        printf("Failed to attach shared memory.\n");
        return 1;
    }

    /* Step 3: Write data */
    strcpy(shared_memory, "Hello from Shared Memory!");

    printf("Data Written Successfully.\n");
    printf("Written Data: %s\n", shared_memory);

    /* Step 4: Read data */
    printf("Reading Data from Shared Memory...\n");
    printf("Data Read: %s\n", shared_memory);

    /* Step 5: Detach shared memory */
    if(shmdt(shared_memory) == -1)
    {
        printf("Failed to detach shared memory.\n");
        return 1;
    }

    /* Remove shared memory */
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared Memory Detached and Deleted Successfully.\n");

    return 0;
}