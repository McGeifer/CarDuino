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

#include "digital_poti.h"
#include "communication.h"
#include "gpio.h"
#include "string.h"

#define DEBUG

const char CARDUINO_WELCOME[] = "CarDuino";
const char CARDUINO_VERSION[] = "Version: 0.1";
const char CARDUINO_CREATED[] = "Created: 03.07.2019 18:44:27";
const char CARDUINO_AUTHOR[] = "Author:  J.Schiller";

enum ECarData
{
    SWC_OUT1_IN1,
    SWC_OUT1_IN2,
    SWC_OUT1_IN3,
    SWC_OUT2_IN1,
    SWC_OUT2_IN2,
    SWC_OUT2_IN3,
    SWC_OUT3_IN1,
    SWC_OUT3_IN2,
    SWC_OUT3_IN3,
    HU_POWER_CONSUMPTION,
    SIZE_OF_CAR_DATA
};

enum ERemoteControlStatus
{
    
};

int16_t g_car_data[SIZE_OF_CAR_DATA] = {};
int16_t g_car_data_last[SIZE_OF_CAR_DATA] = {};

void setup()
{
    CAR_SERIAL_BEGIN(115200);
    CAR_SERIAL_PRINT_MSG(CARDUINO_WELCOME);
    CAR_SERIAL_PRINT_MSG(CARDUINO_VERSION);
    CAR_SERIAL_PRINT_MSG(CARDUINO_CREATED);
    CAR_SERIAL_PRINT_MSG(CARDUINO_AUTHOR);
    CAR_SERIAL_PRINT_MSG();
    CAR_SERIAL_PRINT_MSG("Verbindung hergestellt...");
    CAR_SERIAL_PRINT_MSG();

    InitIO();
    InitCommunication();
}

void loop()
{
    ReadSteeringWheelControl();
    ReadHuPowerConsumption();
    HandleSteeringWheelControl();
    //HeadUnit();
    //Display();
    SetCarDataLast();
}

void ReadSteeringWheelControl(void)
{
    /* Zustand 1 - Mute, Source+ oder Source- */
    digitalWrite(PIN_SWC_OUT1, HIGH);
    g_car_data[SWC_OUT1_IN1] = digitalRead(PIN_SWC_IN1);
    g_car_data[SWC_OUT1_IN2] = digitalRead(PIN_SWC_IN2);
    g_car_data[SWC_OUT1_IN3] = digitalRead(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT1, LOW);

    /* Zustand 2 - Vol-, Vol+ oder Skip */
    digitalWrite(PIN_SWC_OUT2, HIGH);
    g_car_data[SWC_OUT2_IN1] = digitalRead(PIN_SWC_IN1);
    g_car_data[SWC_OUT2_IN2] = digitalRead(PIN_SWC_IN2);
    g_car_data[SWC_OUT2_IN3] = digitalRead(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT2, LOW);

    /* Zustand 3 - Drehknopf */
    digitalWrite(PIN_SWC_OUT3, HIGH);
    g_car_data[SWC_OUT3_IN1] = digitalRead(PIN_SWC_IN1);
    g_car_data[SWC_OUT3_IN2] = digitalRead(PIN_SWC_IN2);
    g_car_data[SWC_OUT3_IN3] = digitalRead(PIN_SWC_IN3);
    digitalWrite(PIN_SWC_OUT3, LOW);
}

void ReadHuPowerConsumption(void)
{
    g_car_data[HU_POWER_CONSUMPTION] = analogRead(PIN_HU_CURRENT);
}

void HandleSteeringWheelControl(void)
{
    // Test für Digitalpotentiometer

}

void SetCarDataLast(void)
{
    for (size_t i = 0; i < SIZE_OF_CAR_DATA; i++)
    {
        g_car_data_last[i] = g_car_data[i];
    }
}