#pragma once
#include <random>
#include <chrono>

class Rand_int {
public:
    Rand_int() : re(std::chrono::system_clock::now().time_since_epoch().count()) {}
    int get_rand_numb(int min, int max) {
        return std::uniform_int_distribution<int>{min, max}(re);
    }
private:
    std::default_random_engine re;
};