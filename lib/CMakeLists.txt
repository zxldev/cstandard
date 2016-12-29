add_subdirectory(lession)
add_subdirectory(common)


#github引用的sds库
set(LIB_SRC sds/sds.c)
add_library(libsds ${LIB_SRC})
