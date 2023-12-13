#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <fmt/format.h>

#include "aoc/days/Day4.hpp"
#include "days/Day.hpp"
#include "aoc/days/Day1.hpp"
#include "aoc/days/Day2.hpp"
#include "aoc/days/Day3.hpp"

std::pair<long long, double> getDurationAndResults(std::function<long long()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    auto res = func();
    auto end = std::chrono::high_resolution_clock::now();
    return {
        res,
        std::chrono::duration<double, std::milli>(
            end - start
        ).count()
    };
}

void printPart(int partNum, std::pair<long long, double> res) {
    std::cout << "Part " << partNum << ": " << fmt::format("{:<20}", res.first);

    std::string colour;
    if (res.second <= 10.0) {
        colour = "10";
    } else if (res.second <= 100) {
        colour = "190";
    } else if (res.second <= 500) {
        colour = "220";
    } else if (res.second <= 1000) {
        colour = "202";
    } else {
        colour = "196";
    }
    std::cout << "("
        << "\033[48;5;" << colour << "m"
        //<< "\033[48:5:232m"
        << fmt::format("{:>10}", res.second)
        << "ms"
        << "\033[0m"
        << ")"
        << std::endl;

}

int main(int argc, char* argv[]) {
    int min = 0, max = 25;
    if (argc == 2) {
        min = max = std::stoi(argv[1]) - 1;
    }

    for (int i = min; i < max; ++i) {
        std::shared_ptr<aoc::Day> day;

        switch (i + 1) {
        case 1:
            day = std::make_shared<aoc::Day1>("inputs/day1.txt");
            break;
        case 2:
            day = std::make_shared<aoc::Day2>("inputs/day2.txt");
            break;
        case 3:
            day = std::make_shared<aoc::Day3>("inputs/day3.txt");
            break;
        case 4:
            day = std::make_shared<aoc::Day4>("inputs/day4.txt");
            break;
        default:
            return 0;
        }

        printPart(1, getDurationAndResults([&]() { return day->part1(); }));
        printPart(2, getDurationAndResults([&]() { return day->part2(); }));

    }
}
