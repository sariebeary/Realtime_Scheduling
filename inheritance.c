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
    //do some work here
    pthread_exit(NULL);
}

void *thread2handler()
{
    //function 2 for thread 2.
    pthread_mutex_lock(&mutex);
    //do some work here and call function()
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *thread3handler()
{
    //function 3 for thread 3.
    //do some work here
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

    param.sched_priority = priority;

    //set different priority for each thread
    
    pthread_setschedparam(t1, policy, &param);
    //pthread_getschedparam(t1, &policy, &param);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    
    return 0;
}

