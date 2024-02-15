
#ifndef LCDCOMPONENT_H
#define LCDCOMPONENT_H

#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// PIN CONNECTIONS I2C
// SDA -> A4
// SCL -> A5

class LCDComponent 
{
 private:
  LiquidCrystal_I2C lcd;

 public:

  LCDComponent(int address, int columns, int rows);
  
  // Function to initialize the LCD
  void InitializeLCD(); 
  
  // Function to update LCD screen
  void UpdateLCD(float temperature, int moisture);
};

#endif