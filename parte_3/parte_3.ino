#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C


//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger 4
#define echo 3
#define alarma 2
int d;
//Constructor
LiquidCrystal_I2C LCD_Alv(direccion_lcd, columnas, filas);


void setup()
{
  Serial.begin(9600);
  for(int i=2; i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(alarma ,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Alv.init();
  LCD_Alv.backlight();
}


void loop()
{
  Serial.println(d);
  medicion();
  alerta();
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(50);
  return d;
}
void alerta(){
   if( d > 45){
    LCD_Alv.setCursor(0,0);
    LCD_Alv.print("FUERA DE ALCANCE");
    LCD_Alv.setCursor(0,1);
    LCD_Alv.print("ESPACIO PRIVADO ");
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
      digitalWrite(alarma, LOW);
  }
  if( d < 45 && d > 30){
    LCD_Alv.setCursor(0,0);
    LCD_Alv.print(" ACERCANDOSE A  ");
    LCD_Alv.setCursor(0,1);
    LCD_Alv.print("ESPACIO PRIVADO ");
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
      digitalWrite(alarma, LOW);
  }
  if( d < 30 && d > 15){
    LCD_Alv.setCursor(0,0);
    LCD_Alv.print("   PRECAUCION   ");
    LCD_Alv.setCursor(0,1);
    LCD_Alv.print("ESPACIO PRIVADO ");
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
      digitalWrite(alarma, HIGH);
    delay(5000);
    digitalWrite(alarma, LOW);
  }
    
    
  if( d < 15 && d > 0){
    LCD_Alv.setCursor(0,0);
    LCD_Alv.print("   INVADIENDO   ");
    LCD_Alv.setCursor(0,1);
    LCD_Alv.print("ESPACIO PRIVADO ");
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
    digitalWrite(alarma, HIGH);
    delay(10000);
    digitalWrite(alarma, LOW);
      }
      else {
        digitalWrite(alarma, LOW);
        }
  }
