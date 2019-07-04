EESchema Schematic File Version 4
LIBS:CarDuino-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L teensy:Teensy3.5 U?
U 1 1 5D1B0B38
P 13200 3550
F 0 "U?" H 13200 6027 60  0000 C CNN
F 1 "Teensy3.5" H 13200 5921 60  0000 C CNN
F 2 "" H 13100 5750 60  0000 C CNN
F 3 "" H 13200 5850 60  0000 C CNN
F 4 "https://www.pjrc.com/teensy/pinout.html" H 13200 5823 50  0000 C CNN "Pinouts"
	1    13200 3550
	1    0    0    -1  
$EndComp
$Comp
L CarDuino:AZDelivery_ACS712 U?
U 1 1 5D1DB42C
P 8550 4250
F 0 "U?" H 8550 3935 50  0000 C CNN
F 1 "AZDelivery_ACS712" H 8550 4026 50  0000 C CNN
F 2 "" H 8550 4500 50  0001 C CNN
F 3 "" H 8550 4500 50  0001 C CNN
	1    8550 4250
	-1   0    0    1   
$EndComp
Text GLabel 1000 1000 0    50   Input ~ 0
+12V
Text GLabel 1000 1200 0    50   Input ~ 0
ACC
Text GLabel 1000 6000 0    50   Input ~ 0
0V
Wire Wire Line
	1000 1200 1100 1200
$Comp
L relay-2x:RELAY-2X K1
U 1 1 5D1FCD1F
P 1850 5000
F 0 "K1" H 1728 5055 30  0000 L CNN
F 1 "RELAY-2X" H 1728 4995 30  0001 L CNN
F 2 "" H 1850 5000 60  0000 C CNN
F 3 "" H 1850 5000 60  0000 C CNN
	1    1850 5000
	1    0    0    -1  
$EndComp
$Comp
L relay-2x:RELAY-2X K1
U 2 1 5D200078
P 1850 2400
F 0 "K1" H 2216 2480 30  0000 L CNN
F 1 "RELAY-2X" H 2216 2420 30  0001 L CNN
F 2 "" H 1850 2400 60  0000 C CNN
F 3 "" H 1850 2400 60  0000 C CNN
	2    1850 2400
	1    0    0    -1  
$EndComp
$Comp
L relay-2x:RELAY-2X K2
U 2 1 5D201EDC
P 2350 2400
F 0 "K2" H 2716 2480 30  0000 L CNN
F 1 "RELAY-2X" H 2716 2420 30  0001 L CNN
F 2 "" H 2350 2400 60  0000 C CNN
F 3 "" H 2350 2400 60  0000 C CNN
	2    2350 2400
	1    0    0    -1  
$EndComp
$Comp
L relay-2x:RELAY-2X K3
U 2 1 5D203A4A
P 1850 3850
F 0 "K3" H 2216 3930 30  0000 L CNN
F 1 "RELAY-2X" H 2216 3870 30  0001 L CNN
F 2 "" H 1850 3850 60  0000 C CNN
F 3 "" H 1850 3850 60  0000 C CNN
	2    1850 3850
	1    0    0    -1  
$EndComp
$Comp
L CarDuino:tinxi_5A_75W_DC_DC_Step_down_Converter U?
U 1 1 5D209F1C
P 2500 5000
F 0 "U?" H 2500 5365 50  0000 C CNN
F 1 "tinxi_5A_75W" H 2500 5274 50  0000 C CNN
F 2 "" H 2500 5500 50  0001 C CNN
F 3 "" H 2500 5500 50  0001 C CNN
	1    2500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 6000 1500 6000
Wire Wire Line
	1500 5200 1500 6000
Connection ~ 1500 6000
Wire Wire Line
	1500 6000 2000 6000
Wire Wire Line
	2000 2550 2000 2750
Wire Wire Line
	2000 1950 2500 1950
Wire Wire Line
	2500 1950 2500 2150
Wire Wire Line
	2000 1950 2000 2150
Wire Wire Line
	2500 2550 2500 2750
Wire Wire Line
	2000 5100 2000 6000
