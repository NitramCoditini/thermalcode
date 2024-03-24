#include <DHT.h>

#define DHTPIN 5    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true); // Read temperature in Fahrenheit

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float heatIndexF = dht.computeHeatIndex(temperatureF, humidity);

  // Compute heat index in Celsius (isFahreheit = false)
  float heatIndexC = dht.computeHeatIndex(temperatureC, humidity, false);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C ");
  Serial.print(temperatureF);
  Serial.print(" °F\t");
  Serial.print("Heat index: ");
  Serial.print(heatIndexC);
  Serial.print(" °C ");
  Serial.print(heatIndexF);
  Serial.println(" °F");
}
