#pragma once

#include "aoc/days/Day.hpp"
#include <set>
#include <stdexcept>
#include <vector>

namespace aoc {

class Day5 : public Day {
private:
    struct AToB {
        long long start, end;
        long long rangeLength;
    };

    std::vector<long long> seeds;

    std::vector<std::vector<AToB>> orderedMaps;

    long long translate(long long value, const std::vector<AToB>& map);
    void rangeTranslation(
        std::pair<long long, long long> seedRange,
        const std::vector<AToB>& map,
        std::set<std::pair<long long, long long>>& out
    );
public:
    Day5(const std::string& input); 

    long long part1() override;
    long long part2() override;
};

}
