cmake_minimum_required (VERSION 3.12)

project(cpp-tools)

file(GLOB_RECURSE SOURCES "./app.cpp" "./utils/*.cpp")

add_compile_options(-std=c++17 -mavx2)

add_executable(app ${SOURCES})

target_link_libraries(app)