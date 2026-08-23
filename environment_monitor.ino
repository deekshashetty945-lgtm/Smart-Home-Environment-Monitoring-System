/*
  YuvaIntern Week 1 Task
  Smart Home Environment Monitoring System

  Hardware:
  - ESP32
  - DHT22 temperature/humidity sensor
  - MQ-135 air-quality sensor (analog)
  - LDR with voltage divider (analog)
  - 0.96" I2C OLED (SSD1306)
  - Buzzer
  - LED

  Required Arduino libraries:
  - DHT sensor library
  - Adafruit GFX Library
  - Adafruit SSD1306
*/

#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ---------- Pin definitions ----------
#define DHT_PIN       4
#define DHT_TYPE      DHT22
#define MQ135_PIN     34
#define LDR_PIN       35
#define BUZZER_PIN    25
#define LED_PIN       2

// ---------- OLED ----------
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDRESS 0x3C

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------- Wi-Fi ----------
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// ---------- Thresholds ----------
const float TEMP_LIMIT = 35.0;       // °C
const float HUMIDITY_LIMIT = 80.0;   // %
const int AIR_QUALITY_LIMIT = 2500;  // Example ADC threshold
const int LIGHT_LIMIT = 300;         // Example ADC threshold

void showMessage(const char* line1, const char* line2) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 15);
  display.println(line1);
  display.setCursor(0, 35);
  display.println(line2);
  display.display();
}

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED initialization failed.");
  } else {
    showMessage("Smart Environment", "Monitor Starting...");
    delay(1500);
  }

  // Wi-Fi is optional. The system continues local monitoring
  // even if Wi-Fi is unavailable.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED &&
         millis() - startTime < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected.");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWi-Fi not available. Local monitoring continues.");
  }
}

void loop() {
  // Read DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read analog sensors
  int airQuality = analogRead(MQ135_PIN);
  int lightLevel = analogRead(LDR_PIN);

  // Check DHT22 reading
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 reading failed.");
    showMessage("Sensor Error", "Check DHT22");
    delay(2000);
    return;
  }

  // Print readings to Serial Monitor
  Serial.println("----- Environment Data -----");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Air Quality ADC: ");
  Serial.println(airQuality);

  Serial.print("Light ADC: ");
  Serial.println(lightLevel);

  // Display readings
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature, 1);
  display.println(" C");

  display.setCursor(0, 13);
  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println(" %");

  display.setCursor(0, 26);
  display.print("Air: ");
  display.println(airQuality);

  display.setCursor(0, 39);
  display.print("Light: ");
  display.println(lightLevel);

  // Alert condition
  bool alert = false;

  if (temperature > TEMP_LIMIT ||
      humidity > HUMIDITY_LIMIT ||
      airQuality > AIR_QUALITY_LIMIT ||
      lightLevel < LIGHT_LIMIT) {
    alert = true;
  }

  if (alert) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    display.setCursor(0, 54);
    display.println("ALERT!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    display.setCursor(0, 54);
    display.println("Status: NORMAL");
  }

  display.display();

  // Wi-Fi status for future IoT/cloud integration
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wi-Fi: Connected");
    // Future extension:
    // Send temperature, humidity, airQuality and lightLevel
    // to an IoT/cloud platform using HTTP or MQTT.
  } else {
    Serial.println("Wi-Fi: Disconnected");
  }

  delay(3000);
}
