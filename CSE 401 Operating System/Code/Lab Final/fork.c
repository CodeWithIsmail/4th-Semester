#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n;
    scanf("%d", &n);
    int pid = fork();

    if(pid<0)
        perror("Fork faild");

    if (pid > 0)
    {
        int esum=0;
        for (int i = 2; i <= n; i += 2)
            esum += i;
        printf("Parent process (PID %d): Sum of even numbers up to %d is %d\n", getpid(), n, esum);
    }
    else
    {
        int osum=0;
        for (int i = 1; i <= n; i += 2)
            osum += i;
        printf("Child process (PID %d): Sum of odd numbers up to %d is %d\n", getpid(), n, osum);
    }
}