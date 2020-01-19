//
// Created by User on 2020-01-17.
//

#include "Log.h"
#include "iostream"

Log::LogLevel Log::log_level = Log::DEBUG;

void Log::logLevel(Log::LogLevel level) {
    Log::log_level = level;
}

void Log::debug(const std::string &s) {
    if (Log::log_level >= DEBUG) {
        std::clog<< "[DEBUG]" << s << std::endl;
    }
}

void Log::message(const std::string &s) {
    if (Log::log_level >= MESSAGE) {
        std::clog << "[MESSAGE]" << s << std::endl;
    }
}

void Log::status(const std::string &s) {
    if (Log::log_level >= STATUS) {
        std::clog << "[STATUS]" << s << std::endl;
    }
}

void Log::error(const std::string &s) {
    if (Log::log_level >= ERROR) {
        std::cerr << "[ERROR]" << s << std::endl;
    }
}

void Log::warning(const std::string &s) {
    if (Log::log_level >= WARNING) {
        std::clog << "[WARNING]" << s << std::endl;
    }
}