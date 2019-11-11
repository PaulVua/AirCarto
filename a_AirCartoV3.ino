/**************************************************************************
  Ecran 1.8'' 128x160 rgb_tft
  5V!!!
  SCL -> SCK(pin52)
  SDA -> MOSI(pin 51)

  SDS011 sur Serial 2 (5V)

  GPS sur SERIAL 3 (5V)

  BME280 connexion sur MEGA SDA>D20 et SCL>D21 alim 3v

  CCS811 Connexion sur le MEGA SDA>D20, SCL>D21 et WAK GND
  Alim 3,3V nécessite un temps d'adaptation (24/48H)

  module carte SD 
  MISO->D50, MOSI->D51, SCK->D52, CS->D53
  en 5V
 **************************************************************************/

//setup screen
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

 #define TFT_CS        11
 #define TFT_RST        7 // Or set to -1 and connect to Arduino RESET pin
 #define TFT_DC         9
  
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


//setup SDS011
#include <SDS011-select-serial.h>
float p10,p25;
int error;
SDS011 my_sds(Serial2);

//setup BME280
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;

//setup CCS811
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;

//pour le GPS on utilise la Librairie TinyGPS++
#include <TinyGPS++.h>
TinyGPSPlus tinyGPS;
HardwareSerial & ss = Serial3;

//setup pour le module carte SD
#include <SD.h>
File myFile;

#include <math.h>

//variable pour dessiner les lignes
int placeX = 41;
