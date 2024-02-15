
#include "SDCard.h"

SDCardComponent::SDCardComponent(int cs, int mosi, int miso, int clk) : 
  chipSelectPin(cs),
  mosiPin(mosi),
  misoPin(miso),
  clockPin(clk) {}


  void SDCardComponent::InitializeSDCard() 
  {
    if (!SD.begin(chipSelectPin)) 
    {
      Serial.println("SD Card initialization failed!");
      return;
    }
    else
    {
      Serial.println("SD Card initialized.");
    }

  }

  void SDCardComponent::SaveDataToFile(String fileName, String data) 
  {
    File dataFile = SD.open(fileName, FILE_WRITE);
    
    if (dataFile) 
    {
      dataFile.println(data);
      dataFile.close();
      //Serial.println("Data saved to SD Card.");
    } 
	else 
    {
      Serial.println("Error opening data file.");
    }
  }

  String SDCardComponent::TimeStringBuilder(DateTime currentDateTime)
  {
    String dateTimeString = 
      String(currentDateTime.year())            +  "-"  +
      FormatTwoDigits(currentDateTime.month())  +  "-"  +
      FormatTwoDigits(currentDateTime.day())    +  "T"  +
      FormatTwoDigits(currentDateTime.hour())   +  ":"  +
      FormatTwoDigits(currentDateTime.minute()) +  ":"  +
      FormatTwoDigits(currentDateTime.second());

    return dateTimeString;

  }

  String SDCardComponent::FormatTwoDigits(int number)
  {
    if(number < 10)
      return "0" + String(number);
    
    else
      return String(number);
  }
  
