#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREAD 3
unsigned long long main_counter,counter[MAX_THREAD];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * thread_worker(void * p);
int main(){
    int i,rtn,ch;
    int record[MAX_THREAD];
    pthread_t pthread_id[MAX_THREAD]={0};
    for (i = 0;i < MAX_THREAD;i++){
        record[i] = i;
        rtn = pthread_create(&pthread_id[i],NULL,(void *)thread_worker,(void *)(&record[i]));
    }

    do {
        pthread_mutex_lock(&mutex);
        unsigned long long sum = 0;
        for (i = 0;i < MAX_THREAD;i++){
            sum += counter[i];
            printf ("%llu ",counter[i]);
        }
        printf("%llu/%llu",main_counter,sum);
        pthread_mutex_unlock(&mutex);
    } while ((ch = getchar())!= 'q');

    pthread_mutex_destroy(&mutex);
    return 0;
}

void * thread_worker(void * p){
    int thread_num;
    thread_num = *((int *)p);
    for (;;){     
        pthread_mutex_lock(&mutex);
        //printf(" i = %d\n ",thread_num);
        counter[thread_num]++; /* 本线程的counter加一 */ 
        main_counter++; /* 主counter 加一 */
        pthread_mutex_unlock(&mutex);
    }
    
}
