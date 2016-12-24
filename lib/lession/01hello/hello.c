//
// Created by root on 16-12-22.
//

#include <stdio.h>


/**
 * 打印hello world
 */
void printHello() {
    printf("hello world!");
    printf("No???/n");
    printf("%s,%s,%s",__DATE__,__TIME__,__FILE__);
    printf("%s",__FILE__);
}

/**
 * 打印所有关键字
 */
void printKeywords() {
    int i;
    char
            keywords[][32] = {
            "auto",
            "double",
            "int",
            "long",
            "break",
            "else",
            "long",
            "switch",
            "case",
            "enum",
            "register",
            "typedef",
            "char",
            "extern",
            "return",
            "union",
            "const",
            "float",
            "short",
            "unsigned",
            "continue",
            "for",
            "signed",
            "void",
            "default",
            "goto",
            "sizeof",
            "volatile",
            "do",
            "if",
            "static",
            "while"
    };
    for(i =0;i< 32;i++){
        printf("%s\n",keywords[i]);
    }
}

