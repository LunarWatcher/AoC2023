#include "Day12.hpp"
#include "aoc/days/Day.hpp"
#include "aoc/input/InputUtils.hpp"
#include <chrono>
#include <numeric>

namespace aoc {

Day12::Day12(const std::string& input) : Day(12) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (auto& line : raw) {
        std::stringstream ss(line);
        std::vector<Component> components;
        std::vector<long long> groups;
        long long totalBroken = 0;

        char v = 0;
        size_t idx = 0;
        while (true) {
            if (idx == line.find(' ')) {
                break;
            }
            ++idx;
            ss >> v;

            switch (v) {
            case '?':
                components.push_back(Component::UNKNOWN);
                break;
            case '.':
                components.push_back(Component::WORKING);
                break;
            case '#':
                components.push_back(Component::BROKEN);
                break;
            }

        }

        while (!ss.bad() && !ss.eof()) {
            long long num;
            ss >> num >> v;
            totalBroken += num;
            groups.push_back(num);
        }

        this->input.push_back(Screw {
            components,
            groups,
            totalBroken,
        });
    }
    TIMER_STOP(12);
}

std::vector<Day12::Screw> Day12::recursiveSubtree(Screw root) {
    std::vector<long long> groups;
    long long group = 0;
    bool ng = false;
    bool validating = true;

    auto currBroken = std::accumulate(
        root.components.begin(),
        root.components.end(),
        0ll,
        [](auto acc, const auto& s) {
            //return 0ll;
            //acc += s;
            return acc + (s == Component::BROKEN ? 1 : 0);
        }
    );

    std::vector<Screw> out;
    for (auto& c : root.components) {
        if (c == Component::BROKEN) {
            if (!ng) {
                ng = true;
                group = 0;
            }

            ++group;

        } else if (c == Component::UNKNOWN) {
            validating = false;
            if (currBroken < root.totalBroken) {
                c = Component::BROKEN;
                
                auto a = recursiveSubtree(root);
                if (a.size()) {
                    out.insert(out.end(), a.begin(), a.end());
                }
            }

            c = Component::WORKING;
            auto b = recursiveSubtree(root);
            if (b.size()) {
                out.insert(out.end(), b.begin(), b.end());
            }
        } else {
            if (ng) {
                ng = false;
                groups.push_back(group);
            }
        }
    }
    if (validating) {

        if (groups.size() != root.desiredGroups.size()) {
            return {};
        } 

        for (size_t i = 0; i < groups.size(); ++i) {
            if (groups.at(i) != root.desiredGroups.at(i)) {
                return {};
            }
        }
    }

    return out;
}

long long Day12::part1() {
    return -404;
    long long sum = 0;
    long long i = 0;
    auto now = std::chrono::high_resolution_clock::now();

    for (auto screw : input) {
        sum += recursiveSubtree(screw).size();
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << ++i << "/1000 (" << (std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count()) / i << "ms/spring)" << std::endl;
    }

    return sum;
}

long long Day12::part2() {
    return -404;
    return 0;
}

}
