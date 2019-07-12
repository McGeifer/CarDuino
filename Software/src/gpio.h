// gpio.h

#ifndef _GPIO_h
#define _GPIO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Ansteuerung Relais
#define PIN_K3          24
#define PIN_K4          25

// Ansteuerung Digitalpotentiometer
#define PIN_DIGIPOT_CS  0
#define PIN_DIGIPOT_INC 0
#define PIN_DIGIPOT_UD  0

// Signale Lenkradfernbedienung
#define PIN_SWC_IN1     55
#define PIN_SWC_IN2     56
#define PIN_SWC_IN3     57
#define PIN_SWC_OUT1    37
#define PIN_SWC_OUT2    36
#define PIN_SWC_OUT3    35

// Signale Joying HU
#define PIN_HU_CURRENT  0
#define PIN_HU_KEY1     0

void InitIO(void);

#endif