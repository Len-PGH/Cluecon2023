# Cluecon2023


Welcome to the maker challenge at Cluecon 2023.  This years challenge is to connect a phone call from an Arduino or ESP32 board.  You can use any sensors provided at the maker tables.  The Arduiono sketch ino examples were made for an ESP32-S3 WROOM Board (FNK0060) kit https://www.amazon.com/gp/product/B0BMQ2CPQN/  You can form a team to create something awesome or create something awesome solo if you like!

The examples scale from if the ESP32 board connects to a wifi connection a phone call is made to more complex examples of including a weather sensor and push button.


<p align="center">
  
![PXL_20230602_170117825](https://github.com/Len-PGH/Cluecon2023/assets/13131198/d3ed7511-c1f1-4c02-b7c8-f2b12958e470)
  
</p>

### Things you will need:
---------------

1. ESP32-S3 WROOM Board 
2. DH11 temperature sensor (optional)
3. 4 prong push button switch (optional)
4. Breadboard (optional)
5. 10K ohm resistor (optional)
6. Wires
7. USB cord
8. Computer
9. Arduino sketch software installed https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE

.

.

-------------------
## Please Note:: For SMS examples. You are welcome to use the SMS examples but the examples will only work if your Signalwire Space has a registered SMS campain. More info can be found at https://signalwire.com/blogs/industry/navigating-the-campaign-registry-with-signalwire
---------------------

.

.

---------------
* Push button:  Sends an sms when the button is pushed
  - https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_sms.ino
---------------
* Send sms when wifi connects to ESP32
  - https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_wifi_connected_sms.ino
---------------
* Push button with DH11 temperature sensor: Sends an sms with the current temperature from the DH11
  - https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_dh11.ino

<p align="center">
  
![image](https://github.com/Len-PGH/Cluecon2023/assets/13131198/ae366d4d-d592-4066-9ab9-84b9211fe337)

 </p> 

This is an Arduino code that uses an ESP32 board to read the state of a button and send an SMS message using the Signalwire service when the button is pressed. It also includes a DHT11 temperature sensor to read the current temperature and include it in the SMS message.

Here's a breakdown of the code:

   1. Include necessary libraries:
        DHT: Library for interfacing with DHT11 temperature and humidity sensor.
        WiFi: Library for connecting to a Wi-Fi network.
        HTTPClient: Library for making HTTP requests.
        sstream: Library for string manipulation.

  2.  Define Wi-Fi and Signalwire configurations:
        Set the Wi-Fi network name (SSID) and password.
        Set the Signalwire space URL, API path, account SID, and API token.
        Set the destination phone number (tooo) and the sender phone number (from).

  3.  Define button and DHT11 sensor configurations:
        Set the pin number for the button.
        Initialize variables for button state and counting button presses.
        Set the pin number and type of the DHT11 sensor.

 4.   Define the sendSMS function:
        Read the temperature from the DHT11 sensor in Celsius and convert it to Fahrenheit.
        Build the URL for sending an SMS using the Signalwire API.
        Build the URL-encoded body of the request, including the account SID, recipient number, sender number, SMS body, and current temperature.
        Create an HTTP client instance, set the necessary headers and authorization, and send a POST request to the Signalwire API.
        Print the HTTP response and return true if the request was successful (HTTP code 201).

 5.   Set up the Arduino:
        Set the button pin as an input.
        Initialize the serial communication at a baud rate of 115200.
        Connect to the Wi-Fi network using the provided SSID and password.
        Wait until connected to the Wi-Fi network and print a message.

 6.   Main loop:
        Read the current state of the button.
        If the button state is the same as the last state (debouncing), check if the button is pressed (high level).
        If the button is pressed, increment the button press counter, print the number of button pushes, and send an SMS using the sendSMS function.
        Delay for a short period to debounce the button.
        Update the last button state.

That's the basic overview of the code. Keep in mind that you need to replace certain values such as the Wi-Fi credentials, Signalwire space details, and pin numbers with your own configurations.

---------------
* Push button: Initiates a phone call with the push of a button.
  - https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_phone_call.ino
---------------
* Push button: Initiates a phone call and sms message with the push of a button.
  - https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_call_and_sms.ino


