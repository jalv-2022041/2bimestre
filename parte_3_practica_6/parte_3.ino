//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trig 17
#define echo 16
#define song 15
int d;
float Si = 494.883;
LiquidCrystal_I2C LCD_ALV(direccion_lcd, columnas, filas);//constructor
void setup()
{
  Serial.begin(9600);
  for(int i=2; i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(song ,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  LCD_ALV.init();
  LCD_ALV.backlight();
}
void loop()
{
  Serial.println(d);
  medicion();
  alerta();
}
int medicion(){
  long t; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(50);
  return d;
}
void alerta(){
   if( d > 45){
    LCD_ALV.setCursor(0,0);
    LCD_ALV.print("FUERA DE ALCANCE");
    LCD_ALV.setCursor(0,1);
    LCD_ALV.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      noTone(song);
  }
  if( d < 45 && d > 30){
    LCD_ALV.setCursor(0,0);
    LCD_ALV.print(" ACERCANDOSE A  ");
    LCD_ALV.setCursor(0,1);
    LCD_ALV.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      noTone(song);
  }
  if( d < 30 && d > 15){
    LCD_ALV.setCursor(0,0);
    LCD_ALV.print("   PRECAUCION   ");
    LCD_ALV.setCursor(0,1);
    LCD_ALV.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(song, 494);
      delay(1000);
      noTone(song);
  }    
  if( d < 15 && d >= 0){
    LCD_ALV.setCursor(0,0);
    LCD_ALV.print("   INVADIENDO   ");
    LCD_ALV.setCursor(0,1);
    LCD_ALV.print("ESPACIO PRIVADO ");
    digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(song, 494);
      delay(10000);
      noTone(song);
  }
  else {
  noTone(song);
  }
  }
