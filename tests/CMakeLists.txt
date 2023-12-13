add_executable(tests src/TestRunner.cpp
    # Tests {{{
    src/Day1.cpp
    src/Day2.cpp
    src/Day3.cpp
    # }}}
)

# Catch2 {{{
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.0)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests Catch2::Catch2)
# }}}

target_link_libraries(tests aoc_src)
