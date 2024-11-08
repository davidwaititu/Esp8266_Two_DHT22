/*
 * This ESP8266 NodeMCU code was developed by newbiely.com
 *
 * This ESP8266 NodeMCU code is made available for public use without any restriction
 *
 * For comprehensive instructions and wiring diagrams, please visit:
 * https://newbiely.com/tutorials/esp8266/esp8266-dht22
 */

#include <DHT.h>

#define DHT_PIN_SENSOR_1  4  // The ESP8266 pin 4 connected to DHT22 sensor 1
#define DHT_PIN_SENSOR_2  5  // The ESP8266 pin 5 connected to DHT22 sensor 2
#define DHT_SENSOR_TYPE   DHT22

DHT dht_sensor_1(DHT_PIN_SENSOR_1, DHT_SENSOR_TYPE);
DHT dht_sensor_2(DHT_PIN_SENSOR_2, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(115200);
  dht_sensor_1.begin(); // Initialize the first DHT sensor
  dht_sensor_2.begin(); // Initialize the second DHT sensor
}

void readAndPrintDHTData(DHT &sensor, const char *sensorName) {
  // Read humidity
  float humi = sensor.readHumidity();
  // Read temperature in Celsius
  float temperature_C = sensor.readTemperature();
  // Read temperature in Fahrenheit
  float temperature_F = sensor.readTemperature(true);

  // Check if the readings are successful
  if (isnan(temperature_C) || isnan(temperature_F) || isnan(humi)) {
    Serial.print("Failed to read from ");
    Serial.print(sensorName);
    Serial.println(" sensor!");
  } else {
    Serial.print(sensorName);
    Serial.print(" - Humidity: ");
    Serial.print(humi);
    Serial.print("%  |  Temperature: ");
    Serial.print(temperature_C);
    Serial.print("°C ~ ");
    Serial.print(temperature_F);
    Serial.println("°F");
  }
}

void loop() {
  Serial.println("Reading data from sensors...");

  // Read and print data for the first sensor
  readAndPrintDHTData(dht_sensor_1, "Sensor 1");

  // Read and print data for the second sensor
  readAndPrintDHTData(dht_sensor_2, "Sensor 2");

  // Wait 2 seconds between readings
  delay(2000);
}
