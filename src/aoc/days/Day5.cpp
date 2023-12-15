#include "Day5.hpp"
#include "aoc/days/Day.hpp"
#include "aoc/input/InputUtils.hpp"
#include <complex>
#include <limits>
#include <stdexcept>

namespace aoc {

Day5::Day5(const std::string& location) : Day(5) {
    constexpr auto
        STATE_SEEDS = -1;

    auto raw = InputUtils::readFile(location);

    TIMER_START;

    auto state = STATE_SEEDS;

    for (auto& line : raw) {
        if (line == "") {
            continue;
        }
        if (line.find("map:") != std::string::npos) {
            ++state;
            orderedMaps.push_back({});
            continue;
        }
        std::stringstream ss(line);
        if (state == STATE_SEEDS) {
            ss.seekg(line.find(' ') + 1);
            InputUtils::ssToLongVector(ss, seeds);
        } else {
            long long start, end, length;
            ss >> end >> start >> length;
            if (ss.bad()) {
                throw std::runtime_error("Failed at " + line);
            }
            this->orderedMaps.at(state).push_back({ start, end, length });
        }
    }

    //std::cout << "Vectors: " << this->orderedMaps.size() << std::endl;
    //std::cout << "Sizes: " << std::endl;
    //for (auto& map : orderedMaps) {
        //std::cout << map.size() << std::endl;
    //}

    TIMER_STOP(5);
}

long long Day5::translate(long long value, const std::vector<AToB>& map) {
    for (auto& [start, end, rangeLen] : map) {
        if (value >= start && value < start + rangeLen) {
            return end + (value - start);
        }
    }
    
    return value;
}

void Day5::rangeTranslation(
    std::pair<long long, long long> seedRange,
    const std::vector<AToB>& map,
    std::set<std::pair<long long, long long>>& out
) {

    const auto [seed, end] = seedRange;
    for (auto& [translationStart, translationEnd, translationLen] : map) {
        auto overlapStart = std::max(seed, translationStart);
        auto overlapEnd = std::min(end, translationStart + translationLen);

        if (overlapStart < overlapEnd) {
            out.insert({
                translationEnd + (overlapStart - translationStart),
                translationEnd + (overlapEnd - translationStart)
            });

            if (seed < overlapStart) {
                //out.insert({
                    //seed, overlapStart
                //});
                rangeTranslation({ seed, overlapStart }, map, out);
            }

            if (overlapEnd < end) {
                //out.insert({
                    //overlapEnd, end
                //});
                rangeTranslation({ overlapEnd, end }, map, out);
            }

            return;
        }

    }
    // No matches, push the entire range unmodified
    out.insert({ seed, end });
}

long long Day5::part1() {
    long long min = std::numeric_limits<long long>::max();
    for (auto seed : seeds) {
        //std::cout << "Start value " << start << std::endl;
        for (auto& map : orderedMaps) {
            //auto _old = start;
            seed = translate(seed, map);
            //std::cout << _old << " -> " << start << std::endl;
        }
        min = std::min(min, seed);
    }

    return min;
}

long long Day5::part2() {
    std::set<std::pair<long long, long long>> startLengthRanges;

    // Even out odd input seeds
    for (size_t i = 0; i < seeds.size() - 1; i += 2) {

        startLengthRanges.insert({seeds.at(i), seeds.at(i) + seeds.at(i + 1)});
    }

    for (auto& map : orderedMaps) {
        std::set<std::pair<long long, long long>> out;
        for (auto& seedRange : startLengthRanges) {
            rangeTranslation(seedRange, map, out);
        }
        startLengthRanges = out;

    }
    // Because a set is used, it's also accidentally sorted. Return the first element
    return startLengthRanges.begin()->first;
}

}
