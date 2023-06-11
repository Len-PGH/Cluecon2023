## Signalwire Temperature Monitoring and SMS Notification

This code is written in C++ using the Arduino framework and is designed to run on an ESP32 microcontroller board. It enables temperature monitoring using a DHT11 sensor and provides functionality to send an SMS using the Signalwire service when a button is pressed.

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

To send SMS using Signalwire, you need to provide your Signalwire account information and API credentials. Replace the following variables with your Signalwire account details:

```cpp
const char * space_url = "replace-me.signalwire.com"; //Replace with your Signalwire space name
const char * account_sid = "fd222264-0000-9999-6666-0545aaa90b65"; //Replace with your Signalwire space account sid
const char * tooo = "17244445555"; //Replace with the number you send SMS to
const char * from = "14125551234"; //Replace with the number from your Signalwire space
const char * sw_token = "PT123"; //Replace with your Signalwire space API Token
```

### Signalwire API URLs

The code constructs the Signalwire SMS API URL for making requests. The URL is constructed using the `space_url`, `api_path`, and `account_sid` variables:

```cpp
std::stringstream url;
url << "https://" << space_url << api_path << account_sid << "/Messages.json";
```

Make sure to replace `"replace-me.signalwire.com"` with your Signalwire space URL.

### Pin Configuration

The code assumes that the button is connected to pin 14 (`buttonPin`) on the ESP32 board. Adjust the pin number if necessary:

```cpp
const int buttonPin = 14; // the pin number for the button
```

The DHT11 sensor is connected to pin 21 (`DHTPIN`) on the ESP32 board. If you have connected the sensor to a different pin, update the following line accordingly:

```cpp
#define DHTPIN 21 // Replace with the actual pin number connected to the DHT11 sensor
```

### Functions

The code defines a function `sendSMS` that takes a `body` parameter, representing the message to be sent via SMS. The function reads the temperature from the DHT11 sensor and constructs the SMS URL and request body. It then makes an HTTP POST request to the Signalwire SMS API endpoint using the constructed URL and request body.

### Setup

The `setup` function is called once when the microcontroller starts. It initializes the button pin as an input and starts the serial communication for debugging. It also connects to the specified Wi-Fi network and initializes the DHT11 sensor.

### Loop

The `loop` function is called repeatedly after the `setup` function. It reads the state of the button and checks if it has been pressed. If the button is pressed, it increments a counter and sends an SMS using the `sendSMS` function. The message body is provided as an argument to

 the function call. After sending the SMS, it adds a delay of 1 second.

That's the explanation of the provided code. Make sure to configure the Wi-Fi and Signalwire settings before uploading the code to your ESP32 board.
