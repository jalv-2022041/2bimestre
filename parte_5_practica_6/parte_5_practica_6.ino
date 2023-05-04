#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C ALV_LCD(direccion_lcd, columnas, filas);
OneWire ourWire(14);
DallasTemperature sensors(&ourWire);
byte customChar1[] = {
 B00100,
  B00100,
  B00100,
  B00100,
  B01110,
  B01010,
  B01010,
  B01110
};
byte customChar2[] = {
  B11000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
void setup()
{
  Serial.begin(9600);
  ALV_LCD.init();
  ALV_LCD.backlight();
  ALV_LCD.createChar(1, customChar1);
  ALV_LCD.createChar(2, customChar2);
sensors.begin();
}
void loop()
{
  sensors.requestTemperatures();
float temp= sensors.getTempCByIndex(0);
float temp1 = sensors.getTempFByIndex(0);
  ALV_LCD.setCursor(0,0);
  ALV_LCD.print("   TERMOMETRO");
  ALV_LCD.write(1);
  ALV_LCD.setCursor(0,1);
  ALV_LCD.print("G");
  ALV_LCD.setCursor(1,1);
  ALV_LCD.write(2);
  ALV_LCD.setCursor(2,1);
  ALV_LCD.print(" ");
  ALV_LCD.setCursor(3,1);
  ALV_LCD.print(temp);
  ALV_LCD.setCursor(9,1);
  ALV_LCD.print("F");  
  ALV_LCD.setCursor(10,1);
  ALV_LCD.write(2);
  ALV_LCD.setCursor(11,1);
  ALV_LCD.print(" ");
  ALV_LCD.setCursor(12,1);
  ALV_LCD.print(temp1);
}
  
 
