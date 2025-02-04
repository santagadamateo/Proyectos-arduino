#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo s;
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
const int Led = A0;  //Pin digital 10 para el Led 

long Vled;
long Vmotor;

void setup() {
  pinMode(Led, OUTPUT);    // Azul
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  s.attach(9);
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {

long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  
  if (d < 20) {
    Vmotor = map(d,2,20,0,180); 
    s.write(Vmotor);
  }
  Vled = map(d,2,20,255,1);
  Serial.print("led=");
  Serial.println(Vled);
  analogWrite(Led,Vled);
  
}
