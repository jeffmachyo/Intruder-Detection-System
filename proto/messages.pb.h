/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8-dev */

#ifndef PB_PB_MESSAGES_PB_H_INCLUDED
#define PB_PB_MESSAGES_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _pb_SensorData {
    char sensorName[40];
    int32_t sensorID;
    int32_t timeStamp;
    int32_t sensorValue;
} pb_SensorData;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define pb_SensorData_init_default               {"", 0, 0, 0}
#define pb_SensorData_init_zero                  {"", 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define pb_SensorData_sensorName_tag             1
#define pb_SensorData_sensorID_tag               2
#define pb_SensorData_timeStamp_tag              3
#define pb_SensorData_sensorValue_tag            4

/* Struct field encoding specification for nanopb */
#define pb_SensorData_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, STRING,   sensorName,        1) \
X(a, STATIC,   REQUIRED, INT32,    sensorID,          2) \
X(a, STATIC,   REQUIRED, INT32,    timeStamp,         3) \
X(a, STATIC,   REQUIRED, INT32,    sensorValue,       4)
#define pb_SensorData_CALLBACK NULL
#define pb_SensorData_DEFAULT NULL

extern const pb_msgdesc_t pb_SensorData_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define pb_SensorData_fields &pb_SensorData_msg

/* Maximum encoded size of messages (where known) */
#define pb_SensorData_size                       74

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
