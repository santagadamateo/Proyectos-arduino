#include <WiFiScan.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiSTA.h>
#include <WiFiGeneric.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <ETH.h>
#include <WiFiMulti.h>
#include <WiFiUdp.h>


#include <Blynk.h>

#define BLYNK_PRINT Serial

int pin        = 5;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "RVF7sVapfMXfkZ0zKxedb49dIMMfutpX";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TeleCentro-c5a6";
char pass[] = "DZMWUDZKZDXA";

void setup() {  
  pinMode(pin, OUTPUT); 
  pinMode(pin, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  

  Blynk.begin("RVF7sVapfMXfkZ0zKxedb49dIMMfutpX", ssid, pass);

}

void loop(){
    Blynk.run();
}
