
#pragma once
#include <chrono>
#include <unordered_map>
class Timer {
    std::chrono::high_resolution_clock ::time_point start;

public:
    Timer();
    void reset();

    double ms();
    double ns();

};


