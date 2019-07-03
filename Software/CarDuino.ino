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

#include "communication.h"
#include "gpio.h"

#define DEBUG



const char CARDUINO_WELCOME[] = "CarDuino";
const char CARDUINO_VERSION[] = "Version: 0.1";
const char CARDUINO_CREATED[] = "Created: 03.07.2019 18:44:27";
const char CARDUINO_AUTHOR[] = "Author:  J.Schiller";

void setup()
{

#ifdef DEBUG
    CAR_SERIAL_BEGIN(115200);
    CAR_PRINT_MSG(CARDUINO_WELCOME);
    CAR_PRINT_MSG(CARDUINO_VERSION);
    CAR_PRINT_MSG(CARDUINO_CREATED);
    CAR_PRINT_MSG(CARDUINO_AUTHOR);
    CAR_PRINT_MSG();
    CAR_PRINT_MSG("Verbindung hergestellt...");
    CAR_PRINT_MSG();
#endif // DEBUG

    InitIO();
    InitCommunication();

}

void loop()
{
    

}