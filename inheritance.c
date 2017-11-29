//#define _GNU_SOURCE
#define __USE_UNIX98	/* Needed for PTHREAD_PRIO_INHERIT */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

static pthread_t t1, t2, t3;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex variable
static pthread_mutexattr_t mta; // mutex attribute variable
//static sched_param sp; // structure variable for buffering thread priority

void function()
{
 //do some work here.
    pthread_mutex_lock(&lock);
}

void function1()
{
 //function 1 for thread 1.
 //do some work here
}

void function2()
{
//function 2 for thread 2.
//do some work here and call function()
}

void function3()
{
//function 3 for thread 3.
//do some work here
}

int main(int argc, char *argv[])
{
//create mutex and initialize it.
    pthread_mutexattr_init (&mta);
    pthread_mutexattr_setprotocol(&mta, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&mutex, &mta);
//create thread 1, thread 2 and thread 3
    pthread_create(&t1, NULL, (void *) &function1, NULL);
    pthread_create(&t1, NULL, (void *) &function2, NULL);
    pthread_create(&t1, NULL, (void *) &function3, NULL);

//set different priority for each thread
//set handler for thread 1, thread 2 and thread 3 respectively. For instance, function 1 for thread 1, function 2 for thread 2 and function 3 for thread 3
 return 0;
}

