#pragma once 

#include <utility>
#include <string>

#include <chrono>
#include <iostream>
#include <ratio>
#define TIMER_START auto start = std::chrono::high_resolution_clock::now()
#define TIMER_STOP(day) \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration<double, std::milli>( \
            end - start \
        ).count(); \
    std::cout << "Day " << #day << " parsed in " << duration << "ms" << std::endl

namespace aoc {

class Day {
public:
    virtual ~Day() = default;

    virtual long long part1() = 0;
    virtual long long part2() = 0;

};

}
