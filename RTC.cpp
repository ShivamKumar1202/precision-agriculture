
#include "RTC.h"

void RTCComponent::InitializeRTC() 
  {
    if (!rtc.begin()) 
    {
      Serial.println("Couldn't find RTC");
      return;
    }

    if (rtc.lostPower()) 
    {
      Serial.println("RTC lost power, let's set the time!");
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
  }

DateTime RTCComponent::GetCurrentDateTime()
{
	return rtc.now();
}

