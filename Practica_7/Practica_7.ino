//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
//Librerias
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h> 
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
//Directivas
#define btn1 8
#define btn2 9
#define btn3 7
#define luminaria1 14
#define luminaria2 15
#define Cantidad_Leds 7
#define pin_Led 6
#define RadarPin 16
#define pin_Servo 5
#define buzzer 13
#define R 10
#define G 11
#define B 12
int personacerca =0;
int value;
int estado1 = 0;
int estado2 = 0;
// Constructor
Adafruit_NeoPixel rueda(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
//Caracteres
byte puerta_cerrada[] = {
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111,
  B11111
};
byte puerta_entreabierta[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_media[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_abierta[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte luz_off[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B01110
};
byte luz_on[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};
byte Centigrados[] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011
};
byte persona_detectada[] = {
  B01000,
  B11100,
  B00000,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
byte persona_nodetec[] = {
  B10100,
  B01000,
  B10100,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
float medicion();
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensor(&ourWire); //Se declara una objeto para nuestro sensor
LiquidCrystal_I2C ALV_LCD(0x27, 16, 2);
Servo Servo_ALV; 
float temperatura;


void setup() {
  
  Servo_ALV.attach(pin_Servo);
  pinMode(RadarPin, INPUT);
  rueda.begin();
  pinMode(luminaria1, OUTPUT);
  pinMode(luminaria2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
sensor.begin(); 
ALV_LCD.init(); 
ALV_LCD.backlight(); 
 ALV_LCD.createChar(1, puerta_abierta);
 ALV_LCD.createChar(2, puerta_media);
 ALV_LCD.createChar(3, puerta_cerrada);
 ALV_LCD.createChar(4, luz_off);
 ALV_LCD.createChar(5, luz_on);
 ALV_LCD.createChar(6, Centigrados);
 ALV_LCD.createChar(7, persona_detectada);
 ALV_LCD.createChar(8, persona_nodetec);
 ALV_LCD.setCursor(0,1);
  ALV_LCD.print("Puerta:");
  ALV_LCD.setCursor(9,1);
    ALV_LCD.print("Luz 2");
    ALV_LCD.write(5);
    ALV_LCD.setCursor(9,0);
    ALV_LCD.print("Luz 1");
    ALV_LCD.write(4);
    Servo_ALV.write(0);
 }
 
void loop() {
  value = digitalRead(RadarPin);
  luminarias();
  puerta();
  temperatura = medicion();
  luminarias();
  puerta();
ALV_LCD.setCursor(0,0);
ALV_LCD.print(temperatura);
ALV_LCD.write(6);
luminarias();
puerta();
proximidad();
luminarias();
puerta();
condicion_temp();
luminarias();
puerta();
}

float medicion(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("Temperatura= ");
  Serial.print(temp);
  Serial.println(" C");
  delay(100);  
  return temp;
  }
void proximidad(){  
  if( value == LOW){
    ALV_LCD.setCursor(7,0);
    ALV_LCD.write(8);
     for(int i = 0; i < 7; i++){
      rueda.setPixelColor(i,rueda.Color(0,255,0));
          rueda.show();
          delay(50);
          rueda.setPixelColor(i,rueda.Color(0,40,10));
          rueda.show();
          delay(50);
      }
    }   
  if(value == HIGH){
    ALV_LCD.setCursor(7,0);
    ALV_LCD.write(7);
    digitalWrite(buzzer, HIGH);
    for(int i = 0; i < 7; i++){
      rueda.setPixelColor(i,rueda.Color(255,0,0));
          rueda.show();
          delay(50);
          rueda.setPixelColor(i,rueda.Color(40,10,0));
          rueda.show();
          delay(50); 
    }
    digitalWrite(buzzer, LOW);
    }if(personacerca == 0){
     
}
}
void luminarias(){
if(digitalRead(btn1) && estado1==0){  // si pulsador presionado y led apagado
    digitalWrite(luminaria1, LOW);          // se enciende el led 
    
    ALV_LCD.setCursor(9,0);
    ALV_LCD.print("Luz 1");
    ALV_LCD.write(5);
    delay(300);
    estado1=1;                       // guardamos el estado encendido   
  } 
  if(digitalRead(btn1) && estado1==1){  // si pulsador presionado y led encendido

    digitalWrite(luminaria1, HIGH);           // se apaga el led 
    
    ALV_LCD.setCursor(9,0);
    ALV_LCD.print("Luz 1");
    ALV_LCD.write(4);
    delay(300); 
    estado1=0;                       // guardamos el estado apagado   
  }
  if(digitalRead(btn2) && estado2==0){  // si pulsador presionado y led apagado
    digitalWrite(luminaria2, LOW);          // se enciende el led 
    
    ALV_LCD.setCursor(9,1);
    ALV_LCD.print("Luz 2");
    ALV_LCD.write(5); 
    delay(300);
    estado2=1;                       // guardamos el estado encendido   
  } 
  if(digitalRead(btn2) && estado2==1){  // si pulsador presionado y led encendido

    digitalWrite(luminaria2, HIGH);           // se apaga el led 
    
    ALV_LCD.setCursor(9,1);
    ALV_LCD.print("Luz 2");
    ALV_LCD.write(4); 
    delay(300);
    estado2=0;                       // guardamos el estado apagado   
  }
}
void puerta(){
  if(digitalRead(btn3)==HIGH){
  Servo_ALV.write(90);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(3);
    delay(100);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(2);
    delay(100);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(1); 
    delay(2000);
    Servo_ALV.write(0);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(1);
    delay(100);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(2);
    delay(100);
    ALV_LCD.setCursor(0,1);
    ALV_LCD.print("Puerta:");
    ALV_LCD.write(3);
    delay(1000); 
    Servo_ALV.write(0);
  } else{
    Servo_ALV.write(0);
    }
}
void condicion_temp(){
if(temperatura > 15 && temperatura <= 21){
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
}
if(temperatura > 21 && temperatura <= 25){
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(B, LOW);
}
if(temperatura > 25 && temperatura < 45){
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
}
