#include <Key.h>
#include <Keypad.h>
//Incluyo la lbreria
//Defino el numero de filas y comlumnas del teclado matricial
//defino cada fila y columna con pines
#define Filas     4   
#define Columnas  4 
#define Fila1    2
#define Fila2    3
#define Fila3    4 
#define Fila4    5
#define Columna1 6
#define Columna2 7
#define Columna3 8
#define Columna4 9
//definr las leds del display
#define a 13
#define b 14
#define c 15
#define d 16
#define e 17
#define f 18
#define g 19

//defino las distribucion de teclas
char keys[Filas][Columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
  byte GFilas[Filas] = {Fila1,Fila2,Fila3,Fila4};
  byte GColumnas[Columnas] = {Columna1,Columna2,Columna3,Columna4};
  Keypad Teclado = Keypad( makeKeymap(keys),GFilas,GColumnas,Filas,Columnas);
void setup() { 
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
}

void loop() {
    char tecla = Teclado.getKey();
   //Tecla a
  if(tecla)
  switch (tecla){
  case ('1'):
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   delay(500);
   break;
   case ('2'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('3'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('4'):
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('5'):
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('6'):
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('7'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   delay(500);
   break;
   case ('8'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('9'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('0'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   delay(500);
   break;
  case ('A'):
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('B'): 
   digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('C'): 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   delay(500);
   break;
   case ('D'): 
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('#'): 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
   case ('*'): 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,LOW);
   digitalWrite(d,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   delay(500);
   break;
}
 else
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
}
