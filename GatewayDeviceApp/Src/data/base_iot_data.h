
#ifndef _BASE_IOT_DATA_H
#define _BASE_IOT_DATA_H

#include <string>
#include "../../config/gda_configs.h"
#include <chrono>
#include <ctime> 

using namespace std;


class BaseIotData {
    private:
        string name;
        int statusCode;
        int typeID;
        string locationID;
        float latitude;
        float longitude;
        float elevation;
        long timeStampMillis;
        string timeStamp;

        
    protected:
        virtual void updateTimeStamp() final;
        virtual void handleUpdateData(const BaseIotData& data);
        BaseIotData();

    public:
        virtual void updateData(const BaseIotData& data);
        void setTypeID(int id);
        void setStatusCode(int code);
        void setName(const string& name);
        void setLocationID(const string& id);
        void setElevation(float val);
        void setLatitude(float val);
        void setLongitude(float val);
        friend ostream& operator<<(ostream& o,const BaseIotData& b);
        string convertToString() const;
        BaseIotData& operator=(const BaseIotData& rhs);

        string getName() const;
        float getElevation() const;
        float getLatitude() const;
        float getLongitude() const;
        string getLocationID() const;
        int getStatusCode() const;
        string getTimeStamp() const;
        long getTimeStampMillis() const;
        int getTypeID() const;
        bool hasError() const;
        
};



#endif //_BASE_IOT_DATA_H