$Comp
L relay-2x:RELAY-2X K2
U 1 1 5D220390
P 3850 5000
F 0 "K2" H 3728 5055 30  0000 L CNN
F 1 "RELAY-2X" H 3728 4995 30  0001 L CNN
F 2 "" H 3850 5000 60  0000 C CNN
F 3 "" H 3850 5000 60  0000 C CNN
	1    3850 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5200 3500 6000
Text GLabel 10250 1000 2    50   Input ~ 0
+12V
Text GLabel 10250 1200 2    50   Input ~ 0
ACC
Text Label 3000 4900 0    50   ~ 0
+5V
Wire Wire Line
	4000 4450 4000 6000
$Comp
L relay-2x:RELAY-2X K3
U 1 1 5D22DF52
P 4850 5000
F 0 "K3" H 4728 5055 30  0000 L CNN
F 1 "RELAY-2X" H 4728 4995 30  0001 L CNN
F 2 "" H 4850 5000 60  0000 C CNN
F 3 "" H 4850 5000 60  0000 C CNN
	1    4850 5000
	1    0    0    -1  
$EndComp
$Comp
L relay-2x:RELAY-2X K4
U 1 1 5D22FBD2
P 5850 5000
F 0 "K4" H 5728 5055 30  0000 L CNN
F 1 "RELAY-2X" H 5728 4995 30  0001 L CNN
F 2 "" H 5850 5000 60  0000 C CNN
F 3 "" H 5850 5000 60  0000 C CNN
	1    5850 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 5200 5500 6000
Wire Wire Line
	3000 5100 3000 6000
Wire Wire Line
	2000 5100 2200 5100
Wire Wire Line
	2000 4900 2200 4900
Wire Wire Line
	2000 2750 2500 2750
Wire Wire Line
	2000 4000 2000 4900
Wire Wire Line
	2000 2750 2000 3450
Wire Wire Line
	2000 3450 2150 3450
Wire Wire Line
	2150 3450 2150 3600
Connection ~ 2000 2750
Wire Wire Line
	9350 5450 9350 6000
Wire Wire Line
	9800 2850 9450 2850
Wire Wire Line
	9450 2850 9450 4550
Text GLabel 10300 6000 2    50   Input ~ 0
0V
Wire Wire Line
	4500 5200 4500 6000
Wire Wire Line
	4500 4750 4500 4450
Wire Wire Line
	4800 3500 4800 3550
$Comp
L Connector:Conn_01x06_Female J?
U 1 1 5D291F53
P 5250 2200
F 0 "J?" H 5150 2500 50  0001 L CNN
F 1 "Conn_01x06_Female" H 4500 2600 50  0001 L CNN
F 2 "" H 5250 2200 50  0001 C CNN
F 3 "~" H 5250 2200 50  0001 C CNN
	1    5250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2000 4200 2000
Wire Wire Line
	4200 2000 4200 3550
Wire Wire Line
	4300 3550 4300 2100
Wire Wire Line
	4300 2100 5050 2100
Wire Wire Line
	5050 2200 4400 2200
Wire Wire Line
	4400 2200 4400 3550
Wire Wire Line
	4500 3550 4500 2300
Wire Wire Line
	4500 2300 5050 2300
Wire Wire Line
	5050 2400 4600 2400
Wire Wire Line
	4600 2400 4600 3550
Wire Wire Line
	5050 2500 4700 2500
Wire Wire Line
	4700 2500 4700 3550
Wire Wire Line
	4800 4450 4800 4500
Text Notes 1500 6500 0    118  ~ 0
K1 - Standard 12V KFZ-Relais
Text Notes 1500 6750 0    118  ~ 0
K2 - K5 - SainSmart 4 Kanal RelaisModul 5V
$Comp
L Device:Fuse F1
U 1 1 5D1F9C61
P 1250 1200
F 0 "F1" V 1310 1246 50  0000 C TNN
F 1 "1A" V 1310 1155 50  0000 R TNN
F 2 "" V 1180 1200 50  0001 C CNN
F 3 "~" H 1250 1200 50  0001 C CNN
	1    1250 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1400 1200 1500 1200
