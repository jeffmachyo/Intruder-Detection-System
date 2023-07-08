#pragma once

/*
Use it by including this header in every file required, and in your main function start a new log.
    Logger::startLog("Log.txt");
Use the various error levels by naming them and simply passing the info and what you want to output.
    Logger::log(ERROR, "Something went wrong.");
*/

// For the unique pointers.
#include <memory>
// Filestream.
#include <fstream>
// String class for names and parameters passed around.
#include <string>

#include <chrono>
#include <ctime> 
#include <mutex>

#define FATAL Logger::Level::Fatal
#define ERROR Logger::Level::Error
#define WARNING Logger::Level::Warning
#define INFO Logger::Level::Info
#define DEBUG Logger::Level::Debug


using namespace std;

namespace Logger {

    extern mutex m_logmutex;
    // Severity level enum.
    enum class Level {
        Fatal,
        Error,
        Warning,
        Info,
        Debug
    };

    // Log a message.
    bool log(Level s, const string& msg);

    // Logging class.
    class Log {
    public:
        Log(const string& filepath);
        bool addLog(Level s, const string& msg);
        ~Log();
    private:
        // File for logging.
        std::ofstream m_logfile;
        std::string levels[5] = {"Fatal", "Error", "Warning", "Info", "Debug"};
    };
}