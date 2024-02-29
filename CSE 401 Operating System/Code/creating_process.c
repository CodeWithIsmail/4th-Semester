#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid;
    pid=fork();

    if(pid==0)
    {
        printf("I am the child process: pid= %d\n",getpid());
    }
    else if(pid==-1)
    {
        perror("fork");
        exit(1);
    }
    else
    {
        printf("I am the parent process: pid=  %d , child pid=  %d\n",getpid(),pid);
    }
    exit(0);
}