Wire Wire Line
	1500 4750 1500 1200
Connection ~ 1500 1200
Wire Wire Line
	1000 1000 1100 1000
$Comp
L Device:Fuse F2
U 1 1 5D1FC308
P 1250 1000
F 0 "F2" V 1310 1046 50  0000 C TNN
F 1 "3A" V 1310 955 50  0000 R TNN
F 2 "" V 1180 1000 50  0001 C CNN
F 3 "~" H 1250 1000 50  0001 C CNN
	1    1250 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1400 1000 2000 1000
Wire Wire Line
	2000 1950 2000 1000
Connection ~ 2000 1950
$Comp
L CarDuino:Teensy3.5 U?
U 1 1 5D22B598
P 4400 4000
F 0 "U?" H 3950 4050 50  0000 L CNN
F 1 "Teensy3.5" H 3950 3950 50  0000 L CNN
F 2 "" H 4400 4350 50  0001 C CNN
F 3 "" H 4400 4350 50  0001 C CNN
	1    4400 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4250 5000 4250
Wire Wire Line
	5000 3500 4800 3500
$Comp
L Connector:Conn_01x06_Male J?
U 1 1 5D30CFD1
P 5250 2200
F 0 "J?" H 4950 1750 50  0001 C CNN
F 1 "Conn_01x06_Male" H 5050 1500 50  0001 C CNN
F 2 "" H 5250 2200 50  0001 C CNN
F 3 "~" H 5250 2200 50  0001 C CNN
	1    5250 2200
	1    0    0    -1  
$EndComp
Text GLabel 10250 1400 2    50   Input ~ 0
+5V
Wire Wire Line
	4000 3550 4000 1400
Wire Wire Line
	3500 1400 4000 1400
Connection ~ 3500 1400
Wire Wire Line
	3500 4750 3500 1400
Wire Wire Line
	3000 4900 3000 1400
Wire Wire Line
	3000 1400 3500 1400
Connection ~ 4000 1400
Wire Wire Line
	2800 4900 3000 4900
Wire Wire Line
	2800 5100 3000 5100
$Comp
L Switch:SW_Push Mute
U 1 1 5D1C8181
P 5850 3500
F 0 "Mute" V 5804 3648 50  0000 L CNN
F 1 "SW_Push" V 5895 3648 50  0000 L CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "~" H 5850 3700 50  0001 C CNN
	1    5850 3500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Skip
U 1 1 5D1C8A00
P 7500 2700
F 0 "Skip" V 7454 2848 50  0000 L CNN
F 1 "SW_Push" V 7545 2848 50  0000 L CNN
F 2 "" H 7500 2900 50  0001 C CNN
F 3 "~" H 7500 2900 50  0001 C CNN
	1    7500 2700
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Source+
U 1 1 5D1C9647
P 6400 3500
F 0 "Source+" V 6354 3648 50  0000 L CNN
F 1 "SW_Push" V 6445 3648 50  0000 L CNN
F 2 "" H 6400 3700 50  0001 C CNN
F 3 "~" H 6400 3700 50  0001 C CNN
	1    6400 3500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Drehknopf_3
U 1 1 5D1C977F
P 8550 2900
F 0 "Drehknopf_3" H 8550 3185 50  0000 C CNN
F 1 "SW_Push" H 8550 3094 50  0000 C CNN
F 2 "" H 8550 3100 50  0001 C CNN
F 3 "~" H 8550 3100 50  0001 C CNN
	1    8550 2900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push Vol-
U 1 1 5D1CA16B
P 6400 2700
F 0 "Vol-" V 6354 2848 50  0000 L CNN
F 1 "SW_Push" V 6445 2848 50  0000 L CNN
F 2 "" H 6400 2900 50  0001 C CNN
F 3 "~" H 6400 2900 50  0001 C CNN
	1    6400 2700
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Vol+
U 1 1 5D1CA708
P 6950 2700
F 0 "Vol+" V 6904 2848 50  0000 L CNN
F 1 "SW_Push" V 6995 2848 50  0000 L CNN
F 2 "" H 6950 2900 50  0001 C CNN
F 3 "~" H 6950 2900 50  0001 C CNN
	1    6950 2700
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Source-
U 1 1 5D1CAED6
P 6950 3500
F 0 "Source-" V 6904 3648 50  0000 L CNN
F 1 "SW_Push" V 6995 3648 50  0000 L CNN
F 2 "" H 6950 3700 50  0001 C CNN
F 3 "~" H 6950 3700 50  0001 C CNN
	1    6950 3500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push Drehknopf_2
