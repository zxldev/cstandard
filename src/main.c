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
#include <zconf.h>
#include <util.h>
#include <fcntl.h>

#define CSTANDRAD_VERSION "1.0.0"

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

    printf("===========The value of 'hello' is %s.\n",reply->str);
    freeReplyObject(reply);
}

void version(void) {
    printf("Redis server v=%s bits=%d\n",
           CSTANDRAD_VERSION,
           sizeof(long) == 4 ? 32 : 64);
    exit(0);
}

void usage(void) {
    fprintf(stderr,"Usage: ./redis-server [/path/to/c.conf] [options]\n");
    fprintf(stderr,"       ./redis-server - (read config from stdin)\n");
    fprintf(stderr,"       ./redis-server -v or --version\n");
    fprintf(stderr,"       ./redis-server -h or --help\n");
    fprintf(stderr,"Examples:\n");
    fprintf(stderr,"       ./redis-server (run the server with default conf)\n");
    fprintf(stderr,"       ./redis-server /etc/redis/6379.conf\n");
    fprintf(stderr,"       ./redis-server --port 7777\n");
    fprintf(stderr,"       ./redis-server --port 7777 --slaveof 127.0.0.1 8888\n");
    fprintf(stderr,"       ./redis-server /etc/myredis.conf --loglevel verbose\n\n");
    exit(1);
}

void daemonize(void) {
    int fd;

    if (fork()!= 0) exit(0); /* parent exits */
    setsid(); /* create a new session */
    /* Every output goes to /dev/null. If Redis is daemonized but
     * the 'logfile' is set to 'stdout' in the configuration file
     * it will not log at all. */
    if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }
}

void procArgc(int argc, char *argv[]){
    int j;
    if (argc >= 2) {
        j = 1; /* First option to parse in argv[] */
        sds options = sdsempty();
        char *configfile = NULL;

        /* Handle special options --help and --version */
        if (strcmp(argv[1], "-v") == 0 ||
            strcmp(argv[1], "--version") == 0) version();
        if (strcmp(argv[1], "--help") == 0 ||
            strcmp(argv[1], "-h") == 0) usage();

        /* First argument is the config file name? */
        if (argv[j][0] != '-' || argv[j][1] != '-') {
            configfile = argv[j];
            server.configfile = getAbsolutePath(configfile);
            /* Replace the config file in server.exec_argv with
             * its absoulte path. */
            free(server.exec_argv[j]);
            server.exec_argv[j] = zstrdup(server.configfile);
            j++;
        }

        /* All the other options are parsed and conceptually appended to the
         * configuration file. For instance --port 6380 will generate the
         * string "port 6380\n" to be parsed after the actual file name
         * is parsed, if any. */
        while(j != argc) {
            if (argv[j][0] == '-' && argv[j][1] == '-') {
                /* Option name */
                if (!strcmp(argv[j], "--check-rdb")) {
                    /* Argument has no options, need to skip for parsing. */
                    j++;
                    continue;
                }
                if (sdslen(options)) options = sdscat(options,"\n");
                options = sdscat(options,argv[j]+2);
                options = sdscat(options," ");
            } else {
                /* Option argument */
                options = sdscatrepr(options,argv[j],strlen(argv[j]));
                options = sdscat(options," ");
            }
            j++;
        }

//   TODO     resetServerSaveParams();
        loadServerConfig(configfile,options);
        sdsfree(options);
    }

    serverLog(LL_WARNING, "oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo");

    serverLog(LL_WARNING,
              "CSTANDARD version=%s, bits=%d ,pid=%d, just started",
              CSTANDRAD_VERSION,
              (sizeof(long) == 8) ? 64 : 32,
              (int)getpid()
    );

    if (argc == 1) {
        serverLog(LL_WARNING, "Warning: no config file specified, using the default config. In order to specify a config file use %s /path/to/%s.conf", argv[0], "c");
    } else {
        serverLog(LL_WARNING, "Configuration loaded");
    }

}

int main(int argc, char *argv[]){

    initConfig(argc,argv);
    procArgc(argc,argv);
    daemonize();



    //TODO 修改这个绝对路径
    char buf[200];
    getcwd(buf,sizeof(buf));
    loadServerConfig(strcat(buf,"/conf/c.conf"),"");
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