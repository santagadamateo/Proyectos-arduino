void setup() {
    pinMode(12, OUTPUT);    // Rojo
  pinMode(14, OUTPUT);     // Amarillo
  pinMode(13, OUTPUT);     // Verde
}

void loop() {
  digitalWrite(12, HIGH);
  delay(3000);
  digitalWrite(12, LOW);
  digitalWrite(14, HIGH);
  delay(1000);
  digitalWrite(14, LOW);
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(13, LOW);
  digitalWrite(14, HIGH);
  delay(1000);
  digitalWrite(14, LOW);
}
