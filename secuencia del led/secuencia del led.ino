//Fundación Kinal
//Centro Educativo Técnico Labral Kinal 
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Josué David Alvizuris Pérez
//Carné: 2022041 
int entrada=3;
#define i
void setup() {
for(entrada;entrada<=12;entrada++){
  {
    pinMode(entrada, OUTPUT);
  }
}
}
void loop() {
  entrada=3;
  for(i;entrada<=12;entrada++){
    digitalWrite(entrada, HIGH);
    delay(500);
    digitalWrite(entrada, LOW);
    }
   entrada=12;
  for(i;entrada>=3;entrada--){
    digitalWrite(entrada, HIGH);
    delay(500);
    digitalWrite(entrada, LOW);
}
}
