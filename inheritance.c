//#define _GNU_SOURCE
//#define __USE_UNIX98	/* Needed for PTHREAD_PRIO_INHERIT */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

static pthread_t t1, t2, t3; //declare threads
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex variable
static pthread_mutexattr_t mta; // mutex attribute variable
struct sched_param param; //declare structure variable for buffering thread priority
int policy = SCHED_RR;
int priority = 10;

void function()
{
    //do some work here.
    
}

void *thread1handler()
{
    //function 1 for thread 1.
    printf("Thread 1 created.\n");
    pthread_mutex_lock(&mutex);
    printf("Locked thread 1\n");
    //do some work here
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("1\n");
    }
    pthread_mutex_unlock(&mutex);
    printf("Released thread 1\n");

    printf("Thread 1 out\n");
    
    pthread_exit(NULL);
}

void *thread2handler()
{
    //function 2 for thread 2.
    printf("Thread 2 created.\n");
    //do some work here and call function()
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("2\n");
    }
    printf("Thread 2 out\n");

    pthread_exit(NULL);
}

void *thread3handler()
{
    //function 3 for thread 3.
    printf("Thread 3 created.\n");
    pthread_mutex_lock(&mutex);
    printf("Locking thread 3.\n");
    //do some work here
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("3\n");
    }
    pthread_mutex_unlock(&mutex);
    printf("Released thread 3.\n");
    printf("Thread 3 out\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    //create mutex and initialize it.
    pthread_mutexattr_init(&mta);
    //set protocol for mutex attribute
    pthread_mutexattr_setprotocol(&mta, PTHREAD_PRIO_INHERIT);
    //initialize mutex with attribute
    pthread_mutex_init(&mutex, &mta);
    //create thread 1, thread 2 and thread 3
    //set handler for thread 1, thread 2 and thread 3 respectively
    pthread_create(&t1, NULL, (void *) thread1handler, NULL);
    pthread_create(&t2, NULL, (void *) thread2handler, NULL);
    pthread_create(&t3, NULL, (void *) thread3handler, NULL);
    
    int maxpriority = sched_get_priority_max(policy);
    int minpriority = sched_get_priority_min(policy);

    

    //set different priority for each thread
    param.sched_priority = minpriority;
    pthread_setschedparam(t1, policy, &param); // thread 1 lowest
    param.sched_priority = priority;
    pthread_setschedparam(t2, policy, &param);
    param.sched_priority = maxpriority;
    pthread_setschedparam(t3, policy, &param); // thread 3 high priority
    
    
    pthread_join(t1, NULL);
    printf("Thread 1 ended\n");
    pthread_join(t2, NULL);
    printf("Thread 2 ended\n");
    pthread_join(t3, NULL);
    printf("Thread 3 ended\n");

    return 0;
}

