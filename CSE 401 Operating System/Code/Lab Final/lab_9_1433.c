#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 1

sem_t mutex, db;
int read_count = 0;

int shared_data;

void *reader(void *arg);
void *writer(void *arg);

int main()
{

    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);

    for (int i = 0; i < NUM_READERS; i++)
    {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++)
    {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++)
    {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&db);

    return 0;
}

void *reader(void *arg)
{
    int id = *(int *)arg;
    while (1)
    {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1)
        {
            sem_wait(&db);
        }
        sem_post(&mutex);
        printf("Reader %d reads the shared data: %d, readers count: %d\n", id, shared_data, read_count);
        sem_wait(&mutex);
        read_count--;
        if (read_count == 0)
        {
            sem_post(&db);
        }
        sem_post(&mutex);
        sleep(rand() % 5);
    }
    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;
    while (1)
    {
        sem_wait(&db);
        shared_data = rand() % 100;
        printf("Writer %d writes the value %d in the shared data\n", id, shared_data);
        sem_post(&db);
        sleep(rand() % 5);
    }
    return NULL;
}