#pragma once 

#include "aoc/days/Day.hpp"
namespace aoc {

class Day13 : public Day {
public:
    struct Image {
        // Representation of the image where each outer vector 
        // is a row (y), and each inner vector is the columns in that row (x)
        std::vector<std::vector<bool>> rows;

        // Same as rows, but with columns (x) first, and y values in inner
        // vectors
        std::vector<std::vector<bool>> cols;

        Image(const std::vector<std::vector<bool>>& rows);
    };


    std::vector<Image> images;

    long long validateRange(long long x, long long x1, const std::vector<std::vector<bool>>& image);
    long long getRotationalAxis(const std::vector<std::vector<bool>>& img);

public:
    Day13(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
