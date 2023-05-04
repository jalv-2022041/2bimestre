//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger 17
#define echo 16
int d;
int distancia;//Directivas de preprocesador
LiquidCrystal_I2C ALV_LCD(direccion_lcd, columnas, filas);//Constructor
byte espacioo[] = {
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110
};
void setup()
{
  Serial.begin(9600);
  for(int i=2; i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  ALV_LCD.init();
  ALV_LCD.backlight();
  ALV_LCD.createChar(1, espacioo);
}
void loop()
{
  Serial.println(d);
  medicion();
   distancia = d;
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
   if( distancia == 50){    
    ALV_LCD.setCursor(0,0);
    ALV_LCD.print("                ");
    ALV_LCD.setCursor(0,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(7,0);
    ALV_LCD.print("50");
    ALV_LCD.setCursor(13,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("     LIBRE      ");
  }
  if( distancia == 30){
    ALV_LCD.setCursor(0,0);
    ALV_LCD.print("                ");
    ALV_LCD.setCursor(0,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(7,0);
    ALV_LCD.print("30");
    ALV_LCD.setCursor(11,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("     CUIDADO    ");
  }
  if( distancia == 10){
    ALV_LCD.setCursor(0,0);
    ALV_LCD.print("                ");
    ALV_LCD.setCursor(0,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(7,0);
    ALV_LCD.print("10");
    ALV_LCD.setCursor(9,0);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.write(1);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("      ALTO      ");
  }
  }
