#include <02assert/l_assert.h>
#include "01hello/hello.h"
#include "04math/l_math.h"
#include <06stdlib/l_stdlib.h>
#include "08time/l_time.h"
#include "config.h"
#include <preg.h>
#include <memory.h>
#include <stdio.h>
#include <09function/l_function.h>
#include <07string/l_string.h>
#include <hiredis/hiredis.h>
#include <stdlib.h>

extern struct Config server;
/**
 * redis
 */
void callRedis(){
    //redis调用
    redisContext *redis = redisConnect(
            server.redisconfig.serverIP,server.redisconfig.port
    );
    redisReply* reply= redisCommand(redis, "auth %s",
                                    server.redisconfig.password
    );
    if (reply==NULL||reply->type == REDIS_REPLY_ERROR) {
        /* Authentication failed */
        exit(1);
    }
    freeReplyObject(reply);

    reply = redisCommand(redis,"set hello world");
    if(reply==NULL||reply->type == REDIS_REPLY_ERROR){
        exit(1);
    }
    freeReplyObject(reply);

    reply = redisCommand(redis,"get hello");
    if(reply==NULL||reply->type == REDIS_REPLY_ERROR){
        exit(1);
    }

    printf("The value of 'hello' is %s.\n",reply->str);
    freeReplyObject(reply);
}

int main(int argc, char *argv[]){
    //TODO 修改这个绝对路径
    loadServerConfig("/alidata/workspace/c/cstandard/src/conf/c.conf","");
    server.redisconfig.password;
    printHello();
    printKeywords();
    printMath();
    printTime();
    printClock();
    printStdlib();
    open_record("ss");
    mutiStringArray();
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
    //SDS测试
    sds sdsstring = sdsnew("ssss");
    printf("sdsString:%s\n",sdsstring);

    callerP();
    callRedis();
    return 0;
}