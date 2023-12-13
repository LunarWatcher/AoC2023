#pragma once

#include "Day.hpp"
#include <vector>

namespace aoc {


class Day2 : public Day {
public:
    struct ColorCombo {
        long long greens, reds, blues;
    };
    struct Game {
        long long id;
        std::vector<ColorCombo> sets;
    };
private:
    std::vector<Game> games;
public:

    Day2(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
