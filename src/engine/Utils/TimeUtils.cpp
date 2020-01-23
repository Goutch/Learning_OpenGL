//
// Created by User on 22-Jan.-2020.
//

#include "TimeUtils.h"

std::string TimeUtils::getTimeString() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d_%m_%Y %H_%M_%S", timeinfo);
    std::string str(buffer);

    return str;
}