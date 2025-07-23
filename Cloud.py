import serial
import requests
import time


THINGSPEAK_API_KEY = '########'
THINGSPEAK_URL = 'https://api.thingspeak.com/update'


arduino = serial.Serial('COM5',
                        9600) 
time.sleep(2)  #


def send_to_thingspeak(distance, temp_ds18b20, temp_dht11, humidity):
    payload = {
        'api_key': THINGSPEAK_API_KEY,
        'field1': distance,
        'field2': temp_ds18b20,
        'field3': temp_dht11,
        'field4': humidity
    }
    response = requests.get(THINGSPEAK_URL, params=payload)
    if response.status_code == 200:
        print("Data sent to ThingSpeak")
    else:
        print("Failed to send data. Status code:", response.status_code)


while True:
    try:
        # Read data from serial
        if arduino.in_waiting > 0:
            line = arduino.readline().decode().strip()
            print("Received:", line)

            # Parse sensor data
            if line.startswith("Distance"):
                parts = line.split(',')
                distance = int(parts[0].split(':')[1])
                temp_ds18b20 = float(parts[1].split(':')[1])
                temp_dht11 = float(parts[2].split(':')[1])
                humidity = float(parts[3].split(':')[1])

                # Send data to ThingSpeak
                send_to_thingspeak(distance, temp_ds18b20, temp_dht11, humidity)
                time.sleep(15)  #

    except Exception as e:
        print("Error:", e)
        break
