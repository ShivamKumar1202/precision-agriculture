
#ifndef SOILMOISTURECOMPONENT_H
#define SOILMOISTURECOMPONENT_H

#include <Arduino.h>
#include <math.h>

// PIN CONNECTIONS
// moisturePin -> A0 Analog
class SoilMoistureComponent 
{
	
 private:
  int moisturePin;             // Arduino Pin (A0)
  const int dryValue = 960;    // Define the dry value for calibration
  const int wetValue = 720;    // Define the wet value for calibration
 
 
 public:
  SoilMoistureComponent(int moisturePin);

  // Function to read soil moisture and calculate percentage
  float ReadMoisture();

};

#endif