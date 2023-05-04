#include <LiquidCrystal.h>
float Si = 494.883;
#define song 10
#define echo 9
#define trigger 8
#define E 7
#define RS  6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
int gente = 0;
int d;
int i;
LiquidCrystal Lcd_Alvizuris (RS,E,D4,D5,D6,D7);

byte customChar1[] = {
  B01110,
  B01110,
  B01110,
  B00101,
  B01110,
  B10100,
  B01010,
  B11011
};
byte customChar2[] = {
  B01110,
  B01110,
  B01110,
  B10100,
  B01110,
  B00101,
  B01010,
  B11011
};
void setup() {
  Lcd_Alvizuris.begin(16, 2);
  Lcd_Alvizuris.clear();
  Lcd_Alvizuris.createChar(1, customChar1);
  Lcd_Alvizuris.createChar(2, customChar2);
   Serial.begin(9600);
   pinMode(song, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Lcd_Alvizuris.setCursor(0,0);
   Lcd_Alvizuris.print("PERSONAS:");
   digitalWrite(song, LOW);
}
void loop(){
  Serial.println(d);
  medicion();
  personas();
  
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delay(100); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(500);
  return d;
}
 void personas(){
    if((d >= 6) && (d < 10)){
      if(gente <= 15){
    gente++;
    int avance = gente -1;
    Lcd_Alvizuris.setCursor(avance, 1);
    Lcd_Alvizuris.write(1);
    delay(10);
    Lcd_Alvizuris.write(1);
    Serial.print("personas: ");
    Serial.println(gente);
    delay(500);}
    if( gente >= 16){
    exceso();
      }
    }
    }
void exceso(){
      tone(song, 494); //si
      Lcd_Alvizuris.setCursor(0,0);
      Lcd_Alvizuris.print("CAPACIDAD MAXIMA");
      Lcd_Alvizuris.setCursor(0,1);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);//animacion1
      delay(500);
      Lcd_Alvizuris.setCursor(0,1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1);
      Lcd_Alvizuris.write(2);
      Lcd_Alvizuris.write(1); //animacion 2
      delay(500);
}    
