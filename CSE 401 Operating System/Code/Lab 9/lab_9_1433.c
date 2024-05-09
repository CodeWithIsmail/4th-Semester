#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
sem_t mutex, rw_mutex;
int read_count = 0;
int sharedVariable = 0;

void *reader(void *param)
{
    int *threadID = (int *)param;
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);

    printf("Reader %d reads: %d\n", *threadID, sharedVariable);

    usleep(300000);
    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
    {
        sem_post(&rw_mutex);
    }
    sem_post(&mutex);
    printf("Reader %d is leaving\n", *threadID);
    return NULL;
}

void *writer(void *param)
{
    int *threadID = (int *)param;
    sem_wait(&rw_mutex);
    printf("Writer %d has entered\n", *threadID);
    sharedVariable++;
    printf("Writer %d wrote: %d\n", *threadID, sharedVariable);
    sem_post(&rw_mutex);
    printf("Writer %d is leaving\n", *threadID);

    usleep(300000);
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    pthread_t readerID[n], writerID[n];
    pthread_t writerThreads[n], readerThreads[n];

    for (int i = 0; i < n; i++)
    {
        readerID[i] = i + 1;
        writerID[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        pthread_create(&writerThreads[i], NULL, writer, &writerID[i]);
        pthread_create(&readerThreads[i], NULL, reader, &readerID[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(readerThreads[i], NULL);
        pthread_join(writerThreads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}