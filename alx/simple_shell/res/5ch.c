#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    for(int i=0; i<5; i++) // loop will run 5 times
    {
        pid = fork();

        if(pid == 0) // this is the child process
        {
            printf("[Child] pid %d from [parent] pid %d\n",getpid(),getppid());
            break;
        }
        else if(pid > 0) // this is the parent process
        {
            wait(NULL); // parent waits for the child to finish
        }
        else // fork failed
        {
            printf("fork() failed!\n");
            return 1;
        }
    }
    return 0;
}

