//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
#define a 2
#define b 3
#define c 4
#define de 5
#define e 6
#define f 7
#define g 8
#define trigger 9
#define echo 10 
#define foco 12
long d;
int gente = -1; 
void setup() {
  Serial.begin(9600);
  for(int i = 2; i <=8; i++){
    pinMode(i,OUTPUT);
  } 
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(de, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(foco, OUTPUT);
  digitalWrite(trigger, LOW);
  
}
void loop(){
  Serial.println(d);
  Medicion();
  personas_maximas();
}
int Medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59; 
  delay(100);
  return d;
}
void personas_maximas(){
  if(d >= 6 && d <=10){
    gente = gente + 1;
    Serial.println(gente);
        switch(gente){
        case 0:
        digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    delay(100);
    
      break;
    case 1:
    digitalWrite(foco, HIGH);
      digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(500);
    break;
    case 2:   
    digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(de, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
      delay(500);
      break;
    case 3: 
    digitalWrite(foco, HIGH);
     digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  delay(500);
  break;
    case 4:
    digitalWrite(foco, HIGH);
      digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
     delay(500);
     break;
    case 5:   
    digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(de, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(500);
     break;
    case 6:
    digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(de, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(500);
    break;
    case 7:
    digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(500);
    break;
    case 8:
    digitalWrite(foco, HIGH);
      digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(500);
    break;    
    case 9:
    digitalWrite(foco, LOW);
      digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(de, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    Serial.println("Limite alcanzado");
    delay(500);
    break;  
        }
}
}
