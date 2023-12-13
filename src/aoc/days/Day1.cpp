#include "Day1.hpp"
#include "aoc/input/InputUtils.hpp"
#include <numeric>
#include <iostream>
#include <sstream>

namespace aoc {

Day1::Day1(const std::string& input) : Day(1) {
    raw = InputUtils::readFile(input);

}

long long Day1::part1() {
    std::vector<long long> calibrationValues;
    for (auto& line : raw) {
        size_t firstDigitIdx = line.find_first_of("0123456789");
        size_t secondDigitIdx = line.find_last_of("0123456789");

        std::stringstream ss;
        ss << line[firstDigitIdx] << line[secondDigitIdx] << std::endl;
        long long num;
        ss >> num;
        //std::cout << num << std::endl;
        calibrationValues.push_back(num);
    }
    return std::accumulate(calibrationValues.begin(), calibrationValues.end(), 0ll);
}

long long Day1::part2() {
    static const std::vector<std::pair<std::string, char>> strToNum{
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
    };
    std::vector<long long> calibrationValues;
    for (auto& line : raw) {
        size_t firstDigitIdx = line.find_first_of("0123456789");
        size_t secondDigitIdx = line.find_last_of("0123456789");

        char firstDigit = firstDigitIdx == std::string::npos ? '\0' : line[firstDigitIdx];
        char lastDigit = secondDigitIdx == std::string::npos ? '\0' : line[secondDigitIdx];

        // Find word indices
        for (auto& [word, num] : strToNum) {
            size_t firstWord = line.find(word);
            if (firstWord != std::string::npos && (firstDigitIdx == std::string::npos || firstWord < firstDigitIdx)) {
                firstDigitIdx = firstWord;
                firstDigit = num;
            }
            size_t lastWord = line.rfind(word);
            if (lastWord == std::string::npos) continue;
            if (secondDigitIdx == std::string::npos || lastWord > secondDigitIdx) {
                secondDigitIdx = lastWord;
                lastDigit = num;
            }
        }

        std::stringstream ss;
        ss << firstDigit << lastDigit;
        long long num;
        ss >> num;
        //std::cout << num << std::endl;
        calibrationValues.push_back(num);
    }
    return std::accumulate(calibrationValues.begin(), calibrationValues.end(), 0ll);
}

}
