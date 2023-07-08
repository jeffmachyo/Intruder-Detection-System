#include "custom_log.h"
#include "../../../config/gda_configs.h"
#include <mutex>
#include <string>
 
namespace Logger {
    // Global Logging Object.

    mutex m_logmutex;
    

    // Method which logs.
    bool log(Level s, const string& msg) {
        Log l(LOGFILEPATH);
        return l.addLog(s,msg);
        
    }

    // Create our global logging object.
    Log::Log(const string& filepath) : m_logfile{} {
        FILE* file;

        file = fopen(filepath.c_str(),"r");

        if (file!=nullptr) {
            m_logfile.open(filepath,ios_base::app);
        }
       
        else {
            m_logfile.open(filepath);
        }
    }

    // Add a message to our log.
    bool Log::addLog(Level s, const string& msg) {

        if (m_logfile.is_open()) {
            lock_guard<mutex> lock(m_logmutex);
            auto time_now = chrono::system_clock::now();
            time_t time_stamp = chrono::system_clock::to_time_t(time_now);
            m_logfile <<ctime(&time_stamp)<<">>"<< levels[static_cast<int>(s)] << ": " << msg << "\n";
            return true;
        }
        return false;
    }

    Log::~Log() {
        m_logfile.close();
    }
}