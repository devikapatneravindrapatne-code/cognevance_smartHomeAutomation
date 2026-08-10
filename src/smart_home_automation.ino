#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define LDR_PIN 34
#define PIR_PIN 27
#define RELAY_PIN 26

DHT dht(DHT_PIN, DHT_TYPE);

int lightThreshold = 2000;

void setup()
{
  Serial.begin(115200);

  dht.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);

  Serial.println("Smart Home Automation System");
  Serial.println("--------------------------------");
}

void loop()
{
  // Read DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read LDR
  int lightValue = analogRead(LDR_PIN);

  // Read PIR
  int motion = digitalRead(PIR_PIN);

  // Display temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display light value
  Serial.print("Light Value: ");
  Serial.println(lightValue);

  // Display motion status
  if (motion == HIGH)
  {
    Serial.println("Motion: DETECTED");
  }
  else
  {
    Serial.println("Motion: NOT DETECTED");
  }

  // Automatic light control
  if (motion == HIGH && lightValue < lightThreshold)
  {
    digitalWrite(RELAY_PIN, HIGH);

    Serial.println("Relay: ON");
    Serial.println("Light: ON");
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);

    Serial.println("Relay: OFF");
    Serial.println("Light: OFF");
  }

  Serial.println("--------------------------------");

  delay(1000);
}
