/*
    Name:           CarDuino.ino
    Created:	    03.07.2019 18:44:27
    Author:         J.Schiller
    
    MIT License

    Copyright (c) 2019 J.Schiller

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include <SPI.h>
#include <MCP41_Simple.h>
#include "string.h"
#include "lib/Arduino-X9C/src/X9C.h"

/*
 * Kommunikation
 */
#define CAR_SERIAL_PORT             Serial
#define CAR_SERIAL_BEGIN(arg)       (CAR_SERIAL_PORT.begin(arg))
#define CAR_SERIAL_PRINT_MSG(arg)   (CAR_SERIAL_PORT.println(arg))

#define DIGIPOT_SPI                 SPI

/*
 * I/O
 */
#define PIN_K3          24  /* Relais K3 */
#define PIN_K4          25  /* Relais K4 */
#define PIN_K5          25  /* Relais K4 */

#define PIN_SWC_IN1     30   /* SWC Eingang 1 - PIN 2 - BU */
#define PIN_SWC_IN2     31   /* SWC Eingang 2 - PIN 3 - YE */
#define PIN_SWC_IN3     32   /* SWC Eingang 3 - PIN 4 - GN */
#define PIN_SWC_OUT1     2 /* SWC Ausgang 1 - PIN 1 - BN */
#define PIN_SWC_OUT2      3/* SWC Ausgang 2 - PIN 5 - RD */
#define PIN_SWC_OUT3      4/* SWC Ausgang 3 - PIN 6 - BK */

#define PIN_DIGIPOT_CS 10   /* chip select für digital Potentiometer */

/* 
 * Signale HU
 */
//#define PIN_HU_CURRENT  0   /* Stromverbrauch HU  */
//#define PIN_HU_KEY1     0   /* Widerstand für */

/* 
 * Digital Potentiometer
 */
#define DIGI_POT_WIPER_RESISTANCE               125     /* Siehe Datenblatt */
#define DIGI_POT_MAX_RESISTANCE                 100000  /* MCP41100 = 100k */

#define DIGI_POT_RESISTANCE_MUTE                10000
#define DIGI_POT_RESISTANCE_SOURCE_UP           20000
#define DIGI_POT_RESISTANCE_SOURCE_DOWN         30000
#define DIGI_POT_RESISTANCE_VOl_UP              40000
#define DIGI_POT_RESISTANCE_VOl_DOWN            50000
#define DIGI_POT_RESISTANCE_SKIP                60000
#define DIGI_POT_RESISTANCE_ROTARY_SWITCH_UP    70000
#define DIGI_POT_RESISTANCE_ROTARY_SWITCH_DOWN  80000
#define DIGI_POT_RESISTANCE_CUSTOM_1            90000


/*
 * Sonstiges
 */
 #define DIGITAL_DELAY_TIME 5
 //#define DEBUG

enum ECarData
{
    SWC_MUTE,
    SWC_SOURCE_UP,
    SWC_SOURCE_DOWN,
    SWC_VOl_UP,
    SWC_VOl_DOWN,
    SWC_SKIP,
    SWC_ROTARY_SWITCH_1,
    SWC_ROTARY_SWITCH_2,
    SWC_ROTARY_SWITCH_3,    /* Bis hier hin nicht ändern oder NumberOfKeysPressed() anpassen */
    HU_CURRENT_CONSUMPTION,
    SIZE_OF_CAR_DATA        /* immer letztes Element! */
};

const char CARDUINO_WELCOME[] = "CarDuino";
const char CARDUINO_VERSION[] = "Version: 0.1";
const char CARDUINO_CREATED[] = "Created: 03.07.2019 18:44:27";
const char CARDUINO_AUTHOR[] = "Author:  J.Schiller";

bool g_fisrst_start = true;
int16_t g_car_data[SIZE_OF_CAR_DATA] = {};          /* alle wichtigen Werte/ Zustände des Systems */
int16_t g_car_data_last[SIZE_OF_CAR_DATA] = {};     /* Kopie von g_car_data zur Zustandswechsel Erkennung */
MCP41_Simple digiPot(DIGIPOT_SPI);

