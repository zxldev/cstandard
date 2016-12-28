#include <02assert/l_assert.h>
#include "01hello/hello.h"
#include "04math/l_math.h"
#include <06stdlib/l_stdlib.h>
#include "08time/l_time.h"
#include <preg.h>
#include <memory.h>
#include <stdio.h>
#include <09function/l_function.h>

int main(int argc, char *argv[]){
    printHello();
    printKeywords();
    printMath();
    printTime();
    printClock();
    printStdlib();
    open_record("ss");

    //
    char pattern[50],subject[50];
    int i,rc;
    char** matches;
    strcpy(pattern,"<titl(e>)(.*)</(tit)le>");
    strcpy(subject,"111 <title>Hello World</title> 222");
    rc = perg_match(pattern,subject,&matches);
    for(i=0;i<rc;i++){
        puts(matches[i]);
    }


    callerP();
    return 0;
}