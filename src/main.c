#include <02assert/l_assert.h>
#include "01hello/hello.h"
#include "04math/l_math.h"
#include <06stdlib/l_stdlib.h>
#include "08time/l_time.h"

int main(int argc, char *argv[]){
    printHello();
    printKeywords();
    printMath();
    printTime();
    printClock();
    printStdlib();
    open_record("ss");
    return 0;
}