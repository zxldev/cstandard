//
// Created by root on 16-12-26.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void printStdlib(){

    char floatString[20];
    strcpy(floatString,"123456789");

    char floatWithStrString[30];
    strcpy(floatWithStrString,"987654321 这是一个测试");
    char* strptr;

    //字符串转浮点数
    double doubleValue = atof(floatString);

    //字符串转整数
    int intValue = atoi(floatString);

    //字符串转长整型
    long longValue = atol(floatString);

    //字符串转浮点数,返回没有转换部分的指针
    double doubleWithStrValue = strtod(floatWithStrString,&strptr);
    printf("doubleWithStrValue:%f rest:%s\n",doubleWithStrValue,strptr);


    //字符串转长整型,返回没有转换部分的指针
    long int longWithStrValue = strtol(floatWithStrString,&strptr,0);
    printf("longWithStrValue:%ld rest:%s\n",longWithStrValue,strptr);

    //字符串转无符号长整型,返回没有转换部分的指针
    unsigned long unsigendWithStrValue = strtoul(floatWithStrString,&strptr,0);
    printf("unsigendWithStrValue:%ld rest:%s\n",unsigendWithStrValue,strptr);

}