U 1 1 5D1CB2CA
P 8550 2500
F 0 "Drehknopf_2" H 8550 2785 50  0000 C CNN
F 1 "SW_Push" H 8550 2694 50  0000 C CNN
F 2 "" H 8550 2700 50  0001 C CNN
F 3 "~" H 8550 2700 50  0001 C CNN
	1    8550 2500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push Drehknopf_1
U 1 1 5D1CB7DA
P 8550 2100
F 0 "Drehknopf_1" H 8550 2385 50  0000 C CNN
F 1 "SW_Push" H 8550 2294 50  0000 C CNN
F 2 "" H 8550 2300 50  0001 C CNN
F 3 "~" H 8550 2300 50  0001 C CNN
	1    8550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 4300 9350 4550
Wire Wire Line
	9350 4200 9350 2550
Wire Wire Line
	5000 3500 5000 4250
Wire Wire Line
	5450 2000 5750 2000
Wire Wire Line
	5750 2000 5750 1600
Wire Wire Line
	5750 1600 8850 1600
Wire Wire Line
	8850 1600 8850 2100
Wire Wire Line
	8850 2100 8750 2100
Wire Wire Line
	8850 2100 8850 2500
Wire Wire Line
	8850 2500 8750 2500
Connection ~ 8850 2100
Wire Wire Line
	8850 2500 8850 2900
Wire Wire Line
	8850 2900 8750 2900
Connection ~ 8850 2500
Wire Wire Line
	5450 2100 5850 2100
Wire Wire Line
	8250 2200 8250 2500
Wire Wire Line
	8250 2500 8350 2500
Wire Wire Line
	8150 2300 8150 2900
Wire Wire Line
	8150 2900 8350 2900
Wire Wire Line
	5450 2500 5550 2500
Wire Wire Line
	5550 2500 5550 3700
Wire Wire Line
	5450 2400 5650 2400
Wire Wire Line
	5650 2400 5650 2900
Wire Wire Line
	5450 2200 5950 2200
Wire Wire Line
	5450 2300 6050 2300
Wire Wire Line
	5550 3700 5850 3700
Connection ~ 6400 2900
Wire Wire Line
	5650 2900 6400 2900
Wire Wire Line
	6400 2900 6950 2900
Connection ~ 5850 3700
Connection ~ 6400 3700
Wire Wire Line
	5850 3700 6400 3700
Wire Wire Line
	6400 3700 6950 3700
Wire Wire Line
	6950 2900 7500 2900
Connection ~ 6950 2900
Wire Wire Line
	6400 2500 6400 2200
Connection ~ 6400 2200
Wire Wire Line
	6400 2200 8250 2200
Wire Wire Line
	6950 2500 6950 2100
Connection ~ 6950 2100
Wire Wire Line
	6950 2100 8350 2100
Wire Wire Line
	7500 2500 7500 2300
Connection ~ 7500 2300
Wire Wire Line
	7500 2300 8150 2300
Wire Wire Line
	5850 3300 5850 2100
Connection ~ 5850 2100
Wire Wire Line
	5850 2100 6950 2100
Wire Wire Line
	6400 3300 6400 3200
Wire Wire Line
	6400 3200 5950 3200
Wire Wire Line
	5950 3200 5950 2200
Connection ~ 5950 2200
Wire Wire Line
	5950 2200 6400 2200
Wire Wire Line
	6950 3300 6950 3100
Wire Wire Line
	6950 3100 6050 3100
Wire Wire Line
	6050 3100 6050 2300
Connection ~ 6050 2300
Wire Wire Line
	6050 2300 7500 2300
