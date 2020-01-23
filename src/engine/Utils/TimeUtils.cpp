//
// Created by User on 22-Jan.-2020.
//

#include "TimeUtils.h"

std::string TimeUtils::getTimeString() {
    char buffer[80];

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    strftime(buffer, sizeof(buffer), "%d_%m_%Y %H_%M_%S", &newtime);
    std::string str(buffer);

    return str;
}