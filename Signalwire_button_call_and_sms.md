## Signalwire Temperature Monitoring and Notification

This code is written in C++ using the Arduino framework and is designed to run on an ESP32 microcontroller board. It enables temperature monitoring using a DHT11 sensor and provides functionality to send an SMS and make a call using the Signalwire service when a button is pressed.

### Dependencies

The code requires several libraries to be included:

- `DHT.h`: This library provides functions for reading temperature and humidity values from the DHT11 sensor.
- `WiFi.h`: This library enables connecting to a Wi-Fi network.
- `HTTPClient.h`: This library allows making HTTP requests.
- `sstream`: This library provides string stream functionality for constructing URLs and request bodies.

### Wi-Fi Configuration

Before running the code, you need to configure the Wi-Fi network. Replace the following variables with your network's SSID and password:

```cpp
const char * ssid = "Cluecon23"; //Change to the wifi ssid
const char * password = "Signalwire123"; //Change to the wifi password
```

### Signalwire Configuration

To send SMS and make calls using Signalwire, you need to provide your Signalwire account information and API credentials. Replace the following variables with your Signalwire account details:

```cpp
const char * account_sid = "fd222264-0000-9999-6666-0545aaa90b65"; //Replace with your Signalwire space account sid
const char * tooo = "17244445555"; //Replace with the number you send SMS to
const char * from = "14125551234"; //Replace with the number from your Signalwire space
const char * sw_token = "PT123"; //Replace with your Signalwire space API Token
```

### Signalwire API URLs

The code uses the Signalwire SMS and call API URLs for making requests. Replace the following variables with the correct URLs:

```cpp
const char * sms_url = "https://example.signalwire.com/api/laml/2010-04-01/Accounts/{account_sid}/Messages.json"; //Replace with your Signalwire space SMS URL
const char * call_url = "https://example.signalwire.com/api/laml/2010-04-01/Accounts/{account_sid}/Calls.json"; //Replace with your Signalwire space call URL
```

### Pin Configuration

The code assumes that the button is connected to pin 14 (buttonPin) on the ESP32 board. Adjust the pin number if necessary:

```cpp
const int buttonPin = 14; // the pin number for the button
```

The DHT11 sensor is connected to pin 21 (DHTPIN) on the ESP32 board. If you have connected the sensor to a different pin, update the following line accordingly:

```cpp
#define DHTPIN 21 // Replace with the actual pin number connected to the DHT11 sensor
```

### Functions

The code defines two functions: `sendSMS` and `makeCall`. These functions take a `body` parameter, which represents the message or URL to be sent via SMS or used for making a call. The functions also read the temperature from the DHT11 sensor and convert it to Fahrenheit.

### Setup

The `setup` function is called once when the microcontroller starts. It initializes the button pin as an input and starts the serial communication for debugging. It also connects to the specified Wi-Fi network and initializes the DHT11 sensor.

### Loop

The `loop` function is called repeatedly after the `setup` function. It reads the state of the button and checks if it has been pressed. If the button is pressed, it increments a counter and sends an SMS and makes a call using the Signalwire

 API. The message body and URL for the call are provided as arguments to the respective functions.

The function also includes a delay of 500 milliseconds to debounce the button and prevent multiple button presses from being registered.

That's the explanation of the provided code. Make sure to configure the Wi-Fi and Signalwire settings before uploading the code to your ESP32 board.
