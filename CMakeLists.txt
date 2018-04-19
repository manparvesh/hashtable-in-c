cmake_minimum_required(VERSION 3.9)
project(hashtable_in_c C)

set(CMAKE_C_STANDARD 99)

add_executable(hashtable_test
        main.c src/generic_hashtable.h src/hashtable.h)

enable_testing()

add_test(NAME "hashtable_test"
        COMMAND hashtable_test)
