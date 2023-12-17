#pragma once

#include "aoc/days/Day.hpp"
#include <utility>
#include <vector>

namespace aoc {

class Day11 : public Day {
private:
    using Vec2i = std::pair<long long, long long>;

    std::vector<Vec2i> galaxies;

    std::vector<long long> emptyCols;
    std::vector<long long> emptyRows;

public:
    Day11(const std::string& source);

    long long part1() override;
    long long part2() override;

    long long manhattan(const Vec2i& a, const Vec2i& b);
    std::vector<Vec2i> transform(const std::vector<Vec2i>& galaxies, long long scaleCoefficient);
};

}
