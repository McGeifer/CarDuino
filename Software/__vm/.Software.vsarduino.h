/* 
	Editor: https://www.visualmicro.com/
			This file is for intellisense purpose only.
			Visual micro (and the arduino ide) ignore this code during compilation. This code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			The contents of the _vm sub folder can be deleted prior to publishing a project
			All non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			Note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Teensy 3.5, Platform=teensy3, Package=teensy
*/

#if defined(_VMICRO_INTELLISENSE)

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __HARDWARE_mk64fx512__
#define __HARDWARE_MK64FX512__
#define __MK64FX512__
#define TEENSYDUINO 146
#define ARDUINO 10807
#define F_CPU 120000000
#define USB_SERIAL
#define LAYOUT_US_ENGLISH
#define __cplusplus 201103L
#define __arm__
#define __ARM__
#define  __attribute__(x)
typedef void *__builtin_va_list;
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__(x)
#define __volatile__
#define NEW_H
#undef _WIN32
#define __STDC__ 
#define __GNUC__ 2
#define __GNUC_MINOR__ 5

extern int at_quick_exit(void (*f)(void));
int at_quick_exit(void (*f)(void)) {
}
extern int quick_exit(void (*f)(void));
int quick_exit(void (*f)(void)) {
}


#include "arduino.h"
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))



#define __disable_irq() __asm__ volatile("");
#define __enable_irq()	__asm__ volatile("");


#include "CarDuino.ino"
#endif
#endif
