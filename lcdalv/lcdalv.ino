#include <LiquidCrystal.h>
#define RS  6
#define Enable 7
#define D4 5
#define D5 4
#define D6 3
#define D7 2
LiquidCrystal LCD_Alvizuris(RS, Enable, D4, D5, D6, D7);
void setup()
{
  LCD_Alvizuris.begin(16,2);
  LCD_Alvizuris.setCursor(0,0); 
  LCD_Alvizuris.print("Josue Alvizuris");
  LCD_Alvizuris.setCursor(0,1);
  LCD_Alvizuris.print("2022041");
}
void loop(){
  }
