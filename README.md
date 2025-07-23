# PeltierPro

# Peltier Module Efficiency Optimizer

This project investigates the thermal efficiency of a Peltier module by logging environmental data (temperature, humidity, etc.) to the cloud and analyzing the performance to determine the optimal operating conditions.

## Project Goals

- Log real-time temperature and humidity data under various voltage inputs
- Use cloud IoT platform (ThingSpeak) to store and visualize data
- Analyze collected data to determine optimal voltage and thermal operating point for maximum cooling efficiency

## Hardware Used

- TEC1-12706 Peltier Module
- Heatsink + Fan
- Arduino Uno
- DS18B20 Temperature Sensor
- DHT11 Temp & Humidity Sensor
- Ultrasonic Sensor (used to monitor distance from cooling object)
- Voltage Regulator
- External Power Supply
- Jumper Wires, Breadboard

## Cloud Integration

Data collected by the Arduino is sent via serial to a Python script (`Cloud.py`), which uploads the readings to **ThingSpeak**.

### Fields Used in ThingSpeak:
- `Field1`: Distance from object (Ultrasonic sensor)
- `Field2`: Temperature (DS18B20)
- `Field3`: Temperature (DHT11)
- `Field4`: Humidity (DHT11)

## Learning Outcomes

- Thermoelectric cooling behavior with Peltier modules
- IoT data logging using ThingSpeak
- Real-time sensor interfacing with Arduino
- Serial communication between Arduino and Python
- Cloud-based data visualization & analysis


## Future Improvements

- Automate voltage control using PWM & MOSFET
- Add real-time graphing in Python
- Use ML to predict optimal voltage-temperature correlation
- Public ThingSpeak channel for live demo

