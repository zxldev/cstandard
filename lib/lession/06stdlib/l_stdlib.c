//
// Created by root on 16-12-26.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include <pcre.h>
#include <preg.h>

extern char **environ;

void afterExit(){
    printf("我是退出函数");
}

void printStdlib(){

    //注册退出函数
    atexit(afterExit );

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

    //分配内存空间-calloc
    int *pCalloc,i;
    pCalloc = calloc(10,sizeof(int));
    for (i = 0; i < 10; ++i) {
        pCalloc[i] = i;
    }

    //回收内存空间
    free(pCalloc);

    char *str;
    //分配空间malloc
    str = (char *) malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    //重新分配空间
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    //回收内存空间
    free(str);

    //停止程序
    if(0){
        abort();
    }

    //退出程序
    if(0){
        exit(EXIT_SUCCESS);
    }

    //获取环境变量
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("HOME"));
    printf("HOSTNAME : %s\n", getenv("HOSTNAME"));

    //打印所有env值
    char **pEnv = environ;

    while (*pEnv){
        char  pattern[50];
        strcpy(pattern,"([^=]+)=.*");
        char ** matches;
        if(perg_match(pattern,*pEnv++,&matches)>=0){
            puts(matches[1]);
            free(matches);
        }
    }

    //执行系统命令
    char command[50];
    strcpy( command, "ls -l" );
    system(command);



}



