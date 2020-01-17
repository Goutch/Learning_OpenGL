
#pragma once
#include <chrono>
#include <unordered_map>
class Timer {
    std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>> start;
public:
    Timer();
    void reset();

    double ms();

};


