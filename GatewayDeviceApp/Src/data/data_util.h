


#include <string>
#include "sensor_data.h"


using namespace std;


namespace DataUtil {

string sensorDataToJson(SensorData sensorData);
SensorData jsonToSensorData(string jsonData);

class _DataUtil {

    public:
    /**
	 * Returns a sensor data instance converted from JSON to the caller.
	 *	
	 *	@return SensorData
	 */
        string _sensorDataToJson(SensorData sensorData);
    /**
	 * Returns a sensor data instance converted from JSON to the caller.
	 *	
	 *	@return SensorData
	 */
        SensorData _jsonToSensorData(string jsonData);


};

}


// 	/**
// 	 * Returns the converted sensor data json to the caller.
// 	 *	
// 	 *	@return String
// 	 */

	
// 	public String sensorDataToJson(SensorData sensorData)
// 	{
// 		String jsonData = null;
		
// 		if (sensorData != null) {
// 			Gson gson = new Gson();
// 			jsonData = gson.toJson(sensorData);
// 		}
		
// 		return jsonData;
// 	}
	
// 	/**
// 	 * Returns the converted system performance data json to the caller.
// 	 *	
// 	 *	@return String
// 	 */
// 	public String systemPerformanceDataToJson(SystemPerformanceData sysPerfData)
// 	{
// 		String jsonData = null;
		
// 		if (sysPerfData != null) {
// 			Gson gson = new Gson();
// 			jsonData = gson.toJson(sysPerfData);
// 		}
		
// 		return jsonData;
// 	}

// 	/**
// 	 * Returns the converted system state data json to the caller.
// 	 *	
// 	 *	@return String
// 	 */
	
// 	public String systemStateDataToJson(SystemStateData sysStateData)
// 	{
// 		String jsonData = null;
		
// 		if (sysStateData != null) {
// 			Gson gson = new Gson();
// 			jsonData = gson.toJson(sysStateData);
// 		}
		
// 		return jsonData;
// 	}

// 	/**
// 	 * Returns an actuator data instance converted from JSON to the caller.
// 	 *	
// 	 *	@return ActuatorData
// 	 */

	
// 	public ActuatorData jsonToActuatorData(String jsonData)
// 	{
// 		ActuatorData data = null;
		
// 		if (jsonData != null && jsonData.trim().length() > 0) {
// 			Gson gson = new Gson();
// 			data = gson.fromJson(jsonData, ActuatorData.class);
// 		}
		
// 		return data;
// 	}

// 	/**
// 	 * Returns a sensor data instance converted from JSON to the caller.
// 	 *	
// 	 *	@return SensorData
// 	 */
	
// 	public SensorData jsonToSensorData(String jsonData)
// 	{
// 		SensorData data = null;
		
// 		if (jsonData != null && jsonData.trim().length() > 0) {
// 			Gson gson = new Gson();
// 			data = gson.fromJson(jsonData, SensorData.class);
// 		}
		
// 		return data;
// 	}

// 	/**
// 	 * Returns a system performance data instance converted from JSON to the caller.
// 	 *	
// 	 *	@return SystemPerformanceData
// 	 */
	
// 	public SystemPerformanceData jsonToSystemPerformanceData(String jsonData)
// 	{
// 		SystemPerformanceData data = null;
		
// 		if (jsonData != null && jsonData.trim().length() > 0) {
// 			Gson gson = new Gson();
// 			data = gson.fromJson(jsonData, SystemPerformanceData.class);
// 		}
		
// 		return data;
// 	}

// 	/**
// 	 * Returns a system state data instance converted from JSON to the caller.
// 	 *	
// 	 *	@return SystemStateData
// 	 */
	
// 	public SystemStateData jsonToSystemStateData(String jsonData)
// 	{
// 		SystemStateData data = null;
		
// 		if (jsonData != null && jsonData.trim().length() > 0) {
// 			Gson gson = new Gson();
// 			data = gson.fromJson(jsonData, SystemStateData.class);
// 		}
		
// 		return data;
// 	}
	
// }