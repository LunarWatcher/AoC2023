#include "Day6.hpp"
#include "aoc/input/InputUtils.hpp"
#include <cmath>
#include <sstream>
#include <stdexcept>

namespace aoc {


Day6::Day6(const std::string& input) : Day(6) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    std::string sink;
    auto timeLine = std::stringstream(raw.at(0));
    auto distLine = std::stringstream(raw.at(1));

    // Could just seek, but I'm lazy
    timeLine >> sink;
    distLine >> sink;

    auto time = InputUtils::ssToLongVector(timeLine);
    auto dist = InputUtils::ssToLongVector(distLine);

    if (time.size() != dist.size()) {
        throw std::runtime_error("Parsing failed");
    }
    std::stringstream timeAcc, recordAcc;
    for (size_t i = 0; i < time.size(); ++i) {
        races.push_back({
            .time = time.at(i),
            .recordDistance = dist.at(i)
        });
        timeAcc << time.at(i);
        recordAcc << dist.at(i);
    }

    long long p2time, p2record;

    timeAcc >> p2time;
    recordAcc >> p2record;
    this->p2Race = { .time = p2time, .recordDistance = p2record };

    TIMER_STOP(6);

}

long long Day6::countWinWays(const Race& race) {

    /*
    // Full form, without optimisations to the ceil operation (which is apparently a bottleneck?)
    return race.time
        - 2
        * std::ceil(
            1.0 / 2.0 * (race.time - std::pow(race.time * race.time - 4 * race.recordDistance, 0.5))
        ) + 1;
     */

    double x = 1.0 / 2.0 * (race.time - std::sqrt(race.time * race.time - 4 * race.recordDistance));
    long long ceil = (long long) x + (x > (long long) x);
    return race.time - 2 * ceil + 1;
}

long long Day6::part1() {
    long long product = 1;

    for (const auto& race : races) {
        product *= countWinWays(race);
        //for (long long i = 1; i < race.time; ++i) {
            //if ((race.time - i) * i >= race.recordDistance) {
                ////return race.time - 2 * i + 1;
                //product *= race.time - 2 * i + 1;
            //}
        //}
    }

    return product;
}

long long Day6::part2() {
    return countWinWays(p2Race);
}

}
