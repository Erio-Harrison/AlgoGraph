cmake_minimum_required(VERSION 3.27)
project(AlgoGraph)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
        "others/*.cpp"
        "leetcode/*.cpp"
        "acwing/*.cpp"
)

add_executable(AlgoGraph ${SOURCES}
        acwing
        leetcode
        others)
