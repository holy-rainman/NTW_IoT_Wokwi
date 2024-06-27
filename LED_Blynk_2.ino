#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPL6aVFnqzua"
#define BLYNK_TEMPLATE_NAME "JUMAAT"
#define BLYNK_AUTH_TOKEN    "2v0jgOZt4mbrRNZp06grbdGzlXPiFlPE"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define LED1  27
#define LED2  26

BLYNK_WRITE(V0)
{ int pb1 = param.asInt();
  digitalWrite(LED1,pb1);
}
BLYNK_WRITE(V1)
{ int pb2 = param.asInt();
  digitalWrite(LED2,pb2);
}

void setup()
{ pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{ Blynk.run();
}

