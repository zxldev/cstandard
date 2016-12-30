#设置环境变量
set(APP_SRC main.c config.c)

#生成可执行文件
add_executable(CSTANDRAD ${APP_SRC})
target_link_libraries(CSTANDRAD m pcre libmath libhello libtime libassert  libstdlib libpreg libfunction libstring  hiredis)

set_property(TARGET CSTANDRAD PROPERTY C_STANDARD 99)

#复制文件到指定路径
file(COPY ${CSTANDRAD_SOURCE_DIR}/src/conf DESTINATION ${CSTANDRAD_BINARY_DIR}/src)

install(TARGETS CSTANDRAD DESTINATION bin)