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

#define FATAL Logger::Level::Fatal
#define ERROR Logger::Level::Error
#define WARNING Logger::Level::Warning
#define INFO Logger::Level::Info
#define DEBUG Logger::Level::Debug


using namespace std;

namespace Logger {
    // Severity level enum.
    enum class Level {
        Fatal,
        Error,
        Warning,
        Info,
        Debug
    };

    // Initialize the log.
    void startLog(const string& filepath);

    // Log a message.
    bool log(Level s, const string& msg);

    // Logging class.
    class Log {
    public:
        Log(const string& filepath,bool& append_status);
        bool addLog(Level s, const string& msg);
        ~Log();
    private:
        // File for logging.
        std::ofstream m_logfile;
        std::string levels[5] = {"Fatal", "Error", "Warning", "Info", "Debug"};
    };
}