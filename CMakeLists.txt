cmake_minimum_required(VERSION 2.8)

project(cstandrad)

add_executable(cstandrad main.c)
target_link_libraries(cstandrad m)
install(TARGETS cstandrad DESTINATION bin)