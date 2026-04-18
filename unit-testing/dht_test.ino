#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT22 Test");
}

void loop() {
  delay(2000); // DHT22 needs 2 sec between readings
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // if (isnan(h) || isnan(t)) {
  //   Serial.println("Failed to read from DHT22! Check wiring.");
  //   return;
  // }

  Serial.print("Humidity: ");    Serial.print(h);    Serial.println(" %");
  Serial.print("Temperature: "); Serial.print(t);    Serial.println(" C");
}