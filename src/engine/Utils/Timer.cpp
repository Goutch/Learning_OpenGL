

#include "Timer.h"
Timer::Timer() {
    start=std::chrono::high_resolution_clock::now();
}
void Timer::reset() {

    start= std::chrono::high_resolution_clock::now();
}

double Timer::ms() {

    std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - Timer::start;
    return static_cast<double >(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count())/1000;

}

double Timer::ns() {
    std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - Timer::start;
    return static_cast<double >(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count())/1000000;
}








