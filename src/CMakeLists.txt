set (SOURCE_FILES
    aoc/days/Day1.cpp
    aoc/days/Day2.cpp
    aoc/days/Day3.cpp
)

add_library(aoc_src STATIC ${SOURCE_FILES})
add_executable(aoc aoc/Main.cpp)

target_include_directories(aoc_src PUBLIC ./)
target_link_libraries(aoc_src fmt::fmt stc)

target_link_libraries(aoc aoc_src)

# vim:ft=cmake
