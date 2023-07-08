#ifndef _LOGGER_TEST_H
#define _LOGGER_TEST_H

#include "../../../../Src/common/log/custom_log.h" 
#include <gtest/gtest.h>

using ::testing::Test;



class CustomLogTest: public Test {

protected:
    void SetUp() {

    }
    void TearDown() {
        
    }

public:
    string readFromLog(const string& filepath);
    // void testLogRead(const string& p1,const string& p2);

};


#endif //_LOGGER_TEST_H