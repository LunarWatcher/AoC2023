#include "Day7.hpp"
#include "aoc/days/Day.hpp"
#include "aoc/input/InputUtils.hpp"
#include <algorithm>
#include <map>
#include <stdexcept>
#include <string>

namespace aoc {


Day7::Day7(const std::string& input) : Day(7) {
    auto raw = InputUtils::readFile(input);

    TIMER_START;
    for (auto& line : raw) {
        std::stringstream ss(line);
        std::string hand;
        long long bet;
        long long strength = 0;
        Type t = Type::HIGH;

        ss >> hand >> bet;
        if (ss.bad()) {
            throw std::runtime_error("stringstream failed");
        }
        //std::cout << hand << ", " << bet << std::endl;
        std::vector<long long> processedHand;
        for (auto& chr : hand) {
            switch(chr) {
            case 'A':
                processedHand.push_back(13);
                break;
            case 'K':
                processedHand.push_back(12);
                break;
            case 'Q':
                processedHand.push_back(11);
                break;
            case 'J':
                processedHand.push_back(10);
                break;
            case 'T':
                processedHand.push_back(9);
                break;
            case '9':
                processedHand.push_back(8);
                break;
            case '8':
                processedHand.push_back(7);
                break;
            case '7':
                processedHand.push_back(6);
                break;
            case '6':
                processedHand.push_back(5);
                break;
            case '5':
                processedHand.push_back(4);
                break;
            case '4':
                processedHand.push_back(3);
                break;
            case '3':
                processedHand.push_back(2);
                break;
            case '2':
                processedHand.push_back(1);
                break;
            default:
                throw std::runtime_error("Unhandled case: " + std::to_string(chr));
                break;
            }

            strength += processedHand.back();
        }

        std::map<long long, long long> cardCounts;
        for (auto& num : processedHand) {
            cardCounts[num] += 1;
        }

        for (auto& [_, count] : cardCounts) {
            //std::cout << bet << ": " << _ << " with " << count << std::endl;
            if (count == 2) {
                if (t == Type::ONE) {
                    t = Type::TWO;
                } else if (t == Type::THREE) {
                    t = Type::FULL;
                    break;
                } else {
                    t = Type::ONE;
                }
            } else if (count == 3) {
                if (t == Type::ONE) {
                    t = Type::FULL;
                } else {

                    t = Type::THREE;
                }
            } else if (count == 4) {
                t = Type::FOUR;
                break;
            } else if (count == 5) {
                t = Type::FIVE;
                break;
            }
        }
        if (processedHand.size() != 5) {
            throw std::runtime_error("Hand size is not 5");
        }
        hands.push_back(Hand {
            processedHand,
            bet,
            strength,
            t,
            cardCounts
        });
        //std::cout << bet << " classified as " << static_cast<int>(t) << std::endl;
    }

    //std::sort(
        //hands.begin(),
        //hands.end(),
        //[](const auto& a, const auto& b) {
            //return a < b; // && a != b;
        //});
    std::sort(hands.begin(), hands.end());

    TIMER_STOP(7);
}

long long Day7::part1() {
    long long r = 0;
    for (size_t i = 0; i < hands.size(); ++i) {
        auto& hand = hands.at(i);
        r += hand.bet * (i + 1ll);
        //std::cout << hand.bet << std::endl;
    }
    return r;
}

long long Day7::part2() {
    // Petition to drag the elf who decided to introduce jokers straight
    // to hell.
    // Tanks in advantaged

    for (auto& hand : hands) {
        for (auto& card : hand.hand) {
            if (card == 10) {
                card = 0;
            }
        }

        switch (hand.t) {
        case Type::FIVE:
            // 5s cannot be improved
            continue;
        case Type::FOUR:
            if (hand.cardCounts[10] == 1) {
                hand.t = Type::FIVE;
            } else if (hand.cardCounts[10] == 4) {
                hand.t = Type::FIVE;
            }
            break;
        case Type::FULL:
            if (hand.cardCounts[10] == 2 || hand.cardCounts[10] == 3) {
                hand.t = Type::FIVE;
            }
            break;
        case Type::THREE:
            if (hand.cardCounts[10] == 1) {
                hand.t = Type::FOUR;
            }
            break;
        case Type::TWO:
            if (hand.cardCounts[10] == 1) {
                hand.t = Type::FULL;
            } else if (hand.cardCounts[10] == 2) {
                hand.t = Type::FOUR;
            }
            break;
        case Type::ONE:

            if (hand.cardCounts[10] == 1 || hand.cardCounts[10] == 2) {
                // case 1: jokers are not the pair; form a three
                // Case 2: jokers are the pair, form a three anyway
                hand.t = Type::THREE;

            }
            break;
        case Type::HIGH:
            if (hand.cardCounts[10] == 1) {
                hand.t = Type::ONE;
            }
            break;
        }
        //std::cout << hand.bet << " reclassified as " << static_cast<int>(hand.t) << std::endl;
    }

    std::sort(hands.begin(), hands.end());


    long long r = 0;
    for (size_t i = 0; i < hands.size(); ++i) {
        auto& hand = hands.at(i);
        r += hand.bet * (i + 1ll);
        //std::cout << hand.bet << std::endl;
    }
    return r;
}

}
