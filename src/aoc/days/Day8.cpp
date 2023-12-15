#include "Day8.hpp"
#include "aoc/days/Day.hpp"
#include "aoc/input/InputUtils.hpp"
#include <map>
#include <numeric>

namespace aoc {


Day8::Day8(const std::string& input) : Day(8) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (auto& chr : raw.at(0)) {
        if (chr == 'L') {
            instructions.push_back(Direction::LEFT);
        } else {
            instructions.push_back(Direction::RIGHT);
        }
    }

    for (size_t i = 2; i < raw.size(); ++i) {
        auto line = raw.at(i);

        auto def = line.substr(0, 3);
        auto l = line.substr(7, 3);
        auto r = line.substr(12, 3);

        nodes[def] = {
            def, l, r
        };
    }
    TIMER_STOP(8);
}

long long Day8::part1() {

    Node* curr = &nodes.at("AAA");

    long long steps = 0;
    long long ptr = 0;
    do {
        auto instr = instructions.at(ptr);
        std::string next;
        switch (instr) {
        case Direction::LEFT:
            next = curr->left;
            break;
        case Direction::RIGHT:
            next = curr->right;
            break;
        }

        curr = &nodes.at(next);

        ++ptr;
        ptr %= instructions.size();
        ++steps;
    } while (curr->ident != "ZZZ");

    return steps;
}
long long Day8::part2() {
    //Node* curr = &nodes.at("AAA");
    std::map<int, Node*> startNodes;
    size_t idx = 0;
    for (auto& [ident, node] : nodes) {
        if (ident.at(2) == 'A') {
            startNodes.insert({idx++, &node});
        }
    }
    //std::cout << "Start paths: " << startNodes.size() << std::endl;

    std::vector<long long> steps(startNodes.size(), 0);
    long long ptr = 0;
    do {
        std::vector<long long> yeet;
        for (auto& [idx, curr] : startNodes) {

            auto instr = instructions.at(ptr);
            std::string next;
            switch (instr) {
            case Direction::LEFT:
                next = curr->left;
                break;
            case Direction::RIGHT:
                next = curr->right;
                break;
            }

            curr = &nodes.at(next);
            steps.at(idx) += 1;

            if (curr->ident.at(2) == 'Z') {

                yeet.push_back(idx);
            }

        }
        for (auto& idx : yeet) {
            startNodes.erase(idx);
        }
        ++ptr;
        ptr %= instructions.size();

    } while (startNodes.size());

    long long result = steps.back();
    steps.pop_back();
    while (steps.size()) {
        result = std::lcm(result, steps.back());
        steps.pop_back();
    }
    return result;
}

}
