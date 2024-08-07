// Puertos    
                           // en esta parte se introducen las constantes
                            
const int SemVerde = 6;
const int SemAmarillo = 5;
const int SemRojo = 4;
const int PasoVerde = 3;
const int PasoRojo = 2;
const int botonPin = 7;


//Variables                                        // se introducen las variables                     
int botonState;


void setup(){                                      // se especifica cuales puertos son de salida
  pinMode(SemVerde, OUTPUT);
  pinMode(SemAmarillo, OUTPUT);
  pinMode(SemRojo, OUTPUT);
  pinMode(PasoRojo, OUTPUT);
  pinMode(PasoVerde, OUTPUT);
}


void loop(){
  botonState = digitalRead(botonPin);        // se identifica el botón
  if (botonState == LOW){                          // si no se presiona el semaforo esta en verde
    digitalWrite(SemVerde, HIGH);                   //y el de paso permanece en rojo
    digitalWrite(PasoRojo, HIGH);
  }else{                                                      // si se presiona el boton se apaga el sem. verde
    for (int i = 0; i < 3; i++){
      digitalWrite(SemVerde, LOW); 
      delay(500);
      digitalWrite(SemVerde, HIGH);            // el semaforo verde parpadea con frecuencia 5ms
      delay(500);
    }
    digitalWrite(SemVerde, LOW);
    digitalWrite(SemAmarillo, HIGH);
    delay(1000);
    digitalWrite(SemAmarillo, LOW);        // se apaga el semaforo verde, prende amarillo y 
    digitalWrite(SemRojo, HIGH);                   //parpadea por 1000 ms
    digitalWrite(PasoVerde, HIGH);          // prende sem. rojo y el de paso en verde
    digitalWrite(PasoRojo, LOW);
    delay(5000);
    digitalWrite(SemRojo, LOW);
    digitalWrite(PasoVerde, LOW);           // se apaga el semaforo rojo y el verde de paso
  }
}
