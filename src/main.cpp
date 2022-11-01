#include <Arduino.h>

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 10;
const int ENB = 11;
const int TIME_TO_WAIT_BEFORE_STARTING = 20;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  for(int i = 0; i < TIME_TO_WAIT_BEFORE_STARTING; i++) {
    Serial.print("Starting session in ");
    Serial.print(TIME_TO_WAIT_BEFORE_STARTING - i);
    Serial.println(" seconds...");
    delay(1000);
  }
  Serial.println("Session started");
}

void loop() {
  //control speed 
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  //control direction 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
