#pragma once

#include "aoc/days/Day.hpp"
#include <vector>
#include <optional>

namespace aoc {

class Day10 : public Day {
private:
    enum class Tile {
        SOURCE,
        WE_PIPE,
        NS_PIPE,

        NE_PIPE,
        NW_PIPE,
        SW_PIPE,
        SE_PIPE,
        GROUND
    };
    
    struct Direction {
        bool north, south, east, west;
    };
    using Vec2i = std::pair<long long, long long>;

    Vec2i sourceCoords;
    long long width, height;
    std::vector<std::vector<Tile>> tiles;
    std::vector<std::vector<bool>> loopMap;
    const auto& getTile(const Vec2i& c) { return tiles.at(c.second).at(c.first); }


    std::vector<Vec2i> getNextTile(Vec2i currTile, Vec2i prevTile);
    bool canTraverse(Vec2i currTile, Vec2i dest);
public:
    Day10(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
