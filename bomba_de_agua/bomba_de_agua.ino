/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David alvizuris perez
Seccion: A
Carne: 2022041
*/
#define sensor 5
#define bomba 4 
#define vacio 3
#define lleno 2
void setup() {
 pinMode(sensor, INPUT);
 pinMode(bomba, OUTPUT);
 pinMode(vacio, OUTPUT);
 pinMode(lleno, OUTPUT);
}
void loop() {
int estado;
estado = digitalRead(sensor);
if (estado == HIGH){
digitalWrite(vacio, HIGH);
digitalWrite(lleno, LOW);
digitalWrite(bomba, HIGH);
}
estado = digitalRead(sensor);
if (estado == LOW){
digitalWrite(vacio, LOW);
digitalWrite(lleno, HIGH);
digitalWrite(bomba, LOW);
delay(1000);
} 
}
