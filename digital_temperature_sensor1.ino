// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int temperaturePin = 0; //Declaring temperature pin
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2); //Setup for LCD 16x2
}

void loop()
{
lcd_1.clear(); //Clearing the screen of LCD
int reading = analogRead(temperaturePin);  //storing value of temperature in "reading" variable
  
float voltage = reading * 5.0;
voltage /= 1024.0; 
float temperatureC = (voltage - 0.5) * 100 ; //Calculations to determine value of temperature in celsius
lcd_1.setCursor(0,1); // Staring sentence at coloumn 0 and row 1 of the LCD
lcd_1.print(temperatureC);
lcd_1.println(" degrees C ");
delay(100); // Delay to improve simulation
}