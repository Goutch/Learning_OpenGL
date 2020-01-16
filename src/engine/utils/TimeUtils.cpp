

#include "TimeUtils.h"
std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>> TimeUtils::start;
void TimeUtils::startTimer() {
    TimeUtils::start = std::chrono::high_resolution_clock::now();
}

double TimeUtils::stopTimer() {
    std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>> end = std::chrono::high_resolution_clock::now();
    auto duration =end-TimeUtils::start;
    return duration.count();
}
