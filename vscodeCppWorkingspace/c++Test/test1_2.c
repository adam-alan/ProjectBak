#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int counter = 1;

void thread1(void *arg)
{
        int i,val;

        for(i = 1; i <= 5; i++)
        {
                val = ++counter;
                printf("1号进程：i= %d counter= %d\n", i, counter);
                sleep(3);
                counter = val;
        }
}

void thread2(void *arg)
{
        int i, val;

        for(i = 1; i <= 5; i++)
        {
                val = ++counter;
                sleep(1);
                printf("2号进程：i= %d counter= %d\n", i, counter);
                counter = val;
        }
}

int main(int argc, char *argv[])
{
        pthread_t id1, id2;

        pthread_create(&id1, NULL, (void *)thread1, NULL);
        pthread_create(&id2, NULL, (void *)thread2, NULL);

        pthread_join(id1, NULL);
        pthread_join(id2, NULL);

        printf("counter最终结果为：%d\n", counter);

        return 0;
}                   
