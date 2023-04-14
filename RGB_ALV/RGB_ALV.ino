//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
#define RG1 3
#define GB1 4
#define R 5
#define G 6
#define B 7
void setup() {
   Serial.begin(9600);
  pinMode(RG1, INPUT);
  pinMode(GB1, INPUT);
   pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}
void loop() {
  int RG;
  RG = digitalRead (RG1);
  int GB;
  GB = digitalRead (GB1);
     
  if (RG==1 && GB == 0 ){
  digitalWrite(R,HIGH);
  digitalWrite(G,HIGH);
  delay(500);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  }
    if (RG==0 && GB == 1 ){
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
  delay(500);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
    }
      if ( RG==1 && GB == 1 ){
  digitalWrite(R,HIGH);
  digitalWrite(B,HIGH);
  delay(500);
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
      }
        if (RG==0 && GB == 0 ) {  
  digitalWrite(B,LOW);
  digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  delay(500);
  digitalWrite(R,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(B,LOW);
  delay(500);
  digitalWrite(G,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(R,LOW);
  delay(500);
  }
}
