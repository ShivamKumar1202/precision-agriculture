
#include "LCD.h"


LCDComponent::LCDComponent(int address, int columns, int rows) : lcd(address, columns, rows) {}

  void LCDComponent::InitializeLCD() 
  {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
  }

  void LCDComponent::UpdateLCD(float temperature, int moisture)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Moisture:");
    lcd.print(moisture);
  }
