# Testing Report

## Smart Home Automation System

## 1. Testing Objective

The objective of testing is to verify that the ESP32 correctly receives data from the DHT22, LDR, and PIR sensors and controls the relay and LED according to the programmed conditions.

The complete system was tested using the Wokwi simulation environment.

---

## 2. Testing Method

The system was tested by changing the sensor conditions in Wokwi and observing the output through the Serial Monitor.

The following parameters were monitored:

- Temperature
- Humidity
- Light intensity
- Motion status
- Relay status
- Light status

---

## 3. Test Cases

| Test Case | Motion | Light Condition | Expected Result | Actual Result | Status |
|---|---|---|---|---|---|
| TC01 | Not Detected | Bright | Relay OFF, Light OFF | Relay OFF, Light OFF | PASS |
| TC02 | Detected | Bright | Relay OFF, Light OFF | Relay OFF, Light OFF | PASS |
| TC03 | Not Detected | Dark | Relay OFF, Light OFF | Relay OFF, Light OFF | PASS |
| TC04 | Detected | Dark | Relay ON, Light ON | Relay ON, Light ON | PASS |

---

## 4. DHT22 Sensor Testing

The DHT22 sensor was tested to verify temperature and humidity measurement.

### Sample Reading

```text
Temperature: 24.00 C
Humidity: 40.00 %
