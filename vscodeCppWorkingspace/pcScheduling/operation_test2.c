#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX_CHLID_NUMBER 10         //允许建立的最大子进程数
#define SLEEP_INTERVAL  2           //子进程睡眠时间
int proc_number = 0;

void do_something();

int main(int argc,char *argv[]){
    int child_proc_number = MAX_CHLID_NUMBER;
    int i,ch;
    pid_t child_pid;
    pid_t pid[10] = {0};

    if (argc > 1){
        child_proc_number = atoi(argv[1]);
        printf("%d\n",child_proc_number);
        child_proc_number = (child_proc_number > 10) ? 10 :child_proc_number;
    }

    for (i = 0;i < child_proc_number;i++){
     /* 填写代码，建立child_proc_number个子进程要执行
        * proc_number = i;
        * do_something();
        * 父进程把子进程的id保存到pid[i] */
        child_pid = fork();
        switch (child_pid)
        {
            case -1:
                printf("failed to create a child process\n");
                break;
            case 0:
                proc_number = i;

                do_something();       
                printf("i is %d\n",i);
            default:    
                //pid[i] = getpid();
                pid[i] = child_pid;
                break;
        }
    }
    //让用户选择杀死进程，数字表示杀死该进程，q退出
    while((ch = getchar()) != 'q'){
        if (isdigit(ch)){
            /*填写代码，向pid[ch-'0']反信号SIGTERM，杀死该子进程*/
            kill(pid[ch-'0'],SIGTERM);
            pid[ch-'0']=0;//一定要清零
        

        }
    }
    //在这里填写代码，杀死本组的所有进程
    kill(0,SIGTERM);    
    return 0;
}

void do_something(){
    while(1)
    {
        printf("This is process No.%d and its pid is %d\n",proc_number,getpid());
        printf("my parent is %d\n",getppid());
        sleep(SLEEP_INTERVAL);
    }
}