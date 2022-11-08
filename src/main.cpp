#include <Arduino.h>

const int IN1 = 7;
const int IN2 = 6;
const int ENA = 10;
const int TIME_TO_WAIT_BEFORE_STARTING = 20;
const long TREATMENT_DELAY_FOR_EACH_HAND = 600000;
const int REFERENCE_VOLTAGE = 12;

int outputVoltage = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  for(int i = 0; i < TIME_TO_WAIT_BEFORE_STARTING; i++) {
    Serial.print("Starting session in ");
    Serial.print(TIME_TO_WAIT_BEFORE_STARTING - i);
    Serial.println(" seconds...");
    delay(1000);
  }
  ///////////////////// session started /////////////////////
  Serial.println("Session started");
  digitalWrite(LED_BUILTIN, HIGH);
  ///////////////////// treat first hand /////////////////////
  Serial.println("Started treating first hand");
  // control direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // increment speed gradually
  for(int i = 0; i < 255; i++) {
    outputVoltage = (i * REFERENCE_VOLTAGE) / 255;
    Serial.print("Voltage: ");
    Serial.print(outputVoltage);
    Serial.print(" V  |  PWM: ");
    Serial.println(i);
    analogWrite(ENA, i);
    delay(500);
  }
  Serial.print("Treating first hand for ");
  Serial.print((TREATMENT_DELAY_FOR_EACH_HAND / 1000) / 60);
  Serial.println(" minutes...");
  delay(TREATMENT_DELAY_FOR_EACH_HAND);
  // decrement speed gradually
  for(int i = 255; i < 0; i--) {
    outputVoltage = (i * REFERENCE_VOLTAGE) / 255;
    Serial.print("Voltage: ");
    Serial.print(outputVoltage);
    Serial.print(" V  |  PWM: ");
    Serial.println(i);
    analogWrite(ENA, i);
    delay(300);
  }
  Serial.println("Finished treating first hand");
  ///////////////////// treat second hand /////////////////////
  Serial.println("Started treating second hand");
  // control direction
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // increment speed gradually
  for(int i = 0; i < 255; i++) {
    outputVoltage = (i * REFERENCE_VOLTAGE) / 255;
    Serial.print("Voltage: ");
    Serial.print(outputVoltage);
    Serial.print(" V  |  PWM: ");
    Serial.println(i);
    analogWrite(ENA, i);
    delay(500);
  }
  Serial.print("Treating second hand for ");
  Serial.print((TREATMENT_DELAY_FOR_EACH_HAND / 1000) / 60);
  Serial.println(" minutes...");
  delay(TREATMENT_DELAY_FOR_EACH_HAND);
  // decrement speed gradually
  for(int i = 255; i < 0; i--) {
    outputVoltage = (i * REFERENCE_VOLTAGE) / 255;
    Serial.print("Voltage: ");
    Serial.print(outputVoltage);
    Serial.print(" V  |  PWM: ");
    Serial.println(i);
    analogWrite(ENA, i);
    delay(300);
  }
  Serial.println("Finished treating second hand");
  ///////////////////// session ended /////////////////////
  Serial.println("Session ended");
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
}
