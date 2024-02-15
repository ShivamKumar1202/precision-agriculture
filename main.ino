#include "LCD.h"
#include "RTC.h"
#include "SDCard.h"
#include "Temperature.h"
#include "SoilMoisture.h"

SoilMoistureComponent soilMoisture(A0); 
TemperatureComponent temperatureSensor(2);
SDCardComponent sdCard(10, 11, 12, 13);   // Initialize the SD Card with the digital pins 
RTCComponent rtc;
LCDComponent lcd(0x26, 16, 2);

// Run the looping code after every 'updateTime' milliseconds
const int updateTime = 60 * 60 * 1000;  //minute * second * millisecond

const String fileName = "dataFile.txt";

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  temperatureSensor.InitializeTemperatureSensor();
  
  rtc.InitializeRTC();
  lcd.InitializeLCD();
  
  sdCard.InitializeSDCard();
  sdCard.SaveDataToFile(fileName, "TimeStamp, Temperature(C), Moisture(%)");

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  static unsigned long lastUpdateTime = 0;
  unsigned long currentTime = millis();
  
  if(currentTime - lastUpdateTime >= updateTime)
  {
    float mVal = soilMoisture.ReadMoisture();
    Serial.println(mVal);

    float tVal = temperatureSensor.ReadTemperature();
    //Serial.println(tVal);

    DateTime currentDateTime = rtc.GetCurrentDateTime();

    String dateTimeString = sdCard.TimeStringBuilder(currentDateTime);

    //Serial.println(dateTimeString);
    lcd.UpdateLCD(tVal, mVal);

    String data = ToPrintSD(dateTimeString, tVal, mVal);
    //Serial.println(data);

    sdCard.SaveDataToFile(fileName, data);

    lastUpdateTime = currentTime;
  }

}

// Returns a string to be printed to the file
String ToPrintSD(String timeStamp, float temperature, float moisture )
{
  String data = timeStamp + ", " + temperature + ", " + moisture;

  return data;
}
