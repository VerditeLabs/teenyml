# CMakeList.txt : CMake project for teenyml, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("teenyml")

# Add source to this project's executable.
add_library(teenyml "src/teenyml.c"  "inc/teenyml.h")

set_property(TARGET teenyml PROPERTY C_STANDARD 11)

target_include_directories(teenyml PUBLIC "inc" "3rdparty/hedley" "3rdparty/p99/p99")
target_compile_options(teenyml PUBLIC -Weverything -w)

add_executable(teenyml_test "3rdparty/munit/munit.c" "src/testmain.c")

target_link_libraries(teenyml_test teenyml)
target_include_directories(teenyml_test PUBLIC "3rdparty/munit")
target_compile_definitions(teenyml_test PUBLIC TEENYML_TESTING=1)

# TODO: Add tests and install targets if needed.
