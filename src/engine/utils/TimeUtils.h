
#pragma once
#include <chrono>
class TimeUtils {
    static std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>> start;
public:
    static void startTimer();
    static double stopTimer();


};


