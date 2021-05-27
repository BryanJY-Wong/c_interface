cmake_minimum_required(VERSION 3.13)
project(c_interface)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED src/library.cpp include/library.h include/library_base.h include/pod.h)

add_executable(${PROJECT_NAME}_Test main.c)
set_target_properties(${PROJECT_NAME}_Test PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(${PROJECT_NAME}_Test ${PROJECT_NAME})
