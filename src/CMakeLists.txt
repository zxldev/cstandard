#设置环境变量
set(APP_SRC main.c)

#生成可执行文件
add_executable(CSTANDRAD ${APP_SRC})
target_link_libraries(CSTANDRAD m libmath libhello libtime libassert)

install(TARGETS CSTANDRAD DESTINATION bin)