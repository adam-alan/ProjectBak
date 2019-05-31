#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int i = 0;
    pid_t pid;
    for (i = 0;i < 2;i++){
        pid = fork();
        switch (pid)
        {
            case 0:
                printf("I'm a child progress,my pid is %d, i = %d\n, nice = %d\n",getpid(),i,getpriority(PRIO_PGRP,pid));
                printf("my parent's pid is %d\n",getppid());
                printf("-\n");
            case -1:
                /* code */
                printf("failed to create a child progress\n");
                break;
        
            default:
                printf("I'm a parent progress,my pid is %d,i = %d\n,nice = %d\n",getpid(),i,getpriority(PRIO_PGRP,pid));
                printf("-\n");
                break;
        }
        
    }
    wait(NULL);
    wait(NULL);
    return 0;
}