

#include <Wire.h>
#include <Time.h>
#include <TimeLib.h> //Esta libreria la agrego para que funcione el "tmElements_t tm"
#include <DS1307RTC.h>

#define CLK 9
#define DIO 8

TM1637 Display1(CLK, DIO);
  int8_t Digitos[] = {0,1,2,3};
  int horas;
  int minutos;
  boolean alterna;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");

  Display1.set();
  Display1.init();
  
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();

    horas = tm.Hour;
    minutos = tm.Minute;
    CalculaDigitos(horas, minutos);
    if (alterna)
      {
        Display1.point(POINT_OFF);
        alterna = false;
      }
      else
      {
        Display1.point(POINT_ON);
        alterna = true;
      }
    
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void CalculaDigitos( int hor, int minu)
   {
      int8_t Digit0 = minu %10 ;
      int8_t Digit1 = (minu % 100) / 10 ;
      int8_t Digit2 = hor % 10 ;
      int8_t Digit3 = (hor % 100) / 10 ;

      Digitos[3] = Digit0 ;
      Digitos[2] = Digit1 ;
      Digitos[1] = Digit2 ;
      Digitos[0] = Digit3 ;

      Display1.display(Digitos);
   }
