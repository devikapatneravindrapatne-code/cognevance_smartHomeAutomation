#define BLYNK_TEMPLATE_ID "TMPL32XvgrlFB"
#define BLYNK_TEMPLATE_NAME "Smart Home Automation"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Pin Definitions
#define DHT_PIN 4
#define DHT_TYPE DHT22
#define LDR_PIN 34
#define PIR_PIN 27
#define RELAY_PIN 26

// Sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Wi-Fi
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Blynk Timer
BlynkTimer timer;

// Light Threshold
int lightThreshold = 2000;

// Send Sensor Data
void sendSensorData()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int lightValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT22 reading failed!");
    return;
  }

  // Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, lightValue);
  Blynk.virtualWrite(V3, motion);

  // Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Light Value: ");
  Serial.println(lightValue);

  // Motion Status
  if (motion == HIGH)
  {
    Serial.println("Motion: DETECTED");
  }
  else
  {
    Serial.println("Motion: NOT DETECTED");
  }

  // Automatic Light Control
  if (motion == HIGH && lightValue < lightThreshold)
  {
    digitalWrite(RELAY_PIN, HIGH);

    Blynk.virtualWrite(V4, 1);
    Blynk.virtualWrite(V5, 1);

    Serial.println("Relay: ON");
    Serial.println("Light: ON");
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);

    Blynk.virtualWrite(V4, 0);
    Blynk.virtualWrite(V5, 0);

    Serial.println("Relay: OFF");
    Serial.println("Light: OFF");
  }

  Serial.println("--------------------------------");
}

// Setup
void setup()
{
  Serial.begin(115200);

  dht.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);

  Serial.println();
  Serial.println("================================");
  Serial.println("Smart Home Automation System");
  Serial.println("================================");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensorData);
}

// Loop
void loop()
{
  Blynk.run();
  timer.run();
}
