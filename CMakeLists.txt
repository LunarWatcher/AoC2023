cmake_minimum_required(VERSION 3.10)
project(AoC2023)

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.1.0
)
FetchContent_Declare(stc
    GIT_REPOSITORY https://github.com/LunarWatcher/stc
)

FetchContent_MakeAvailable(stc)
FetchContent_MakeAvailable(fmt)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=undefined")
set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")

add_custom_target(resources
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/inputs

    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/inputs ${CMAKE_BINARY_DIR}/inputs
    COMMENT "Copying input files"
)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

add_dependencies(aoc_src resources)

add_custom_target(test
    COMMAND tests
    DEPENDS tests
    COMMENT "Run tests")
# vim:ft=cmake
