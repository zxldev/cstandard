//
// Created by root on 12/24/16.
//
#include <stdio.h>

extcFileClose(){
    FILE *fp;

    fp = fopen("/alidata/workspace/c/standard/bin/output.txt", "w");

    fprintf(fp, "%s", "This is souii.com");
    fclose(fp);

    return(0);
}