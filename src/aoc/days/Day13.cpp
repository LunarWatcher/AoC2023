#include "Day13.hpp"
#include "aoc/input/InputUtils.hpp"
#include <stdexcept>

namespace aoc {


Day13::Day13(const std::string& input) : Day(13) {
    auto raw = InputUtils::readFile(input);

    std::vector<std::vector<bool>> image;

    TIMER_START;
    for (auto& line : raw) {

        if (line == "") {
            images.push_back({ image });
            image.clear();
        } else {
            image.push_back({});
            for (auto& ch : line) {
                image.back().push_back(ch == '#');
            }

        }
    }
    images.push_back({ image });
    TIMER_STOP(13);
}

Day13::Image::Image(const std::vector<std::vector<bool>>& rows) 
        : rows(rows), cols(rows.at(0).size(), std::vector<bool>(rows.size(), false)) {
    for (size_t x = 0; x < cols.size(); ++x) {
        for (size_t y = 0; y < cols.at(0).size(); ++y) {
            cols.at(x).at(y) = rows.at(y).at(x);
        }

    }
}

long long Day13::validateRange(long long vx, long long vx1, const std::vector<std::vector<bool>>& img) {
    if (vx % 2 == vx1 % 2) return -1;

    while (true) {
        //std::cout << vx << ", " << vx1 << std::endl;
        if (img.at(vx) != img.at(vx1)) return -1;
        if (vx + 1 == vx1) return vx + 1;

        ++vx; --vx1;
    }
}

long long Day13::getRotationalAxis(const std::vector<std::vector<bool>>& img) {

    auto isMatch = [&](long long x, long long x1) {
        return img.at(x) == img.at(x1);
    };
    std::pair<long long, long long> range = {-1, -1};

    for (size_t x = 0; x < img.size() - 1; ++x) {
        // option 1: start is bullshit
        size_t x1 = img.size() - 1;
        if (isMatch(x, x1)) {
            auto rs = validateRange(x, x1, img);
            if (rs > -1) {
                return rs;
            }

        } 

        if (x > 0 && isMatch(0, x)) {
            auto rs = validateRange(0, x, img);
            if (rs > -1) {
                return rs;
            }
        }

    }

    return -1;
}

long long Day13::part1() {
    long long fuckday12 = 0;

    size_t c = 0;
    for (auto& image : images) {
        auto horCenter = getRotationalAxis(image.cols);
        auto vertCenter = getRotationalAxis(image.rows);

        //std::cout << "Centers for " << c++ <<  " found: " << horCenter << ", " << vertCenter << std::endl;
        if (horCenter != -1) {
            fuckday12 += horCenter;
        }
        if (vertCenter != -1) {
            fuckday12 += 100 * vertCenter;
        }
    }

    return fuckday12;
}

long long Day13::part2() {
    return 0;
}

}
