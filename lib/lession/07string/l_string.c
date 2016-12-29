//
// Created by root on 12/25/16.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mutiStringArray(){
    char **pString;
    int nString = 3,i;
    char* src[3] = {"a","bb","ccc"};
    pString = (char**)malloc(nString*sizeof(char*));
    for(i=0;i<nString;i++){
        pString[i] = malloc(i*sizeof(char));
        strcpy(pString[i],src[i]);
    }
    for(i=0;i<nString;i++){
       puts(pString[i]);
    }
    return;
}