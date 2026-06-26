pthread_t threads[6];
int ids[6];

for(int i = 0; i < 6; i++)
{
    ids[i] = i + 1;
    pthread_create(&threads[i], NULL, process, &ids[i]);
}