void setup()
{
#ifdef DEBUG
    CAR_SERIAL_BEGIN(1000000);
#endif
    InitIGPIO();
    //digiPot.begin(PIN_DIGIPOT_CS);
    //digiPot.shutdownMode();             /* tri state Modus sicherstellen */
}

void loop()
{
#ifdef DEBUG
    if (g_fisrst_start)
    {
        delay(1000);
        CAR_SERIAL_PRINT_MSG(CARDUINO_WELCOME);
        CAR_SERIAL_PRINT_MSG(CARDUINO_VERSION);
        CAR_SERIAL_PRINT_MSG(CARDUINO_CREATED);
        CAR_SERIAL_PRINT_MSG(CARDUINO_AUTHOR);
        CAR_SERIAL_PRINT_MSG();
        CAR_SERIAL_PRINT_MSG("Verbindung hergestellt...");
        CAR_SERIAL_PRINT_MSG();
        g_fisrst_start = false;
    }
#endif 

    ReadSteeringWheelControl();
    //ReadHuPowerConsumption();
    //HandleSteeringWheelControl();
    //HeadUnit();
    //Display();
    //SetCarDataLast();
    //CAR_SERIAL_PRINT_MSG("test");
    //delay(1000);
}

/*
 * Hier sollte etwas stehen 
 */
void InitIGPIO(void)
{
    /* Eingänge */
    pinMode(PIN_SWC_IN1, INPUT);
    pinMode(PIN_SWC_IN2, INPUT);
    pinMode(PIN_SWC_IN3, INPUT);

    /* Ausgänge */
    /*pinMode(PIN_K3, OUTPUT);
    pinMode(PIN_K4, OUTPUT);
    pinMode(PIN_K5, OUTPUT);*/
    pinMode(PIN_SWC_OUT1, OUTPUT);
    pinMode(PIN_SWC_OUT2, OUTPUT);
    pinMode(PIN_SWC_OUT3, OUTPUT);
    pinMode(PIN_DIGIPOT_CS, OUTPUT);
}

/*
 * Hier sollte etwas stehen
 */
void ReadSteeringWheelControl(void)
{
    /* Zustand 1 - Mute, Source+ oder Source- */
    digitalWrite(PIN_SWC_OUT1, HIGH);
    delayMicroseconds(DIGITAL_DELAY_TIME);
    g_car_data[SWC_ROTARY_SWITCH_1] = digitalReadFast(PIN_SWC_IN1);
    g_car_data[SWC_ROTARY_SWITCH_1] = digitalReadFast(PIN_SWC_IN2);
    g_car_data[SWC_ROTARY_SWITCH_3] = digitalReadFast(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT1, LOW);
    delayMicroseconds(DIGITAL_DELAY_TIME);
    
    /* Zustand 2 - Vol-, Vol+ oder Skip */
    digitalWrite(PIN_SWC_OUT2, HIGH);
    delayMicroseconds(DIGITAL_DELAY_TIME);
    g_car_data[SWC_VOl_UP] = digitalReadFast(PIN_SWC_IN1);
    g_car_data[SWC_VOl_DOWN] = digitalReadFast(PIN_SWC_IN2);
    g_car_data[SWC_SKIP] = digitalReadFast(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT2, LOW);
    delayMicroseconds(DIGITAL_DELAY_TIME);

    /* Zustand 3 - Drehknopf */
    digitalWrite(PIN_SWC_OUT3, HIGH);
    delayMicroseconds(DIGITAL_DELAY_TIME);
    g_car_data[SWC_MUTE] = digitalReadFast(PIN_SWC_IN1);
    g_car_data[SWC_SOURCE_UP] = digitalReadFast(PIN_SWC_IN2);
    g_car_data[SWC_SOURCE_DOWN] = digitalReadFast(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT3, LOW);
    delayMicroseconds(DIGITAL_DELAY_TIME);

#ifdef DEBUG
    if (memcmp(g_car_data, g_car_data_last, SIZE_OF_CAR_DATA) != 0)
    {
        Serial.print("SWC_MUTE =            ");
        Serial.println(g_car_data[SWC_MUTE]);
        Serial.print("SWC_SOURCE_UP =       ");
        Serial.println(g_car_data[SWC_SOURCE_UP]);
        Serial.print("SWC_SOURCE_DOWN =     ");
        Serial.println(g_car_data[SWC_SOURCE_DOWN]);
        Serial.print("SWC_VOl_UP =          ");
        Serial.println(g_car_data[SWC_VOl_UP]);
        Serial.print("SWC_VOl_DOWN =        ");
        Serial.println(g_car_data[SWC_VOl_DOWN]);
        Serial.print("SWC_SKIP =            ");
        Serial.println(g_car_data[SWC_SKIP]);
        Serial.print("SWC_ROTARY_SWITCH_1 = ");
        Serial.println(g_car_data[SWC_ROTARY_SWITCH_1]);
        Serial.print("SWC_ROTARY_SWITCH_2 = ");
        Serial.println(g_car_data[SWC_ROTARY_SWITCH_2]);
        Serial.print("SWC_ROTARY_SWITCH_3 = ");
        Serial.println(g_car_data[SWC_ROTARY_SWITCH_3]);
    }
#endif
}

