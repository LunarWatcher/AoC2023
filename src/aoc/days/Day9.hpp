#pragma once

#include "aoc/days/Day.hpp"
#include <vector>
namespace aoc {

class Day9 : public Day {
private:
    struct Report {
        std::vector<
            std::vector<long long>
        > values;
    };

    std::vector<Report> reports;
public:
    Day9(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
