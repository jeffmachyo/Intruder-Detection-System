

#ifndef _SENSOR_DATA_H
#define _SENSOR_DATA_H


#include "base_iot_data.h"
#include "../../config/gda_configs.h"



class SensorData : public BaseIotData {
    
    private:

        int sensorType;
        float value;

    protected:
        // void handleUpdateData(const BaseIotData& data);
        void handleUpdateData(const SensorData& data);

    public:
        
        SensorData(int sensorType=DEFAULT_SENSOR_TYPE);
        int getType() const;
        float getValue() const;
        void setType(int type);
        void setValue(float val);
        void updateData(const SensorData& data);
};



#endif