#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 1;
int main(){
    /*
    int i = 0;
    for (i = 0;i < 2;i++){
        fflush(stdout);
        fork();
        printf("-");
        
    }
    wait(NULL);
    wait(NULL);
    */
    int i,val;

    for(i = 1; i <= 5; i++)
    {
            val = ++counter;
            printf("1号进程：i= %d counter= %d\n", i, counter);
            sleep(3);
            counter = val;
    }
    return 0;
}