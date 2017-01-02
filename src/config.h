//
// Created by root on 16-12-29.
//

#ifndef CSTANDRAD_CONFIG_H
#define CSTANDRAD_CONFIG_H


//日志等级
#include <jmorecfg.h>
#include <sys/types.h>

#define LL_DEBUG 0
#define LL_VERBOSE 1
#define LL_NOTICE 2
#define LL_WARNING 3
#define LL_RAW (1<<10) /* Modifier to log without timestamp */
#define CONFIG_DEFAULT_VERBOSITY LL_NOTICE

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
    /* General */
    pid_t pid;                  /* Main process pid. */
    char *configfile;           /* Absolute config file path, or NULL */
    char *executable;           /* Absolute executable file path. */
    char **exec_argv;           /* Executable argv vector (copy). */

    char * logfile;//日志文件位置
    int verbosity;//loglevel日志等级
    boolean syslog_enabled;//是否记录系统日志
    struct RedisConfig redisconfig;
} ;

void initConfig(int argc, char *argv[]);
char *zstrdup(const char *s);
void loadServerConfigFromString(char *config);
void loadServerConfig(char *filename, char *options);
void serverLogRaw(int level, const char *msg);
void serverLog(int level, const char *fmt, ...);
#endif //CSTANDRAD_CONFIG_H
