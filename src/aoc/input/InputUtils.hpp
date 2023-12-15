#pragma once

#include <fstream>
#include <map>
#include <sstream>
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

inline void ssToLongVector(std::stringstream& ss, std::vector<long long>& in) {
    while (!ss.eof()) {
        long long val;
        ss >> val;
        if (ss.bad()) return;
        in.push_back(val);
    }
}
inline std::vector<long long> ssToLongVector(std::stringstream& ss) {
    std::vector<long long> in;
    ssToLongVector(ss, in);
    return in;
}

template <typename T>
inline std::vector<std::vector<T>> fileToMap(const std::string& path, const std::map<char, T>& typeConversionMap) {
    auto raw = readFile(path);
    
    std::vector<std::vector<T>> out;

    for (auto& line : raw) {
        std::vector<T> lineOut;
        for (auto& ch : line) {
            lineOut.push_back(typeConversionMap.at(ch));
        }
        out.push_back(lineOut);
    }

    return out;
}

}
