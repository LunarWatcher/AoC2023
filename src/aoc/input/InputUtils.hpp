#pragma once

#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

namespace aoc::InputUtils {

inline std::vector<std::string> readFile(const std::string& path) {
    std::ifstream ifs(path);

    if (!ifs) {
        throw std::runtime_error(path + " does not exist. Are you in the right working directory?");
    }

    std::vector<std::string> out;
    std::string line;
    while (std::getline(ifs, line)) {
        out.push_back(line);
    }

    return out;
}

}
