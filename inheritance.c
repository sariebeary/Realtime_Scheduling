#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

static pthread_t t1; //thread variable
static pthread_mutex_t m; // mutex variable
static pthread_mutexattr_t ma; // mutex attribute variable
static sched_param sp; // structure variable for buffering thread priority

void function()
{
 //do some work here.
}

void funtion1()
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
//create thread 1, thread 2 and thread 3
//set different priority for each thread
//set handler for thread 1, thread 2 and thread 3 respectively. For instance, function 1 for thread 1, function 2 for thread 2 and function 3 for thread 3
 return 0;
}

