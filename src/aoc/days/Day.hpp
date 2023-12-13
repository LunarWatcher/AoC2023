#pragma once 

#include <utility>
#include <string>

namespace aoc {

class Day {
public:
    virtual ~Day() = default;

    virtual long long part1() = 0;
    virtual long long part2() = 0;

};

}
