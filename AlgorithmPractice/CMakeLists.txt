cmake_minimum_required(VERSION 3.6)   # CMake version check
project(AlgorithmPractice)            # Create project "AlgorithmPractice"
set(CMAKE_CXX_STANDARD 11)            # Enable C++11 standard

set(SOURCE_FILES
        POJ2394_checking_an_alibi.cpp
        POJ3278_catch_that_cow.cpp
        leetcode10_QAQ_regular_expression_matching.cpp
        leetcode23_TODO_merge_k_sorted_lists.cpp
        leetcode25_TODO_reverse_nodes_in_k_group.cpp
        leetcode30_substring_with_concatenation_of_all_words.cpp)
add_executable(AlgorithmPractice ${SOURCE_FILES})