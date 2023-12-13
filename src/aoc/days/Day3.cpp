#include "Day3.hpp"
#include "aoc/input/InputUtils.hpp"

namespace aoc {

Day3::Day3(const std::string& input) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (size_t lineIdx = 0; lineIdx < raw.size(); ++lineIdx) {
        auto& line = raw.at(lineIdx);

        size_t idx = 0;
        std::stringstream ss(line);

        while (true) {
            idx = line.find_first_of("123456789", idx);
            if (idx == std::string::npos) {
                break;
            }
            ss.seekg(idx);

            long long value;
            ss >> value;

            Number num = {
                .start = { lineIdx, idx },
                .length = (long long) std::to_string(value).length(),
                .value = value,
                .adjacentTo = {}
            };

            for (long long x = num.start.second - 1; x < num.start.second + num.length + 1; ++x) {
                for (long long y = num.start.first - 1; y <= num.start.first + 1; ++y) {
                    if (x < 0 || y < 0) continue;
                    if (x >= (long long) line.size() || y >= (long long) raw.size()) continue;
                    auto line = raw.at(y); 
                    auto chr = line.at(x);

                    std::pair<long long, long long> charCoords(x, y);
                    if (!chars.contains(charCoords)) {
                        if (chr != '.' && !(chr >= '0' && chr <= '9')) {
                            
                            chars[charCoords] = { chr, { num.value } };
                            num.adjacentTo.push_back(charCoords);
                        }
                    } else {
                        num.adjacentTo.push_back(charCoords);
                        chars[charCoords].second.push_back(num.value);
                    }
                }
            }
            
            // Avoid re-reading
            idx += num.length;

            this->numbers.push_back(num);
        }


    }
    TIMER_STOP(3);
}

long long Day3::part1() {
    long long sum = 0;
    for (auto& number : numbers) {
        if (!number.adjacentTo.empty()) {
            sum += number.value;
        }
    }
    return sum;
}

long long Day3::part2() {
    long long sum = 0;
    for (auto& [_, charNearMap] : chars) {
        auto& [chr, values] = charNearMap;
        if (chr == '*' && values.size() == 2) {
            sum += values.at(0) * values.at(1);
        }
    }
    return sum;
}

}
