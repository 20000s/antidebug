#include<sys/time.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>


static int _getrusage();
static int _clock();
static int _time();
static int _gettimeofday();
static int _clock_gettime();



int main(){
    _getrusage();
    _clock();
    _time();
    _gettimeofday();
    _clock_gettime();
    return 0;
}

int _getrusage()
{
    struct rusage t1;
    getrusage(RUSAGE_SELF,&t1);

    long used = t1.ru_utime.tv_sec + t1.ru_stime.tv_sec;
    if(used >2){
        puts("debugged");
    }
    return 0 ;
}
int _clock()
{
    clock_t t1,t2;

    t1 = clock();
    t2 = clock();

    double used = (double)(t2-t1) / CLOCKS_PER_SEC;
    if(used > 2){
        puts("debugged");
    }
    return 0;
}

int _time()
{
    time_t t1,t2;
    time(&t1);
    time(&t2);
    if(t2 - t1 >2){
        puts("debugged");
    }
    return 0;
}
int _gettimeofday ()
{
struct timeval t1, t2;
struct timezone t;
gettimeofday (&t1, &t);
/* breakpoint */
gettimeofday (&t2, &t);
if (t2.tv_sec - t1.tv_sec >2 ) {
puts ("debugged");
}
return 0;
}
int _clock_gettime ()
{
struct timespec t1, t2;
clock_gettime (CLOCK_REALTIME, &t1);
/* breakpoint */
clock_gettime (CLOCK_REALTIME, &t2);
if (t2.tv_sec - t1.tv_sec > 2) {
puts ("debugged");
}
return 0;
}