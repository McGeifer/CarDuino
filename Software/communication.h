// communication.h

#ifndef _COMMUNICATION_h
#define _COMMUNICATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define CAR_SERIAL_PORT             Serial1
#define CAR_SERIAL_BEGIN(arg)       (CAR_SERIAL_PORT.begin(arg))
#define CAR_SERIAL_PRINT_MSG(arg)   (CAR_SERIAL_PORT.println(arg))

void InitCommunication(void);

#endif

