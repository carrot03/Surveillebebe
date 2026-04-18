#define MQ2_ANALOG A9
#define MQ2_DIGITAL 4

void setup() {
  Serial.begin(9600);
  pinMode(MQ2_DIGITAL, INPUT);
  Serial.println("MQ-2 Test - Warming up...");
  delay(2000); // short warm up for testing
}

void loop() {
  int analogVal = analogRead(MQ2_ANALOG);
  int digitalVal = digitalRead(MQ2_DIGITAL);

  Serial.print("Analog: "); Serial.print(analogVal);
  Serial.print("  Digital: "); Serial.println(digitalVal);

  delay(500);
}