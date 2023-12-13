#include "Day2.hpp"
#include "aoc/input/InputUtils.hpp"
#include <chrono>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace aoc {

Day2::Day2(const std::string& file) {

    auto raw = InputUtils::readFile(file);

    auto start = std::chrono::high_resolution_clock::now();
    for (auto& line : raw) {
        std::stringstream ss(line);
        ss.seekg(5);

        int gameId;
        ss >> gameId;
        ss.seekg(line.find(' ', 5));

        Game game {
            .id = gameId,
            .sets = {}
        };

        std::string rawSet;
        while (std::getline(ss, rawSet, ';')) {
            ColorCombo set{0, 0, 0};
            std::stringstream subpartition(rawSet);
            std::string colourCountPair;
            while (std::getline(subpartition, colourCountPair, ',')) {
                size_t idx = 0;
                int count = std::stoi(colourCountPair, &idx);

                std::string colour = colourCountPair.substr(idx + 1);
                switch (colour[0]) {
                case 'r':
                    set.reds += count;
                    break;
                case 'g':
                    set.greens += count;
                    break;
                case 'b':
                    set.blues += count;
                    break;
                default:
                    throw std::runtime_error("parse failed");
                }
            }
            game.sets.push_back(set);
        }

        games.push_back(game);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(
            end - start
        ).count();
    std::cout << "Part 2 parsed in " << duration << "ms" << std::endl;
}

long long Day2::part1() {
    long long good = 0;
    for (auto& game : games) {
        for (auto& set : game.sets) {
            if (set.reds > 12 || set.greens > 13 || set.blues > 14) goto nope;
        }
        good += game.id;
nope:;
    }
    return good;
}
long long Day2::part2() {
    long long good = 0;
    for (auto& game : games) {
        long long minReds = 0, minGreens = 0, minBlues = 0;
        for (auto& set : game.sets) {
            minReds = std::max(set.reds, minReds);
            minBlues = std::max(set.blues, minBlues);
            minGreens = std::max(set.greens, minGreens);
        }
        good += minReds * minBlues * minGreens;
    }
    return good;
}

}
