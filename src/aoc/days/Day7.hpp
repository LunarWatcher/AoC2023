#pragma once

#include "aoc/days/Day.hpp"
#include <map>
#include <stdexcept>
#include <vector>
namespace aoc {
enum class Type {
    FIVE = 6,
    FOUR = 5,
    FULL = 4,
    THREE = 3,
    TWO = 2,
    ONE = 1,
    HIGH = 0
};

struct Hand {
    std::vector<long long> hand;
    long long bet;
    long long strength;

    Type t;

    std::map<long long, long long> cardCounts;
};
inline bool operator<(const Hand& a, const Hand& other) {
    if (a.t < other.t) return true;
   if (other.t < a.t) return false;

    for (size_t i = 0; i < a.hand.size(); ++i) {
        if (a.hand.at(i) < other.hand.at(i)) {
            return true;
        } else if (other.hand.at(i) < a.hand.at(i)) {
            return false;
        }
    }
    return false;
}
inline bool operator==(const Hand& a, const Hand& other) {
    return a.t == other.t && a.hand == other.hand;
}

class Day7 : public Day {
public:
    std::vector<Hand> hands;

    Day7(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
