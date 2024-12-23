#pragma once
#include <random>

template <typename T>
class Randomizer {
public:
    static T generate(T min, T max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(min, max);
        return dis(gen);
    }
};