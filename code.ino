#include "Arduino.h"
#include "DCMDriverL298.h"
#include "DHT.h"

// Pin Definitions

#define motorA1 3
#define motorA2 4
#define motorB1 7
#define motorB2 8
#define DHT_DATA 9
#define Line1 10
#define Line2 11
#define MQ2 A3
int buzzer = 2;

// object initialization
DHT dht(DHT_DATA);

int sensorThres = 400;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Line1, INPUT);
  pinMode(Line2, INPUT);
  
  dht.begin();
  
  Serial.begin(9600);  
}

void loop() {
float dhtHumidity = dht.readHumidity();
float dhtTempC = dht.readTempC();

if(dhtTempC > 50)
  {
  digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
   tone(buzzer, 1000);
    delay(500);      
   noTone(buzzer);  
    delay(500);
  }

float MQ2_State = analogRead(MQ2);

if (MQ2_State > sensorThres)
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
  tone(buzzer, 1000, 200);
    delay(500);      
   noTone(buzzer);  
    delay(500);
  }

 if(digitalRead(Line1) && digitalRead(Line2))     // Move Forward
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(mot*orB1, HIGH);
    digitalWrite(motorB2, LOW);
  }
  
  if(!(digitalRead(Line1)) && digitalRead(Line2))     // Turn right
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
  }
  
  if(digitalRead(Line1) && !(digitalRead(Line2)))     // turn left
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
  }
  
  if(!(digitalRead(Line1)) && !(digitalRead(Line2)))     // stop
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
  }
