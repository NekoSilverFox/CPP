// 同步
#include <stdio.h>
#include <pthread.h>
#define MAXTHREADS 2

void* produce(void* arg);
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//int num=0;

int main(void)
{
    int i, count[MAXTHREADS];
    pthread_t tid_produce[MAXTHREADS];
    for (i = 0; i < MAXTHREADS; i++)
    {
        count[i] = i;
        if (!pthread_create(&tid_produce[i], NULL, produce, &count[i]))
        {
            printf("tid %d\n", tid_produce[i]);
        }
        else { printf("Can not create pthread!\n"); exit(0); }
    }

    for (i = 0; i < MAXTHREADS; i++)
    {
        pthread_join(tid_produce[i], NULL);
        printf("count[%d]=%d\n", i, count[i]);
    }
    return(0);
}

void* produce(void* arg)
{
    pthread_t tid;

    tid = pthread_self();
    pthread_mutex_lock(&mutex);
    printf("Hello I am Thread %d\n", *(int*)arg);
    sleep(5);
    printf("Hello I am Thread %d\n", *(int*)arg);
    pthread_mutex_unlock(&mutex);
    printf("Inside tid=%d\n", tid);
    return(0);
}
