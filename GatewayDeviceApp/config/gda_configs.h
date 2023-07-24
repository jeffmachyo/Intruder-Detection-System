#pragma once


/*
 * Logger prameters 
*/

#define LOGFILEPATH "/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/gda_log.txt"

/*
 * Gateway Service 
*/

#define CREDFILE    "./cred/PiotPersistenceCred.props"
#define GATEWAYHOST "10.42.0.1"
#define GATEWAYPORT 6379U

/*
 * Default values
*/




#define NOT_SET                                 "Not Set"
#define DEFAULT_HOST                            "localhost"
#define DEFAULT_MQTT_PROTOCOL                   "tcp"
#define DEFAULT_MQTT_SECURE_PROTOCOL            "ssl"
#define DEFAULT_MQTT_PORT                       1883U
#define DEFAULT_MQTT_SECURE_PORT                8883U
#define DEFAULT_KEEP_ALIVE                      60U
#define DEFAULT_POLL_CYCLES                     60U
#define DEFAULT_TTL                             60U

#define DEFAULT_VAL                             0.0f
#define DEFAULT_LAT                             DEFAULT_VAL
#define DEFAULT_LON                             DEFAULT_VAL
#define DEFAULT_ELEVATION                       DEFAULT_VAL
#define DEFAULT_SENSOR_TYPE                     1001U
#define DEFAULT_TYPE_ID                         DEFAULT_SENSOR_TYPE   
#define DEFAULT_COMMAND                         0U
#define DEFAULT_STATUS                          0U
#define OFF_COMMAND                             DEFAULT_COMMAND
#define ON_COMMAND                              1U
#define REBOOT_SYSTEM_COMMAND                   100U
                    

