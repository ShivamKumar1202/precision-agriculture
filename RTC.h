
#ifndef RTCCOMPONENT_H
#define RTCCOMPONENT_H

#include <Wire.h>
#include <RTClib.h>

// PIN CONNECTIONS I2C
// SDA -> A4
// SCL -> A5

class RTCComponent 
{ 
 private:
  RTC_DS3231 rtc;

 public:
  
  // Function to initialize RTC
  // Run SetTime from DS1307RTC beforehand
  void InitializeRTC();
  

  // Function to get the current date and time
  DateTime GetCurrentDateTime();
  
};

#endif
