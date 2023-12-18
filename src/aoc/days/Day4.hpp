#pragma once

#include "aoc/days/Day.hpp"
#include <set>
#include <unordered_set>
#include <vector>
#include <stringstream>

namespace aoc {

class Day4 : public Day {
private:
    struct Card {
        int cardIdx;
        std::unordered_set<long long> numbers;
        std::unordered_set<long long> winning;
    };

    std::vector<Card> cards;

    std::unordered_set<long long> stringToVec(const std::string& in) {
        std::stringstream ss(in);
        std::unordered_set<long long> out;
        while (true) {
            long long num;
            ss >> num;
            if (ss.fail()) break;

            out.insert(num);
        }
        return out;
    }

    long long winCount(const Card& card);
public:
    Day4(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
