#pragma once

#include "string"

class Log {
public:

    static const int DEBUG = 5;
    static const int MESSAGE= 4;
    static const int STATUS = 3;
    static const int WARNING = 2;
    static const int ERROR = 1;
    static const int NOTHING = 0;

private:
    static int log_level;
public:
    static void logLevel(int level);

    static void debug(const std::string &s);

    static void message(const std::string &s);

    static void status(const std::string &s);

    static void warning(const std::string &s);

    static void error(const std::string &s);


};


