#include "Day12.hpp"
#include "aoc/days/Day.hpp"
#include "aoc/input/InputUtils.hpp"

namespace aoc {

Day12::Day12(const std::string& input) : Day(12) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (auto& line : raw) {
        std::stringstream ss(line);
        std::vector<Component> components;
        std::vector<long long> groups;

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
            groups.push_back(num);
        }

        this->input.push_back(Screw {
            components, groups
        });
    }
    TIMER_STOP(12);
}

std::vector<Day12::Screw> Day12::recursiveSubtree(Screw root) {
    std::vector<long long> groups;
    long long group = 0;
    bool ng = false;
    bool validating = true;


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
            c = Component::BROKEN;
            auto a = recursiveSubtree(root);
            //if (a.size()) {
                //out.insert(out.end(), a.begin(), a.end());
            //}

            c = Component::WORKING;
            auto b = recursiveSubtree(root);
            //if (b.size()) {
                //out.insert(out.end(), b.begin(), b.end());
            //}
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
    long long sum = 0;
    //size_t i = 0;
    for (auto screw : input) {
        sum += recursiveSubtree(screw).size();
        //std::cout << ++i << "/1000" << std::endl;
        
    }

    return sum;
}

long long Day12::part2() {
    return 0;
}

}
