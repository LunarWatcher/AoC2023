#include "Day11.hpp"
#include "aoc/input/InputUtils.hpp"
#include "fmt/format.h"

namespace aoc {

Day11::Day11(const std::string& source) : Day(11) {
    auto raw = InputUtils::readFile(source);

    TIMER_START;
    for (int i = 0; i < raw.at(0).size(); ++i) {
        this->emptyCols.push_back(i);
    }

    for (size_t row = 0; row < raw.size(); ++row) {
        auto rowVal = raw.at(row);
        bool empty = true;
        for (size_t col = 0; col < rowVal.size(); ++col) {
            if (rowVal.at(col) == '#') {
                empty = false;

                galaxies.push_back({ col, row });

                if (auto it = std::find(emptyCols.begin(), emptyCols.end(), col);
                        it != emptyCols.end()) {
                    emptyCols.erase(it);
                }
            }
        }
        if (empty) {
            emptyRows.push_back(row);
        }
    }
    //std::cout << "Empty rows: ";
    //for (auto& row : emptyRows) {
        //std::cout << row << ", ";
    //}
    //std::cout << std::endl;
    //std::cout << "Empty cols: ";
    //for (auto& row : emptyCols) {
        //std::cout << row << ", ";
    //}
    //std::cout << std::endl;

    TIMER_STOP(11);
}

std::vector<Day11::Vec2i> Day11::transform(const std::vector<Vec2i>& galaxies, long long scaleCoefficient) {
    std::vector<Vec2i> out;

    for (auto galaxy : galaxies) {
        long long preceedingCols = 0, preceedingRows = 0;
        for (auto& col : emptyCols) {
            if (galaxy.first > col) {
                ++preceedingCols;
                //std::cout << fmt::format("{}, {} preceeds {}", galaxy.first, galaxy.second, col) << std::endl;
            } else break; 
        }
        for (auto& row : emptyRows) {
            if (galaxy.second > row) {
                ++preceedingRows;
            } else break;
        }

        
        //std::cout << fmt::format("Before: {}, {}", galaxy.first, galaxy.second) << std::endl;
        //galaxy.first -= preceedingCols;
        //galaxy.second -= preceedingRows;


        galaxy.first += preceedingCols * (scaleCoefficient - 1);
        galaxy.second += preceedingRows * (scaleCoefficient - 1);
        //std::cout << fmt::format("after: {}, {}", galaxy.first, galaxy.second) << std::endl;
        out.push_back(galaxy);
    }

    return out;
}

long long Day11::manhattan(const Vec2i& a, const Vec2i& b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

long long Day11::part1() {
    auto scaledGalaxies = transform(galaxies, 2);

    //long long pairs = 0;
    long long sum = 0;
    for (int i = 0; i < galaxies.size() - 1; ++i) {
        const auto& a = scaledGalaxies.at(i);
        for (int j = i + 1; j < galaxies.size(); ++j) {
            //++pairs;
            const auto& b = scaledGalaxies.at(j);
            auto dist = manhattan(
                a, b
            );
            //std::cout << i << "->" << j << ": " << dist << std::endl;
            sum += dist;
        }
    }
    //std::cout << scaledGalaxies.size() << " galaxies with " << pairs << " pairs" << std::endl;
    return sum;
}

long long Day11::part2() {
    auto scaledGalaxies = transform(galaxies, 1'000'000);

    //long long pairs = 0;
    long long sum = 0;
    for (int i = 0; i < galaxies.size() - 1; ++i) {
        const auto& a = scaledGalaxies.at(i);
        for (int j = i + 1; j < galaxies.size(); ++j) {
            //++pairs;
            const auto& b = scaledGalaxies.at(j);
            auto dist = manhattan(
                a, b
            );
            //std::cout << i << "->" << j << ": " << dist << std::endl;
            sum += dist;
        }
    }
    //std::cout << scaledGalaxies.size() << " galaxies with " << pairs << " pairs" << std::endl;
    return sum;
}

}
