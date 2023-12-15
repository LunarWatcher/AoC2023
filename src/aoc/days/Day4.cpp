#include "Day4.hpp"
#include "aoc/input/InputUtils.hpp"
#include <cmath>
#include <sstream>
#include <unordered_map>

namespace aoc {


Day4::Day4(const std::string& input) : Day(4) {

    auto raw = InputUtils::readFile(input);
    TIMER_START;
    std::string disposal;
    for (auto& line : raw) {
        std::stringstream ss(line);
        ss >> disposal;

        int cardIdx;
        ss >> cardIdx;
        ss.seekg(line.find(':') + 1);

        std::string numbers;
        std::string winningNumbers;
        std::getline(ss, numbers, '|');
        std::getline(ss, winningNumbers);

        cards.push_back(Card {
            .cardIdx = cardIdx,
            .numbers = stringToVec(numbers),
            .winning = stringToVec(winningNumbers)
        });
    }

    TIMER_STOP(4);
}

long long Day4::winCount(const Card& card) {

    long long winning = 0;
    for (auto& num : card.numbers) {
        if (card.winning.contains(num)) {
            winning += 1;
        }
    }
    return winning;
}

long long Day4::part1() {
    long long sum = 0;
    for (auto& card : cards) {
        auto winning = winCount(card);
        if (winning) {
            long long localSum = 1;
            localSum <<= winning - 1;
            sum += localSum;
        }

    }
    return sum;
}

long long Day4::part2() {
    std::unordered_map<long long, long long> cardCounts;
    long long sum = cards.size();
    for (long long i = cards.size() - 1; i >= 0; --i) {
        auto card = cards.at(i);
        auto winning = winCount(card);
        long long subtotals = 0;
        for (auto i = 0ll; i < winning; ++i) {
            subtotals += cardCounts.at(card.cardIdx + i + 1);
        }

        auto cardSum = winning + subtotals;
        sum += cardSum;
        cardCounts[card.cardIdx] = cardSum;
    }


    return sum;
}

}
