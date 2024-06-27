#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPL6aVFnqzua"
#define BLYNK_TEMPLATE_NAME "JUMAAT"
#define BLYNK_AUTH_TOKEN    "2v0jgOZt4mbrRNZp06grbdGzlXPiFlPE"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{ Blynk.run();
}

