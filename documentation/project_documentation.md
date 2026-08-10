# Smart Home Automation System

## 1. Introduction

The Smart Home Automation System is an ESP32-based embedded system designed to monitor environmental conditions and automatically control a light.

The system uses a DHT22 sensor to measure temperature and humidity, an LDR to measure light intensity, and a PIR sensor to detect motion. The ESP32 processes the sensor data and controls a relay connected to an LED, which represents a household light.

The complete system was designed and tested using the Wokwi simulation platform.

---

## 2. Objective

The objectives of this project are:

- To understand ESP32-based embedded system development.
- To interface multiple sensors with an ESP32.
- To measure temperature and humidity.
- To measure ambient light intensity.
- To detect human motion.
- To control a light automatically using a relay.
- To monitor sensor readings through the Serial Monitor.
- To test the complete system in a simulation environment.

---

## 3. Components Used

### Hardware Components

- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- Photoresistor (LDR) Sensor
- PIR Motion Sensor
- Relay Module
- LED
- Resistor
- Connecting Wires

### Software and Tools

- Wokwi Simulator
- Arduino-compatible ESP32 programming environment
- Embedded C/C++
- GitHub

---

## 4. System Architecture

The overall system follows the architecture below:

Sensors
   ↓
ESP32
   ↓
Sensor Data Processing
   ↓
Decision Making
   ↓
Relay Control
   ↓
LED / Light

The DHT22, LDR, and PIR sensors provide input to the ESP32.

The ESP32 processes the sensor readings and determines whether the light should be switched ON or OFF.

---

## 5. Working Principle

The ESP32 continuously reads data from the connected sensors.

### DHT22 Sensor

The DHT22 measures:

- Temperature
- Humidity

The measured values are displayed through the Serial Monitor.

### LDR Sensor

The LDR measures the surrounding light intensity.

The analog output of the photoresistor is connected to GPIO 34 of the ESP32.

A light threshold is used to determine whether the environment is dark or bright.

### PIR Sensor

The PIR sensor detects human motion.

When motion is detected, its output becomes HIGH and the ESP32 identifies the presence of motion.

### Relay and LED

The relay is controlled by the ESP32.

The LED is used as a simulated household light.

---

## 6. Pin Configuration

| Component | Pin | ESP32 Pin |
|---|---|---|
| DHT22 | DATA | GPIO 4 |
| LDR | AO | GPIO 34 |
| PIR | OUT | GPIO 27 |
| Relay | IN | GPIO 26 |

### Power Connections

| Component | Connection |
|---|---|
| DHT22 VCC | 3.3V |
| DHT22 GND | GND |
| LDR VCC | 3.3V |
| LDR GND | GND |
| PIR VCC | 5V |
| PIR GND | GND |
| Relay VCC | 5V |
| Relay GND | GND |

---

## 7. Control Logic

The automatic light control is based on two conditions:

1. Motion must be detected.
2. The environment must be dark.

The system uses a light threshold of 2000.

### Logic

If:

Motion = DETECTED

AND

Light Value < 2000

Then:

Relay = ON  
Light = ON

Otherwise:

Relay = OFF  
Light = OFF

---

## 8. Program Flow

The program follows these steps:

1. Initialize Serial communication.
2. Initialize the DHT22 sensor.
3. Configure the PIR and relay pins.
4. Read temperature and humidity.
5. Read the LDR analog value.
6. Read the PIR motion status.
7. Display sensor values on the Serial Monitor.
8. Check the motion and light conditions.
9. Turn the relay ON when motion is detected in a dark environment.
10. Turn the relay OFF otherwise.
11. Repeat the process continuously.

---

## 9. Sensor Monitoring

The Serial Monitor is used to display the sensor readings and system status.

Example output:

Temperature: 24.00 C  
Humidity: 40.00 %  
Light Value: 839  
Motion: NOT DETECTED  
Relay: OFF  
Light: OFF

When motion is detected in a dark environment:

Temperature: 24.00 C  
Humidity: 40.00 %  
Light Value: 839  
Motion: DETECTED  
Relay: ON  
Light: ON

---

## 10. Testing

The system was tested under different combinations of light and motion conditions.

| Test Case | Motion | Light Condition | Expected Result | Status |
|---|---|---|---|---|
| 1 | Not Detected | Bright | Light OFF | PASS |
| 2 | Detected | Bright | Light OFF | PASS |
| 3 | Not Detected | Dark | Light OFF | PASS |
| 4 | Detected | Dark | Light ON | PASS |

The LDR, DHT22, PIR sensor, relay, and LED were tested individually and as part of the complete system.

---

## 11. Simulation Environment

The project was implemented and tested using Wokwi because physical hardware components were not available during development.

The simulation was used to verify:

- ESP32 operation
- DHT22 sensor readings
- LDR light measurements
- PIR motion detection
- Relay control
- LED operation
- Automatic control logic
- Serial Monitor output

---

## 12. Results

The ESP32 successfully received data from the DHT22, LDR, and PIR sensors.

The DHT22 successfully displayed temperature and humidity readings.

The LDR successfully provided analog light values.

The PIR successfully detected simulated motion using the Wokwi motion simulation feature.

The relay successfully controlled the LED according to the programmed conditions.

Therefore, the complete Smart Home Automation System was successfully simulated and tested.

---

## 13. Limitations

The current implementation is a simulation-based prototype.

The system does not currently include:

- Physical hardware testing
- Mobile application control
- Cloud data storage
- Remote appliance control
- Energy consumption monitoring

---

## 14. Future Improvements

The system can be further improved by:

- Connecting the ESP32 to an IoT cloud platform.
- Creating a web or mobile dashboard.
- Adding remote appliance control.
- Sending notifications when motion is detected.
- Adding additional home appliances.
- Adding energy monitoring.
- Storing sensor data for analysis.
- Implementing voice-based control.

---

## 15. Conclusion

The Smart Home Automation System demonstrates the use of an ESP32 for sensor interfacing, real-time monitoring, decision making, and automatic appliance control.

The project successfully integrates a DHT22, LDR, PIR sensor, relay, and LED. The system was simulated and tested using Wokwi, and the sensor readings and automation behavior were verified through the Serial Monitor.

This project provides practical experience in embedded programming, sensor interfacing, GPIO control, analog input processing, digital input processing, and basic home automation.
