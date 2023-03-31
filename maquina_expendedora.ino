/*Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josue David Alivuzis Perez
Seccion: A
Carne: 2022041*/
#define arriva 4
#define abajo 3
int i = 1;
struct item{
  unsigned int preciou;
  unsigned int stock;
  String nombre;
  unsigned int bodega;
  float precio_l;};
item Coca;
item hershey;
item papas;
item can_can;
void setup(){
  Serial.begin(9600);
  pinMode(arriva, INPUT);
  pinMode(abajo, INPUT);
  Coca.preciou = 12;
  Coca.stock = 5;
  Coca.nombre = "Coca-Cola";
  Coca.bodega = 34;
  Coca.precio_l = (Coca.preciou*23);  // matematicas de Coca
  hershey.preciou = 5;
  hershey.stock = 15;
  hershey.nombre = "hershey original";
  hershey.bodega = 29;
  hershey.precio_l = (hershey.preciou*11);//matematicas de hershey
  papas.preciou = 5;
  papas.stock = 20;
  papas.nombre = "papas lays";
  papas.bodega = 19;
  papas.precio_l = (papas.preciou*15);//matematicas de papas
  can_can.preciou = 2;
  can_can.stock = 7;
  can_can.nombre = "Can Can original";
  can_can.bodega = 29;
  can_can.precio_l = (can_can.preciou*5.5); }//matematicas de can_can
void loop(){
  int producto = i;
  if (digitalRead(arriva) == 0){     i++;     }
  else if (digitalRead(abajo)==0){
     i--;     }
  else if ( i < 1){
    i = 4;    }
  else if ( i > 4){
    i = 1;    }
if (producto == 1){
  Serial.println("Producto no.1: ");
  Serial.println(Coca.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Coca.preciou);
  Serial.print("Stock: ");
  Serial.println(Coca.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(Coca.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Coca.precio_l);
  Serial.println("-------------------------");//texto de coca
  delay(2000);}
if (producto == 2){
  Serial.println("Producto no.2: ");
  Serial.println(hershey.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(hershey.preciou);
  Serial.print("Stock: ");
  Serial.println(hershey.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(hershey.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(hershey.precio_l);
  Serial.println("-------------------------");//texto de chocolate
  delay(2000);}
if (producto == 3){
  Serial.println("Producto no.3: ");
  Serial.println(papas.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(papas.preciou);
  Serial.print("Stock: ");
  Serial.println(papas.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(papas.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(papas.precio_l);
  Serial.println("-------------------------");//texto de papas
  delay(2000);}
if (producto == 4){
  Serial.println("Producto no.4: ");
  Serial.println(can_can.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(can_can.preciou);
  Serial.print("Stock: ");
  Serial.println(can_can.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(can_can.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(can_can.precio_l);
  Serial.println("-------------------------");//texto de galleta
  delay(2000);  
}else if ( producto > 4){
  i = 1;
  loop();}
  else if ( producto < 1){
  i = 4;
  } }
