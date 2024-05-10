#include <Wire.h>
#include "MAX30102_PulseOximeter.h"

const int trigPin = 10; // Trigger pin of ultrasonic sensor
const int echoPin = 8;  // Echo pin of ultrasonic sensor
const int buzzerPin = 7; // Buzzer pin
const int REPORTING_PERIOD_MS = 500;
unsigned long tsLastReport = 0; 

PulseOximeter pox;

String checkPosture() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send 10 microsecond pulse to trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of pulse on echo pin
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  if (distance > 100)
    return "check the sensor";

  if (distance >= 15) {
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(100); // Beep for 100 milliseconds
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
    return "False";
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
    return "True";
  }
}

void onBeatDetected() {}

void setup() {
    Serial.begin(115200);

    pinMode(trigPin, OUTPUT); // Set trigger pin as output
    pinMode(echoPin, INPUT);  // Set echo pin as input
    pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output

    while (!pox.begin()) {
        Serial.println("check the sensor\tcheck the sensor\tcheck the sensor");
    }

    pox.setIRLedCurrent(125);
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    pox.update();

    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print(pox.getHeartRate());
        Serial.print('\t');
        Serial.print(pox.getSpO2());
        Serial.print('\t');
        Serial.println(checkPosture());
        tsLastReport = millis();
    }
}
