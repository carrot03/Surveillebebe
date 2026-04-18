#include <Wire.h>
#include <MAX30105.h>

MAX30105 particleSensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 NOT FOUND - check wiring!");
    while (1);
  }
  
  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x0A);
  particleSensor.setPulseAmplitudeIR(0x0A);
  Serial.println("MAX30102 OK - place finger on sensor");
}

void loop() {
  Serial.print("IR=");
  Serial.print(particleSensor.getIR());
  Serial.print("  RED=");
  Serial.println(particleSensor.getRed());
  delay(500);
}