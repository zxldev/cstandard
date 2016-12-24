cmake_minimum_required(VERSION 2.8)

#示执行构建过程中详细的信息
set(CMAKE_VERBOSE_MAKEFILE on)
#定义项目名称
project(CSTANDRAD)


#指定了头文件所在的目录
include_directories(lib/lession)

#源码
add_subdirectory(src)
#库文件
add_subdirectory(lib)

message(${CSTANDRAD_BINARY_DIR})

message(${CSTANDRAD_SOURCE_DIR})