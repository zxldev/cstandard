//
// Created by root on 12/23/16.
//
#include <time.h>
#include <stdio.h>
#include <math.h>
int printTime(){
    struct tm t;
    t.tm_year = 2016-1900;
    t.tm_mon = 12-1;
    t.tm_mday = 13-1;
    t.tm_hour = 23-1;
    t.tm_min = 23-1;
    t.tm_sec = 24 -1;
    puts(asctime(&t));

    time_t curtime;

    time(&curtime);

    printf("Current time = %s", ctime(&curtime));

    return(0);
}

void printClock(){
    clock_t start_t, end_t, total_t;
    int i,j;

    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);

    printf("Going to scan a big loop, start_t = %ld\n", start_t);
    for(i=0; i< 10000000; i++)
    {
    }
    end_t = clock();
    printf("End of the big loop, end_t = %ld\n", end_t);

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );
    printf("Exiting of the program...\n");

}