/*
 * Hier sollte etwas stehen
 */
void ReadHuPowerConsumption(void)
{
    //g_car_data[HU_CURRENT_CONSUMPTION] = analogRead(PIN_HU_CURRENT);
}

/*
 * Hier sollte etwas stehen
 */
void HandleSteeringWheelControl(void)
{
    uint8_t _number_of_keys_pressed = NumberOfKeysPressed();

    if (memcmp(g_car_data, g_car_data_last, SIZE_OF_CAR_DATA) != 0)
    {
        if (_number_of_keys_pressed > 0 && _number_of_keys_pressed <= 2)
        {
            if (_number_of_keys_pressed == 1)
            {
                if (g_car_data[SWC_MUTE])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_MUTE - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_SOURCE_UP])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_SOURCE_UP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_SOURCE_DOWN])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_SOURCE_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_VOl_UP])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_VOl_UP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_VOl_DOWN])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_VOl_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_SKIP])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_SKIP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data[SWC_VOl_DOWN])
                {
                    digiPot.setWiper(((DIGI_POT_RESISTANCE_VOl_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    return;
                }

                if (g_car_data_last[SWC_ROTARY_SWITCH_1])
                {
                    if (g_car_data[SWC_ROTARY_SWITCH_2])
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    else
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_UP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    return;
                }

                if (g_car_data_last[SWC_ROTARY_SWITCH_2])
                {
                    if (g_car_data[SWC_ROTARY_SWITCH_3])
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    else
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_UP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    return;
                }

                if (g_car_data_last[SWC_ROTARY_SWITCH_3])
                {
                    if (g_car_data[SWC_ROTARY_SWITCH_1])
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_DOWN - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    else
                    {
                        digiPot.setWiper(((DIGI_POT_RESISTANCE_ROTARY_SWITCH_UP - DIGI_POT_WIPER_RESISTANCE) / DIGI_POT_MAX_RESISTANCE) * 255);
                    }
                    return;
                }
            }
        }
        else
        {
            digiPot.shutdownMode();
        }
    }
}

/*
 * Ermittelt die Anzahl betätigter Tasten und gibt diese zurück.
 */
uint8_t NumberOfKeysPressed(void)
{
    uint8_t x = 0;

    for (size_t i = 0; i < SWC_ROTARY_SWITCH_3 + 1; i++)
    {
        x += g_car_data[i];
    }
    
    return x;
}

/*
 * Hier sollte etwas stehen
 */
void SetCarDataLast(void)
{
    memcpy(g_car_data_last, g_car_data, SIZE_OF_CAR_DATA);
}