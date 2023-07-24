

#include "sensor_data.h"



SensorData::SensorData(int sensorType) : BaseIotData(),value(DEFAULT_VAL) {
    this->sensorType = sensorType;
}

int SensorData::getType() const {
    return sensorType;
}
float SensorData::getValue() const {
    return value;
}
void SensorData::setType(int type) {
    sensorType=type;
}
void SensorData::setValue(float val) {
    value=val;
}

void SensorData::handleUpdateData(const SensorData& data) {
    value = data.getValue();

    BaseIotData::updateData(data);
    
    
}

void SensorData::updateData(const SensorData& data) {
    handleUpdateData(data);
}
