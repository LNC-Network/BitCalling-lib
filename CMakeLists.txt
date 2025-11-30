cmake_minimum_required(VERSION 3.10)
project(BitCalling VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -O3")

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
