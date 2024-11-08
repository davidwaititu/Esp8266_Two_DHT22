# ESP8266 with Two DHT22 Sensors

This project demonstrates how to use an ESP8266 NodeMCU to read temperature and humidity data from two DHT22 sensors. The code reads data from both sensors, then displays the readings via the Serial Monitor.

## Table of Contents
- [Overview](#overview)
- [Components](#components)
- [Wiring](#wiring)
- [Code Explanation](#code-explanation)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [License](#license)

## Overview
The ESP8266 NodeMCU reads data from two DHT22 sensors, displaying the temperature (in Celsius and Fahrenheit) and humidity for each sensor in the Serial Monitor. This setup is useful for applications that require temperature and humidity monitoring at different locations within a small space.

## Components
- ESP8266 NodeMCU
- 2x DHT22 sensors
- Jumper wires
- Breadboard (optional)

## Wiring
Here’s how to connect each component:
1. **DHT22 Sensor 1**
   - VCC to 3.3V on the ESP8266
   - GND to GND on the ESP8266
   - Data to GPIO4 (D2 on NodeMCU)

2. **DHT22 Sensor 2**
   - VCC to 3.3V on the ESP8266
   - GND to GND on the ESP8266
   - Data to GPIO5 (D1 on NodeMCU)

**Note**: Make sure to install a 10K pull-up resistor between the VCC and data lines of each DHT22 sensor to ensure stable readings.

## Code Explanation
The code reads temperature and humidity data from each sensor every two seconds and displays it in the Serial Monitor.

- `DHT dht_sensor_1` and `DHT dht_sensor_2` are used to initialize the two sensors connected to GPIO4 and GPIO5.
- The `readAndPrintDHTData()` function reads and prints humidity and temperature data from each sensor.
- The main `loop()` calls `readAndPrintDHTData()` for both sensors, separated by a 2-second delay.

### Code Snippet
```cpp
#include <DHT.h>

#define DHT_PIN_SENSOR_1  4  // GPIO4 for Sensor 1
#define DHT_PIN_SENSOR_2  5  // GPIO5 for Sensor 2
#define DHT_SENSOR_TYPE   DHT22

DHT dht_sensor_1(DHT_PIN_SENSOR_1, DHT_SENSOR_TYPE);
DHT dht_sensor_2(DHT_PIN_SENSOR_2, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(115200);
  dht_sensor_1.begin();
  dht_sensor_2.begin();
}

void loop() {
  // Read data from both sensors and print to Serial Monitor
}
