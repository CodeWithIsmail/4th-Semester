#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
int min;
int max;
int num_args;

void *sum_runner(void *param);
void *min_runner(void *param);
void *max_runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid_sum, tid_min, tid_max;
    pthread_attr_t attr;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <integer1> <integer2> ... <integerN>\n", argv[0]);
        return -1;
    }

    num_args = argc - 1;
    int *numbers = (int *)malloc(num_args * sizeof(int));
    if (numbers == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    for (int i = 0; i < num_args; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
        //   printf("%d ",numbers[i]);
    }

    pthread_attr_init(&attr);

    pthread_create(&tid_sum, &attr, sum_runner, numbers);
    pthread_create(&tid_min, &attr, min_runner, numbers);
    pthread_create(&tid_max, &attr, max_runner, numbers);

    pthread_join(tid_sum, NULL);
    pthread_join(tid_min, NULL);
    pthread_join(tid_max, NULL);

    printf("Sum = %d\n", sum);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    free(numbers);

    return 0;
}

void *sum_runner(void *param)
{
    int *numbers = (int *)param;
    sum = 0;
    for (int i = 0; i < num_args; i++)
    {
        sum += numbers[i];
    }
    pthread_exit(0);
}

void *min_runner(void *param)
{
    int *numbers = (int *)param;
    min = numbers[0];
    for (int i = 1; i < num_args; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    pthread_exit(0);
}

void *max_runner(void *param)
{
    int *numbers = (int *)param;
    max = numbers[0];
    for (int i = 1; i < num_args; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    pthread_exit(0);
}