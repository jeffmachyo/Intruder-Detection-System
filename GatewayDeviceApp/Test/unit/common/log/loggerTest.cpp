
#include "loggerTest.h"
#include <mutex>
#include <fstream>
#include "../../../config/gda_configs.h"
#include <thread>


extern mutex Logger::m_logmutex;

string CustomLogTest::readFromLog(const string& filepath) {
    lock_guard<mutex> lock(Logger::m_logmutex);
    ifstream i_file(filepath);
    string str,res;

    while (getline(i_file,str)) {
        if (str.length()) {
            res=str;
        }
        
    }

    return res;

}

void testLogRead(const string& p1,const string& p2) {
    unique_ptr<CustomLogTest> ptr;
    string str=ptr->readFromLog(LOGFILEPATH);
    string cmp = ">>"+p1+": "+p2;
    ASSERT_STREQ(cmp.c_str(),str.c_str());

    
}

void testLogWrite(bool isEven) {
    
    for (int i=0;i<20;++i) {
        if (isEven) {
            if (i%2==0) {
                string prompt = "This is a test INFO logger message number: "+to_string(i);
                ASSERT_TRUE(Logger::log(INFO,prompt));
            }
        }
        else {
            if (i%2) {
                string prompt = "This is a test INFO logger message number: "+to_string(i);
                ASSERT_TRUE(Logger::log(INFO,prompt));
            }
        }
        
    }
}


TEST_F(CustomLogTest, TestLogSingleThread) {

    ASSERT_TRUE(Logger::log(DEBUG,"This is a test DEBUG logger message"));
    ASSERT_TRUE(Logger::log(INFO,"This is a test INFO logger message"));
    ASSERT_TRUE(Logger::log(WARNING,"This is a test WARNING logger message"));
    ASSERT_TRUE(Logger::log(ERROR,"This is a test ERROR logger message"));
    ASSERT_TRUE(Logger::log(FATAL,"This is a test FATAL logger message"));
}

TEST_F(CustomLogTest, TestReadAndWriteLog) {
    string prompt = "I am hereby testing logger reading and writing";
    ASSERT_TRUE(Logger::log(INFO,prompt));
    string str=readFromLog(LOGFILEPATH);

    string cmp = ">>Info: "+prompt;
    ASSERT_STREQ(cmp.c_str(),str.c_str());
       
}


TEST_F(CustomLogTest, TestLogMultipleThread) {
    // thread t1(Logger::log(DEBUG,"Logging a DEBUG message from Thread 1"));
    // string p1 = "Logging a DEBUG message from Thread 1";
    thread t1(testLogWrite,false);
    thread t2(testLogWrite,true);
    // string p2 = "Logging a WARNING message from Thread 3";
    // thread t3(Logger::log,WARNING,p2);
    // thread t4(testLogRead,"Warning",p2);

    // t3.join();
    t1.join();
    t2.join();
    // t3.join();
    // t4.join();
       
}


