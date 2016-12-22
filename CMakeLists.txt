cmake_minimum_required(VERSION 2.8)

project(cstandrad)

add_executable(cstandrad main.c)

install(TARGETS cstandrad DESTINATION bin)