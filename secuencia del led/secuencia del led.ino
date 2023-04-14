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
