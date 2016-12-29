#设置环境变量
set(APP_SRC main.c config.c)

#生成可执行文件
add_executable(CSTANDRAD ${APP_SRC})
target_link_libraries(CSTANDRAD m pcre libmath libhello libtime libassert  libstdlib libpreg libfunction libsds)

install(TARGETS CSTANDRAD DESTINATION bin)