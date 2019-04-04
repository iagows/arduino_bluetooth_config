#include <SoftwareSerial.h>

SoftwareSerial bt(10,9);

void setup() {
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  bt.begin(38400);
}

void loop() {
  // Keep reading from HC-05 and send to Arduino
  // Serial Monitor
  if (bt.available())
    Serial.write(bt.read());

  // Keep reading from Arduino Serial Monitor
  //  and send to HC-05
  if (Serial.available())
    bt.write(Serial.read());
}
