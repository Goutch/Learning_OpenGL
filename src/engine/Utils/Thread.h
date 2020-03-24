#pragma once

#include <future>
template <class T>
struct Thread {
    std::shared_ptr<std::future<T>> result;
    Thread(std::shared_ptr<std::future<T>> result)
    {
        this->result=result;
    }
    T getResult()
    {
        auto status = result->wait_for(std::chrono::milliseconds(0));
        if(status == std::future_status::ready){
            return result->get();
        }
    };
    bool isFinish()
    {
        auto status = result->wait_for(std::chrono::milliseconds(0));
        return status == std::future_status::ready;
    }
};

