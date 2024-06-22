#include "log.h"

Logger::Logger(const std::string& filename, LogLevel logLevel)
    : currentLogLevel(logLevel) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error opening log file: " << filename << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::setLogLevel(LogLevel logLevel) {
    currentLogLevel = logLevel;
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

void Logger::log(const std::string& message, LogLevel logLevel) {
    if (logLevel < currentLogLevel) {
        return;
    }

    std::lock_guard<std::mutex> guard(logMutex);

    if (logFile.is_open()) {
        logFile << "[" << getCurrentTime() << "] ";

        switch (logLevel) {
        case DEBUG: logFile << "DEBUG: "; break;
        case INFO: logFile << "INFO: "; break;
        case WARNING: logFile << "WARNING: "; break;
        case ERROR: logFile << "ERROR: "; break;
        }
        
        logFile << message << std::endl;
    }
}

void Logger::debug(const std::string& message) {
    log(message, DEBUG);
}

void Logger::info(const std::string& message) {
    log(message, INFO);
}

void Logger::warning(const std::string& message) {
    log(message, WARNING);
}

void Logger::error(const std::string& message) {
    log(message, ERROR);
}