#define NAME_PROP                               "name"
#define DEVICE_ID_PROP                          "deviceID"
#define TYPE_CATEGORY_ID_PROP                   "typeCategoryID"
#define TYPE_ID_PROP                            "typeID"
#define TIMESTAMP_PROP                          "timeStamp"
#define HAS_ERROR_PROP                          "hasError"
#define STATUS_CODE_PROP                        "statusCode"
#define LOCATION_ID_PROP                        "locationID"
#define LATITUDE_PROP                           "latitude"
#define LONGITUDE_PROP                          "longitude"
#define ELEVATION_PROP                          "elevation"
#define COMMAND_PROP                            "command"
#define STATE_DATA_PROP                         "stateData"
#define VALUE_PROP                              "value"
#define IS_RESPONSE_PROP                        "isResponse"
#define CPU_UTIL_PROP                           "cpuUtil"
#define DISK_UTIL_PROP                          "diskUtil"
#define MEM_UTIL_PROP                           "memUtil"
#define SENSOR_DATA_LIST_PROP                   "sensorDataList"
#define DEVICE_LOCATION_ID                      "gatewaydevice001"





	// public static final String DEFAULT_HOST             = "localhost";
	// public static final String DEFAULT_COAP_PROTOCOL    = "coap";
	// public static final String DEFAULT_COAP_SECURE_PROTOCOL = "coaps";
	// public static final int    DEFAULT_COAP_PORT        = 5683;
	// public static final int    DEFAULT_DATA_PORT        = 6379;
	// public static final int    DEFAULT_COAP_SECURE_PORT = 5684;
	// public static final String DEFAULT_MQTT_PROTOCOL    = "tcp";
	// public static final String DEFAULT_MQTT_SECURE_PROTOCOL = "ssl";
	// public static final int    DEFAULT_MQTT_PORT        = 1883;
	// public static final int    DEFAULT_MQTT_SECURE_PORT = 8883;
	// public static final int    DEFAULT_KEEP_ALIVE       = 60;
	// public static final int    DEFAULT_POLL_CYCLES      = 60;
	// public static final int    DEFAULT_TTL              = 60;
	
	// public static final float  DEFAULT_VAL = 0.0f;
	
	// // for purposes of this library, float precision is more then sufficient
	// public static final float  DEFAULT_LAT = DEFAULT_VAL;
	// public static final float  DEFAULT_LON = DEFAULT_VAL;
	// public static final float  DEFAULT_ELEVATION = DEFAULT_VAL;

	// public static final int DEFAULT_ACTION_ID = 0;
	// public static final int INITIAL_SEQUENCE_NUMBER = 0;
	
	// public static final String PRODUCT_NAME = "PIOT";
	// public static final String CLOUD        = "Cloud";
	// public static final String GATEWAY      = "Gateway";
	// public static final String CONSTRAINED  = "Constrained";
	// public static final String DEVICE       = "Device";
	// public static final String SERVICE      = "Service";

	// public static final String CONSTRAINED_DEVICE = CONSTRAINED + DEVICE;
	// public static final String GATEWAY_DEVICE     = GATEWAY + DEVICE;
	// public static final String GATEWAY_SERVICE    = GATEWAY + SERVICE;
	// public static final String CLOUD_SERVICE      = CLOUD + SERVICE;

	// /*****
	//  * Property Names
	//  */

	// public static final String NAME_PROP        = "name";
	// public static final String DEVICE_ID_PROP   = "deviceID";
	// public static final String TYPE_CATEGORY_ID_PROP = "typeCategoryID";
	// public static final String TYPE_ID_PROP     = "typeID";
	// public static final String TIMESTAMP_PROP   = "timeStamp";
	// public static final String HAS_ERROR_PROP   = "hasError";
	// public static final String STATUS_CODE_PROP = "statusCode";
	// public static final String LOCATION_ID_PROP = "locationID";
	// public static final String LATITUDE_PROP    = "latitude";
	// public static final String LONGITUDE_PROP   = "longitude";
	// public static final String ELEVATION_PROP   = "elevation";
	
	// public static final String COMMAND_PROP     = "command";
	// public static final String STATE_DATA_PROP  = "stateData";
	// public static final String VALUE_PROP       = "value";
	// public static final String IS_RESPONSE_PROP = "isResponse";

	// public static final String CPU_UTIL_PROP    = "cpuUtil";
	// public static final String DISK_UTIL_PROP   = "diskUtil";
	// public static final String MEM_UTIL_PROP    = "memUtil";
	
	// public static final String SENSOR_DATA_LIST_PROP      = "sensorDataList";
	// public static final String SYSTEM_PERF_DATA_LIST_PROP = "systemPerfDataList";
	
	// public static final String ACTION_ID_PROP             = "actionID";
	// public static final String DATA_URI_PROP              = "dataURI";
	// public static final String MESSAGE_PROP               = "message";
	// public static final String ENCODING_NAME_PROP         = "encodingName";
	// public static final String RAW_DATA_PROP              = "rawData";
	// public static final String SEQUENCE_NUMBER_PROP       = "seqNo";
	// public static final String USE_SEQUENCE_NUMBER_PROP   = "useSeqNo";
	// public static final String SEQUENCE_NUMBER_TOTAL_PROP = "seqNoTotal";
	
	// public static final String SEND_RESOURCE_NAME_PROP    = "sendResourceName";
	// public static final String RECEIVE_RESOURCE_NAME_PROP = "receiveResourceName";
	// public static final String IS_PING_PROP               = "isPing";

	// /*****
	//  * Resource and Topic Names
	//  */

	// public static final String SYS_PERF_DATA  = "SysPerfData";
	// public static final String SYS_STATE_DATA = "SysStateData";
	
	// public static final int    DEFAULT_COMMAND = 0;
	// public static final int    DEFAULT_STATUS  = 0;
	// public static final int    OFF_COMMAND     = DEFAULT_COMMAND;
	// public static final int    ON_COMMAND      = 1;
	// public static final int    REBOOT_SYSTEM_COMMAND    = 100;
	// public static final int    GET_SYSTEM_STATE_COMMAND = 200;
	
	// // these types could be read from a common configuration file
	// // used by both the CDA and GDA to avoid hard-coding type ID's
	// // within both source trees' ConfigConst modules
	// public static final int    DEFAULT_TYPE_ID           =    0;
	// public static final int    DEFAULT_TYPE_CATEGORY_ID  =    0;
	// public static final int    DEFAULT_ACTUATOR_TYPE     = DEFAULT_TYPE_ID;
	// public static final int    DEFAULT_SENSOR_TYPE       = DEFAULT_TYPE_ID;
	
	// public static final int    ENV_DEVICE_TYPE           = 1000;
	// public static final int    HVAC_ACTUATOR_TYPE        = 1001;
	// public static final int    HUMIDIFIER_ACTUATOR_TYPE  = 1002;
	
	// public static final int    HUMIDITY_SENSOR_TYPE      = 1010;
	// public static final int    PRESSURE_SENSOR_TYPE      = 1012;
	// public static final int    TEMP_SENSOR_TYPE          = 1013;
	
	// public static final int    DISPLAY_DEVICE_TYPE       = 2000;
	// public static final int    LED_ACTUATOR_TYPE         = 2001;
	// public static final int    LED_DISPLAY_ACTUATOR_TYPE = 2001;
	
	// public static final int    MEDIA_DEVICE_TYPE         = 3000;
	// public static final int    CAMERA_SENSOR_TYPE        = 3001;
	
	// public static final int    SYSTEM_MGMT_TYPE          = 8000;
	// public static final int    RESOURCE_MGMT_TYPE        = 8001;
	
	// public static final String RESOURCE_MGMT_NAME = "ResourceMgmt";
	
	// public static final int    SYSTEM_PERF_TYPE          = 9000;
	// public static final int    CPU_UTIL_TYPE             = 9001;
	// public static final int    DISK_UTIL_TYPE            = 9002;
	// public static final int    MEM_UTIL_TYPE             = 9003;