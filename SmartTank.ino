#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const int trigPin1 = D1;
const int echoPin1 = D2;
#define redled D3
#define grnled D4
unsigned long ch_no =  1887208;//Replace with Thingspeak Channel number
const char * write_api = "SB88QUJJ7PH2UHQZ";//Replace with Thingspeak write API
char auth[] = "mwa0000027854876";
char ssid[] = "GeoStone1";
char pass[] = "1234567890";
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 10000;
WiFiClient  client;
long duration1;
int distance1;
void setup()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(grnled, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(redled, LOW);
  digitalWrite(grnled, LOW);
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  startMillis = millis();  //initial start time
}
void loop()
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.println(distance1);
  if (distance1 <= 5 )
  {
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    Serial.println("Stop ! water has reached the required level...");
    delay(500);
  }
  else
  {
    digitalWrite(D4, HIGH);
    digitalWrite(D3, LOW);
    delay(500);
  }
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    ThingSpeak.setField(1, distance1);
    ThingSpeak.writeFields(ch_no, write_api);
    startMillis = currentMillis;
  }
}