
#include "SoilMoisture.h"


SoilMoistureComponent::SoilMoistureComponent(int moisturePin) : moisturePin(moisturePin) {}


float SoilMoistureComponent::ReadMoisture() 
{
	float sensorValue = analogRead(A0);

	// float moisturePercentage = map(sensorValue, wetValue, dryValue, 100, 0);

  // moisturePercentage = round(moisturePercentage * 100.0) / 100.0;   // round to 2 decimal places
	
	// moisturePercentage = constrain(moisturePercentage, 0, 100);

  //Serial.println(moisturePercentage);
  Serial.println(sensorValue);
  
	
	return sensorValue;
}

