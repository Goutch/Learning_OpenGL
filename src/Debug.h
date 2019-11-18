#pragma once


namespace Debug {
    template <typename T>
    void printVector(const T x,const T y,const  T z){
        std::cout << "(" << x << "," << y <<","<< x <<")" << std::endl;
    }
    template <typename T>
    void printVector(const T x,const T y)
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
}

