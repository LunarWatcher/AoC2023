set (SOURCE_FILES
    aoc/days/Day1.cpp
    aoc/days/Day2.cpp
    aoc/days/Day3.cpp
    aoc/days/Day4.cpp
    aoc/days/Day5.cpp
    aoc/days/Day6.cpp
    aoc/days/Day7.cpp
    aoc/days/Day8.cpp
    aoc/days/Day9.cpp
    aoc/days/Day10.cpp
    aoc/days/Day11.cpp
    aoc/days/Day12.cpp
    #aoc/days/Day13.cpp
    #aoc/days/Day14.cpp
    #aoc/days/Day15.cpp
    #aoc/days/Day16.cpp
    #aoc/days/Day17.cpp
    #aoc/days/Day18.cpp
    #aoc/days/Day19.cpp
    #aoc/days/Day20.cpp
    #aoc/days/Day21.cpp
    #aoc/days/Day22.cpp
    #aoc/days/Day23.cpp
    #aoc/days/Day24.cpp
    #aoc/days/Day25.cpp
)

add_library(aoc_src STATIC ${SOURCE_FILES})
add_executable(aoc aoc/Main.cpp)

target_include_directories(aoc_src PUBLIC ./)
target_link_libraries(aoc_src fmt::fmt stc)

target_link_libraries(aoc aoc_src)

# vim:ft=cmake
