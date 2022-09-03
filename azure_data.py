import random
import time

# Using the Python Device SDK for IoT Hub:
#   https://github.com/Azure/azure-iot-sdk-python
# The sample connects to a device-specific MQTT endpoint on your IoT Hub.
from azure.iot.device import IoTHubDeviceClient, Message

# The device connection string to authenticate the device with your IoT hub.
# Using the Azure CLI:
# az iot hub device-identity show-connection-string --hub-name {YourIoTHubName} --device-id MyNodeDevice --output table
CONNECTION_STRING = "HostName=Trupt.azure-devices.net;DeviceId=mydevice;SharedAccessKey=JUFg69U7WlQVjNTbOS+YjSa1xh/OuKHIO5Gq7OVjzKU="

# Define the JSON message to send to IoT Hub.
TEMPREATURE = 20.0
DISTANCE = 50
HUMIDITY = 50
MSG_TXT = '{{"tempreature": {tempreature},"distance": {distance}, "humidity": {humidity}}}'

def iothub_client_init():
    # Create an IoT Hub client
    client = IoTHubDeviceClient.create_from_connection_string(CONNECTION_STRING)
    return client

def iothub_client_accident_data():

    try:
        client = iothub_client_init()
        print ( "IoT Hub device sending periodic messages, press Ctrl-C to exit" )
        while True:
            # Build the message with simulated telemetry values.
            tempreature = TEMPREATURE + (random.random() * 15)
            distance = DISTANCE + (random.random() * 20)
            humidity = HUMIDITY + (random.random() * 25)
            msg_txt_formatted = MSG_TXT.format(tempreature=tempreature, distance=distance, humidity=humidity)
            message = Message(msg_txt_formatted)

            # Add a custom application property to the message.
            # An IoT hub can filter on these properties without access to the message body.
            #if pressure > 40:
              #message.custom_properties["pressureAlert"] = "true"
            #else:
              #message.custom_properties["pressureAlert"] = "false"

            # Send the message.
            if (distance < 200):
              print("Your Distance very less.... then need to break")
            else if (distance > 200):
              if( (tempreature < 20) || (humidity > 70) ):
                print("Not to good for driving because... not proper visible")
              else
                print( "Sending message: {}".format(message) )
            client.send_message(message)
            print ( "Message successfully sent" )
            time.sleep(3)

    except KeyboardInterrupt:
        print ( "IoTHubClient sample stopped" )

if __name__ == '__main__':
    print ( "IoT Hub Quickstart #1 - Simulated device" )
    print ( "Press Ctrl-C to exit" )
    iothub_client_accident_data():
