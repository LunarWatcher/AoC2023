#include "Day10.hpp"
#include "aoc/input/InputUtils.hpp"
#include <queue>
#include <stdexcept>

namespace aoc {

Day10::Day10(const std::string& input) : Day(10) {
    TIMER_START;
    this->tiles = InputUtils::fileToMap<Tile>(
        input, 
        {
            {'.', Tile::GROUND},
            {'|', Tile::NS_PIPE},
            {'-', Tile::WE_PIPE},
            {'L', Tile::NE_PIPE},
            {'J', Tile::NW_PIPE},
            {'7', Tile::SW_PIPE},
            {'F', Tile::SE_PIPE},
            {'S', Tile::SOURCE}
        }
    );
    height = tiles.size();
    width = tiles.at(0).size();

    for (size_t y = 0; y < tiles.size(); ++y) {
        for (size_t x = 0; x < tiles.at(0).size(); ++x) {
            if  (tiles.at(y).at(x) == Tile::SOURCE) {
                sourceCoords = { x, y };
                goto done;
            }
        }
    }

done:;
    loopMap = std::vector<std::vector<bool>>((size_t) height, std::vector<bool>(width, false));
    TIMER_STOP(10);
}

bool Day10::canTraverse(Vec2i currTile, Vec2i dest) {
    static const std::map<Tile, Direction> directions = {
        {Tile::SOURCE, { true, true, true, true }},
        {Tile::WE_PIPE, { false, false, true, true }},
        {Tile::NS_PIPE, { true, true, false, false }},
        {Tile::NE_PIPE, { true, false, true, false }},
        {Tile::NW_PIPE, { true, false, false, true }},
        {Tile::SW_PIPE, { false, true, false, true }},
        {Tile::SE_PIPE, { false, true, true, false }}
    };
    if (currTile.first != dest.first && currTile.second != dest.second) {
        // same tile as origin
        return false;
    } else if (dest.first < 0 || dest.second < 0 || dest.first >= width || dest.second >= height) {
        // OOB check
        return false;
    }
    auto tile = getTile(currTile);
    auto destTile = getTile(dest);
    if (destTile == Tile::GROUND) {
        return false;
    } else if (tile == Tile::GROUND) {
        throw std::runtime_error("Wtf did you do?");
    }

    if (currTile.first > dest.first) {
        // going west
        return directions.at(tile).west && directions.at(destTile).east;
    } else if (currTile.first < dest.first) {
        // Going east
        return directions.at(tile).east && directions.at(destTile).west;
    } else if (currTile.second > dest.second) {
        // Going north (y is inverted)
        return directions.at(tile).north && directions.at(destTile).south;
    } else if (currTile.second < dest.second) {
        // Going south
        return directions.at(tile).south && directions.at(destTile).north;
    }
    throw std::runtime_error("Unreachable");
}

long long Day10::part1() {
    static const std::vector<Vec2i> steps = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    std::map<Vec2i, long long> dists;

    std::queue<std::pair<Vec2i, long long>> queue;
    queue.push({sourceCoords, 0});

    while (queue.size()) {
        auto& [curr, accumulatedDist] = queue.front();
        if (!dists.contains(curr) || dists.at(curr) < accumulatedDist) {
            loopMap.at(curr.second).at(curr.first) = true;
            dists[curr] = accumulatedDist;
        }

        for (auto& step : steps) {
            Vec2i next = {curr.first + step.first, curr.second + step.second};
            if (canTraverse(curr, next)) {
                if (!dists.contains(next) || dists.at(next) > accumulatedDist + 1) {
                    queue.push({next, accumulatedDist + 1});

                }
            }
        }

        queue.pop();
    }
    
    long long max = 0;
    for (auto& [_, dist] : dists) {
        max = std::max(dist, max);
    }

    return max;
}

long long Day10::part2() {
    long long area = 0;

    for (size_t y = 0; y < height; ++y) {
        bool inside = false;
        std::optional<Tile> expectedEndTile = std::nullopt;
        for (size_t x = 0; x < width; ++x) {
            auto isPipe = loopMap.at(y).at(x);
            if (isPipe) {
                auto tile = tiles.at(y).at(x);

                if (!expectedEndTile.has_value()) {
                    switch (tile) {
                    case Tile::SOURCE:
                        // Source is never going to trigger this, but it's here anyway.
                    case Tile::NS_PIPE:
                        inside = !inside;
                        break;
                    case Tile::NE_PIPE:
                        expectedEndTile = Tile::NW_PIPE;
                        break;
                    //case Tile::NW_PIPE:
                        //expectedEndTile = Tile::SW_PIPE;
                        //break;
                    //case Tile::SW_PIPE:
                        //break;
                    case Tile::SE_PIPE:
                        expectedEndTile = Tile::SW_PIPE;
                        break;
                    case Tile::GROUND:
                    case Tile::WE_PIPE:
                        std::cout << "Bad tile type" << std::endl;
                        throw std::runtime_error("Bad tile type: " + std::to_string(static_cast<int>(tile)));
                    case Tile::SW_PIPE:
                    case Tile::NW_PIPE:
                        std::cout << "Fucking moron" << std::endl;
                        throw std::runtime_error("You fucking suck at geometry");
                    }
                } else {
                    if (tile == Tile::WE_PIPE) {
                        // We're going along, ignore
                        continue;
                    } else if (tile == Tile::SOURCE) {
                        // Another edge-case
                        continue;
                    } else {
                        if (tile != expectedEndTile.value()) {
                            inside = !inside;
                        }
                        expectedEndTile = std::nullopt;
                    }
                }
            } else if (inside) {
                area += 1;
            }
        }
    }
    return area;
}

}