Text Notes 8000 3700 0    50   ~ 0
Lenkradfernbedienung
Text Label 5450 2000 0    50   ~ 0
BN
Text Label 5450 2100 0    50   ~ 0
BU
Text Label 5450 2200 0    50   ~ 0
YE
Text Label 5450 2300 0    50   ~ 0
GN
Text Label 5450 2400 0    50   ~ 0
RD
Text Label 5450 2500 0    50   ~ 0
BK
Wire Notes Line
	5300 1500 8950 1500
Wire Notes Line
	8950 1500 8950 3800
Wire Notes Line
	8950 3800 5300 3800
Wire Notes Line
	5300 3800 5300 1500
Connection ~ 2000 1000
Connection ~ 2000 6000
Connection ~ 3000 6000
Connection ~ 3500 6000
Connection ~ 4000 6000
Connection ~ 4500 6000
Connection ~ 5500 6000
Wire Wire Line
	4000 6000 4500 6000
Wire Wire Line
	2000 6000 3000 6000
Wire Wire Line
	3500 6000 4000 6000
Wire Wire Line
	3000 6000 3500 6000
Wire Wire Line
	4500 6000 5500 6000
Connection ~ 9350 6000
Wire Wire Line
	9350 6000 10300 6000
Wire Wire Line
	5500 6000 6500 6000
Text Label 4700 2500 0    50   ~ 0
LFB_OUT1
Text Label 4700 2400 0    50   ~ 0
LFB_OUT2
Text Label 4700 2300 0    50   ~ 0
LFB_OUT3
Text Label 4700 2000 0    50   ~ 0
LFB_IN1
Text Label 4700 2100 0    50   ~ 0
LFB_IN2
Text Label 4700 2200 0    50   ~ 0
LFB_IN3
$Comp
L CarDuino:Joying U?
U 1 1 5D242C5F
P 9750 5000
F 0 "U?" H 10278 5046 50  0000 L CNN
F 1 "Joying" H 10278 4955 50  0000 L CNN
F 2 "" H 9750 5550 50  0001 C CNN
F 3 "" H 9750 5550 50  0001 C CNN
	1    9750 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 4500 10050 4550
Wire Wire Line
	4800 4500 10050 4500
Wire Wire Line
	8900 4200 9350 4200
Wire Wire Line
	8900 4300 9350 4300
Wire Wire Line
	4000 1400 10250 1400
Wire Wire Line
	4600 4700 5500 4700
Wire Wire Line
	4600 4450 4600 4700
Wire Wire Line
	5500 4700 5500 4750
$Comp
L relay-2x:RELAY-2X K5
U 1 1 5D2078B4
P 6850 5000
F 0 "K5" H 6728 5025 30  0000 L CNN
F 1 "RELAY-2X" H 6728 4995 30  0001 L CNN
F 2 "" H 6850 5000 60  0000 C CNN
F 3 "" H 6850 5000 60  0000 C CNN
	1    6850 5000
	1    0    0    -1  
$EndComp
$Comp
L relay-2x:RELAY-2X K5
U 2 1 5D208ABA
P 9200 2400
F 0 "K5" H 9566 2450 30  0000 L CNN
F 1 "RELAY-2X" H 9566 2420 30  0001 L CNN
F 2 "" H 9200 2400 60  0000 C CNN
F 3 "" H 9200 2400 60  0000 C CNN
	2    9200 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2150 9500 1000
Wire Wire Line
	4700 4450 4700 4600
Wire Wire Line
	4700 4600 6500 4600
Wire Wire Line
	6500 4600 6500 4750
Wire Wire Line
	6500 5200 6500 6000
Connection ~ 6500 6000
Wire Wire Line
	6500 6000 9350 6000
Connection ~ 9500 1000
Wire Wire Line
	9500 1000 10250 1000
Wire Wire Line
	2000 1000 9500 1000
Wire Wire Line
	1500 1200 9800 1200
Wire Wire Line
	9800 1200 9800 2850
Connection ~ 9800 1200
Wire Wire Line
	9800 1200 10250 1200
$EndSCHEMATC
