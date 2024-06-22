#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class Logger {
public:
    Logger(const std::string &filename) : logFile(filename, std::ios::app) {
        if (!logFile) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    void log(const std::string &message) {
        if (logFile) {
            std::time_t now = std::time(nullptr);
            logFile << std::asctime(std::localtime(&now)) << ": " << message << std::endl;
        }
    }

private:
    std::ofstream logFile;
};
class Debug : public Logger {
public:
    Debug(const std::string &filename) : Logger(filename) {}

    void debug(const std::string &message) {
        log("DEBUG: " + message);
    }

    void info(const std::string &message) {
        log("INFO: " + message);
    }

    void warn(const std::string &message) {
        log("WARN: " + message);
    }

    void error(const std::string &message) {
        log("ERROR: " + message);
    }
};
