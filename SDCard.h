
#ifndef SDCARDCOMPONENT_H
#define SDCARDCOMPONENT_H

#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>
#include <Arduino.h>

//PIN CONNECTIONS
// chipSelectPin -> 10 Digital  
// mosiPin -> 11 Digital
// misoPin -> 12 Digital
// clockPin -> 13 Digital

class SDCardComponent
{
 private:
  int chipSelectPin;
  int mosiPin;
  int misoPin;
  int clockPin;

 public:
   SDCardComponent(int cs, int mosi, int miso, int clk);

  // Function to save a string to the file
  void SaveDataToFile(String fileName, String data);

  String TimeStringBuilder(DateTime currentDateTime);

  String FormatTwoDigits(int number);

  // Function to initialize SD Card module if needed
  void InitializeSDCard();
};

#endif
