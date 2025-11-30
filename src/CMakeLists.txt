file(GLOB_RECURSE SOURCES
    "core/*.c"
    "net/*.c"
    "mesh/*.c"
    "rtp/*.c"
    "audio/*.c"
    "crypto/*.c"
    "sim/*.c"
)

# Create a library for the engine
add_library(bitcalling_lib ${SOURCES})
target_include_directories(bitcalling_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Main executable
add_executable(bitcalling main.c)
target_link_libraries(bitcalling PRIVATE bitcalling_lib)
