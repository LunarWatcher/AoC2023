#include "Day9.hpp"
#include "aoc/input/InputUtils.hpp"
#include <sstream>

namespace aoc {


Day9::Day9(const std::string& input) : Day(9) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (auto& line : raw) {
        std::stringstream ss(line);
        auto vec = InputUtils::ssToLongVector(ss);

        Report report {
            .values = std::vector<std::vector<long long>> {
                vec
            }
        };

        while (true) {
            auto& last = report.values.back();

            std::vector<long long> additionalLine;
            bool hasNonZero = false;
            for (size_t i = 0; i < last.size() - 1; ++i) {

                auto diff = last.at(i + 1) - last.at(i);
                if (diff != 0) {
                    hasNonZero = true;
                }

                additionalLine.push_back(diff);
            }

            report.values.push_back(additionalLine);

            if (!hasNonZero) {
                break;
            }
        }

        reports.push_back(report);
        
    }
    TIMER_STOP(9);
}

long long Day9::part1() {
    long long sum = 0;

    for (auto& report : reports) {
        int virtualRowAccumulator = 0;
        decltype(report.values)::iterator i = report.values.end();
        while (i != report.values.begin()) {
            --i;

            virtualRowAccumulator += i->back();
        }

        sum += virtualRowAccumulator;
    }

    return sum;
}
long long Day9::part2() {
    long long sum = 0;

    for (auto& report : reports) {
        int virtualRowAccumulator = 0;
        decltype(report.values)::iterator i = report.values.end();
        while (i != report.values.begin()) {
            --i;

            virtualRowAccumulator = -virtualRowAccumulator + i->front();
        }

        sum += virtualRowAccumulator;
    }

    return sum;
}

}
