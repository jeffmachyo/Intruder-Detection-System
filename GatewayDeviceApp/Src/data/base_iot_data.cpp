#include "base_iot_data.h"


BaseIotData::BaseIotData(): name(NOT_SET),statusCode(DEFAULT_STATUS),typeID(DEFAULT_TYPE_ID),latitude(DEFAULT_LAT),longitude(DEFAULT_LON),elevation(DEFAULT_ELEVATION) {
    setLocationID(DEVICE_LOCATION_ID);
    updateTimeStamp();
}

string BaseIotData::getName() const {
    return name;
}

void BaseIotData::updateTimeStamp() {
    auto time_now = chrono::system_clock::now();
    time_t time_stamp = chrono::system_clock::to_time_t(time_now);
    ctime(&time_stamp);
    timeStamp = to_string(time_stamp);

}
void BaseIotData::handleUpdateData(const BaseIotData& data) {

}

void BaseIotData::updateData(const BaseIotData& data) {
    if ((void*)this!=&data) {
        updateTimeStamp();

        setName(data.getName());
        setTypeID(data.getTypeID());
        setStatusCode(data.getStatusCode());
        setLocationID(data.getLocationID());
        setLatitude(data.getLatitude());
        setLongitude(data.getLongitude());
        setElevation(data.getElevation());
        
        handleUpdateData(data);
    }
}
void BaseIotData::setTypeID(int id) {
    typeID=id;
}
void BaseIotData::setStatusCode(int code) {
    statusCode=code;
}
void BaseIotData::setName(const string& name) {
    if (!name.empty() && name !=" ") {
        this->name = name;
    }
    
}
void BaseIotData::setLocationID(const string& id) {
    if (!id.empty() && id !=" ") {
        locationID=id;
    }
    
}
void BaseIotData::setElevation(float val) {
    elevation=val;
}
void BaseIotData::setLatitude(float val) {
    latitude=val;
}
void BaseIotData::setLongitude(float val) {
    longitude=val;
}
ostream& operator<<(ostream& os,const BaseIotData& b) {
    string str = b.convertToString();
    os<<str;

    return os;
}
string BaseIotData::convertToString() const {
    string str;
    str = string(NAME_PROP)+"="+name+","
        + string(TYPE_ID_PROP)+"="+to_string(typeID)+","
        + string(TIMESTAMP_PROP)+"="+timeStamp+","
        + string(STATUS_CODE_PROP)+"="+to_string(statusCode)+","
        + string(HAS_ERROR_PROP)+"="+to_string(hasError())+","
        + string(LOCATION_ID_PROP)+"="+locationID+","
        + string(LATITUDE_PROP)+"="+to_string(latitude)+","
        + string(LONGITUDE_PROP)+"="+to_string(longitude)+","
        + string(ELEVATION_PROP)+"="+to_string(elevation)+","

    ;
            

    return str;
}

float BaseIotData::getElevation() const {
    return elevation;
}
float BaseIotData::getLatitude() const {
    return latitude;
}
float BaseIotData::getLongitude() const {
    return longitude;
}
string BaseIotData::getLocationID() const {
    return locationID;
}
int BaseIotData::getStatusCode() const {
    return statusCode;
}
string BaseIotData::getTimeStamp() const {
    return timeStamp;
}
long BaseIotData::getTimeStampMillis() const {
    return timeStampMillis;
}
int BaseIotData::getTypeID() const {
    return typeID;
}
bool BaseIotData::hasError() const {
    return (statusCode < 0) ? true : false;
}

BaseIotData& BaseIotData::operator=(const BaseIotData& rhs) {
   
    updateData(rhs);

    return *this;
    
}