#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPL6aVFnqzua"
#define BLYNK_TEMPLATE_NAME "JUMAAT"
#define BLYNK_AUTH_TOKEN    "2v0jgOZt4mbrRNZp06grbdGzlXPiFlPE"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define LED1  27
#define LED2  26
#define pinPB 32

BLYNK_WRITE(V0)
{ int pb1 = param.asInt();
  digitalWrite(LED1,pb1);
}
BLYNK_WRITE(V1)
{ int pb2 = param.asInt();
  digitalWrite(LED2,pb2);
}
void getInput()
{ int pb = digitalRead(pinPB);
  Serial.println(pb);
  if(pb==0) Blynk.virtualWrite(V3,"Pushed");
  if(pb==1) Blynk.virtualWrite(V3,"Idle");
}

void setup()
{ pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(pinPB,INPUT_PULLUP);

  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(10L,getInput);
}

void loop()
{ Blynk.run();
  timer.run();
}

