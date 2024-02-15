
#ifndef TEMPERATURECOMPONENT_H
#define TEMPERATURECOMPONENT_H

#include <OneWire.h>
#include <DallasTemperature.h>

#include <math.h>

//PIN CONNECTIONS
// temperaturePin -> 2  Digital

class TemperatureComponent 
{
 public:
  int temperaturePin;   // Arduino Pin
  OneWire oneWire;
  DallasTemperature temperatureSensor;
 
 public:
  TemperatureComponent(int tempPin);

  // Function to read temperature in celsius
  float ReadTemperature();

  // Function to initialize temperature sensor
  void InitializeTemperatureSensor();
};
#endif
