// digital_poti.h

#ifndef _DIGITAL_POTI_h
#define _DIGITAL_POTI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Ansteuerung Digitalpotentiometer
#define PIN_DIGIPOT_CS  0
#define PIN_DIGIPOT_INC 0
#define PIN_DIGIPOT_UD  0

#endif