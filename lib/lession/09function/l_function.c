//
// Created by root on 16-12-28.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int calledP(char ***data){
    int i;
    *data = (char **)calloc(3,sizeof(char*));
    for(i=0;i<3;i++){
        (*data)[i] = malloc(10* sizeof(char));
        strcpy((*data)[i],"aa");
    }
    return 3;
}
void callerP(){
    char **arr = NULL;
    int i,num = calledP(&arr);
    for(i=0;i<num;i++){
        puts(arr[i]);
    }
}

