#include<stdio.h>
#include<sys/time.h>
int main(int argc, const char *argv[]){
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    printf("tv_sec:%d\n",tv.tv_sec);
    printf("tv_usec:%d\n",tv.tv_usec);
    //printf("tv_usec of sec:%f\n",(int)(tv.tv_usec)/1000.0/1000.0);
    printf("tv_usec of sec:%d\n",(int)(tv.tv_usec)/10000);
    //printf("%f\n",1.0/3);
    //printf("tz_minuteswest:%d\n",tz.tz_minuteswest);
    //printf("tz_dsttime:%d\n",tz.tz_dsttime);
    return 0;
}