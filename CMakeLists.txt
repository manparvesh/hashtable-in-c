cmake_minimum_required(VERSION 3.9)
project(hashtable_in_c C)

set(CMAKE_C_STANDARD 11)

############################################################
# Create a library
############################################################

# Generate the static library from the library sources
add_library(hashtable_in_c STATIC
        src/hashtable-simple.h src/hashtable-simple.c)
# link math library to hashtable_in_c
target_link_libraries(hashtable_in_c m)

target_include_directories(hashtable_in_c
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        )

############################################################
# Create an executable for testing
############################################################

# Add an executable with the above sources
add_executable(hashtable_test
        tests/main.c)

# link the new hello_library target with the hello_binary target
target_link_libraries(hashtable_test
        PRIVATE
        hashtable_in_c
        )

############################################################
# Enable testing
############################################################

enable_testing()

add_test(NAME "hashtable_test"
        COMMAND hashtable_test)
