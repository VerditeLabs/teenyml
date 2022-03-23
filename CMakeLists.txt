# CMakeList.txt : CMake project for teenyml, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("teenyml")

# Add source to this project's executable.
add_executable (teenyml "src/teenyml.c"  "inc/teenyml.h")

set_property(TARGET teenyml PROPERTY C_STANDARD 11)

target_include_directories(teenyml PUBLIC inc)
target_compile_options(teenyml PUBLIC -Weverything)

# TODO: Add tests and install targets if needed.
