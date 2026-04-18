// Sound sensor test script
// Wiring:
// VCC -> 5V
// GND -> GND
// AO  -> A0
// DO  -> D2

const int soundAnalogPin = A9;   // Analog output from sensor
const int soundDigitalPin = 3;   // Digital output from sensor
const int ledPin = 5;           // Built-in LED on most Arduino boards

void setup() {
  Serial.begin(9600);

  pinMode(soundDigitalPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("Sound sensor test starting...");
  Serial.println("Make noise near the sensor and watch the values.");
  Serial.println("-----------------------------------------------");
}

void loop() {
  // Read sensor values
  int analogValue = analogRead(soundAnalogPin);
  int digitalValue = digitalRead(soundDigitalPin);

  // Print values to Serial Monitor
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print("    Digital Value: ");
  Serial.print(digitalValue);

  // LED indication based on digital output
  if (analogValue > 180) {
    digitalWrite(ledPin, HIGH);
    Serial.print("    --> Sound detected above threshold");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print("    --> Below threshold");
  }

  Serial.println();

  delay(200);
}