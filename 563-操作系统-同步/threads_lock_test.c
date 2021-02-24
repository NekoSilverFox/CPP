#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t lock;
int sum = 0;

#define msleep(ms)  usleep((ms) * 1000)

void * add1(void * cnt)
{     
	int i = 0;
	char * name = (char*)cnt;
	while(1)
	{
		pthread_mutex_lock(&lock);
		i++;
		printf("%s i=%d sum=%d\n",name,i,sum++);
		msleep(1000);		
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
	return 0;
}

void * add2(void *cnt)
{     
	int i = 0;
	char * name = (char*)cnt;
	while(1)
	{
		pthread_mutex_lock(&lock);
		i++;
		printf("%s i=%d sum=%d\n",name,i,sum++);
		msleep(1000);
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
	return 0;
}
int main(void)
{ 
	int i;
	pthread_t ptid1,ptid2;

	pthread_mutex_init(&lock,NULL);
	pthread_create(&ptid1,NULL,add1,"Job01");
	pthread_create(&ptid2,NULL,add2,"Job02");

	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	pthread_join(ptid1,NULL);
	pthread_join(ptid2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
