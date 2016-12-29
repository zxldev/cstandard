//
// Created by root on 16-12-29.
//

#ifndef CSTANDRAD_CONFIG_H
#define CSTANDRAD_CONFIG_H


//日志等级
#include <jmorecfg.h>

#define LL_DEBUG 0
#define LL_VERBOSE 1
#define LL_NOTICE 2
#define LL_WARNING 3

//单条日志最大长度
#define LOG_MAX_LEN    1024 /* Default maximum length of syslog messages */
//配置文件最大长度
#define CONFIG_MAX_LINE    1024

struct RedisConfig{
    char *serverIP; //redis服务IP
    int port;//redis端口
    char *password;//redis密码
};

struct Config{
    char * logfile;//日志文件位置
    int verbosity;//loglevel日志等级
    boolean syslog_enabled;//是否记录系统日志
    struct RedisConfig redisconfig;
} ;
void loadServerConfigFromString(char *config);
void loadServerConfig(char *filename, char *options);
void serverLogRaw(int level, const char *msg);
void serverLog(int level, const char *fmt, ...);
#endif //CSTANDRAD_CONFIG_H
