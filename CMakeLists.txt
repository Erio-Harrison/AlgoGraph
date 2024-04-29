cmake_minimum_required(VERSION 3.27)
project(AlgoGraph)

set(CMAKE_CXX_STANDARD 20)

# Automatically add all .cpp files within the specified directories
file(GLOB_RECURSE SOURCES
        "competition/*.cpp"
        "leetcode/*.cpp"
        "acwing/*.cpp"
)

add_executable(AlgoGraph ${SOURCES})
