cmake_minimum_required(VERSION 3.29)
project(C_voting_system C)

set(CMAKE_C_STANDARD 17)

add_executable(C_voting_system main.c voter_functions.c)
