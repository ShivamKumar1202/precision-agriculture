
#include "Temperature.h"

  TemperatureComponent::TemperatureComponent(int tempPin) : 
    temperaturePin(tempPin), 
    oneWire(temperaturePin),
    temperatureSensor(&oneWire) {}


  void TemperatureComponent::InitializeTemperatureSensor() 
  {
    temperatureSensor.begin();
  }

  float TemperatureComponent::ReadTemperature() 
  {
    temperatureSensor.requestTemperatures();

    float tempReading = temperatureSensor.getTempCByIndex(0);

    if(tempReading == DEVICE_DISCONNECTED_C)
      return -1.0f;

    tempReading = round(tempReading * 100.0)/ 100.0;  // round to 2 decimal places

    return tempReading;
  }

