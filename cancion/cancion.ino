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
    tone(song, 262); //Do
    }
    if(d == 10){
    tone(song, 277);//Do Sostenido
    }
    if(d == 15){
    tone(song, 294);//Re
    }
    if(d == 20){
    tone(song, 311);//Re Sostenido
    }
    if(d == 25){
    tone(song, 330);//Mi
    }
    if(d == 30){
    tone(song, 349);//Fa
    }
    if(d == 35){
    tone(song, 370);//Fa Sostenido
    }
    if(d == 40){
    tone(song, 392);//Sol
    }
    if(d == 45){
    tone(song, 415);//Sol Sostenido
    }
    if(d == 50){
    tone(song, 440);//La
    }
    if(d == 55){
    tone(song, 446);//La Sostenido
    }
    if(d == 60){
    tone(song, 494); //Sol
    }
    else{
      delay(400);
    noTone(song);
    }
    }
