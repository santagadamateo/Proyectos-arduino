#include <Servo.h> // Incluimos la biblioteca Servo

Servo servo;  // Definimos los servos que vamos a utilizar
long valor;
 long valor2;
 
void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Inicio de sketch - valores del potenciometro");
 servo.attach(7);

}
 
void loop() {
  // leemos del pin A0 valor
  valor = analogRead(A0);
  valor2 = map(valor, 0, 1023, 0, 180);
 
  //Imprimimos por el monitor serie
  Serial.print("El valor es = ");
  Serial.println(valor);
  servo.write(valor2);

  delay(1000);
 
}
