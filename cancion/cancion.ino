//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
float distanciao = 261.626;
float distanciaoSos = 277.163;
float Re = 293.665;
float ReSos = 311.127;
float Mi = 329.628;
float Fa = 349.228;
float FaSos = 369.994;
float Sol = 391.995;
float SolSos = 415.305;
float La = 440;
float LaSos = 446.164;
float Si = 494.883;
#define song 2
#define tr 3
#define echo 4
long d;
void setup()    
{    
  Serial.begin(9600);
  pinMode(song, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  Serial.println(d);
  medicion();
  notas();
}
int medicion(){
  long t; 
  digitalWrite(tr, HIGH);
  delayMicroseconds(10); 
  digitalWrite(tr, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(500);
  return d;
}
  void notas(){
    if(d == 5){
    tone(song, 262);
    //delay(10);         //Do
    //noTone(song);
    }
    if(d == 10){
    tone(song, 277);
    //delay(10);        //Do Sostenido
    //noTone(song);
    }
    if(d == 15){
    tone(song, 294);
    //delay(10);         //Re
    //noTone(song);
    }
    if(d == 20){
    tone(song, 311);
    //delay(10);         //Re Sostenido
    //noTone(song);
    }
    if(d == 25){
    tone(song, 330);
    //delay(10);         //Mi
    //noTone(song);
    }
    if(d == 30){
    tone(song, 349);
    //delay(10);         //Fa
    //noTone(song);
    }
    if(d == 35){
    tone(song, 370);
    //delay(10);         //Fa Sostenido
    //noTone(song);
    }
    if(d == 40){
    tone(song, 392);
    //delay(10);         //Sol
    //noTone(song);
    }
    if(d == 45){
    tone(song, 415);
    //delay(10);         //Sol Sostenido
    //noTone(song);
    }
    if(d == 50){
    tone(song, 440);
    //delay(10);         //La
    //noTone(song);
    }
    if(d == 55){
    tone(song, 446);
    //delay(10);         //La Sostenido
    //noTone(song);
    }
    if(d == 60){
    tone(song, 494);
    //delay(10);         //Sol
    //noTone(song);
    }
    else{
      delay(400);
    noTone(song);
    }
    }
