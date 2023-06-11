## Signalwire SMS Sender with Button

This code is written in C++ using the Arduino framework and is designed to run on an ESP32 microcontroller board. It sends an SMS message using the Signalwire service when a button connected to the microcontroller is pressed.

### Dependencies

The code requires the following libraries to be included:

- `WiFi.h`: This library enables connecting to a Wi-Fi network.
- `HTTPClient.h`: This library allows making HTTP requests.
- `sstream`: This library provides string stream functionality for constructing URLs and request bodies.

### Wi-Fi Configuration

Before running the code, you need to configure the Wi-Fi network. Replace the following variables with your network's SSID and password:

```cpp
const char* ssid = "Cluecon23"; //Change to the wifi ssid
const char* password =  "Signalwire123"; //Change to the wifi password
```

### Signalwire Configuration

To send an SMS using Signalwire, you need to provide your Signalwire account information and API credentials. Replace the following variables with your Signalwire account details:

```cpp
const char * space_url = "replace-me.signalwire.com"; //Replace with your Signalwire space name
const char * account_sid = "fd222264-0000-9999-6666-0545aaa90b65"; //Replace with your Signalwire space account sid
const char * tooo = "17244445555"; //Replace with the number you send the SMS to
const char * from = "14125551234"; //Replace with the number from your Signalwire space
const char * sw_token = "PT123"; //Replace with your Signalwire space API Token
```

Make sure to replace `"replace-me.signalwire.com"` with your Signalwire space URL.

### Button Configuration

The code assumes that you have a button connected to pin 14 of the ESP32 board. If you are using a different pin, modify the following line according to your configuration:

```cpp
const int buttonPin = 14; // the pin number for the button
```

### Function: sendSMS

The code defines a function `sendSMS` that takes a `body` parameter representing the text message to be sent. It constructs the SMS API URL and request body using the provided information and makes an HTTP POST request to the Signalwire API.

### Setup

The `setup` function is called once when the microcontroller starts. It initializes the serial communication for debugging and connects to the specified Wi-Fi network. After establishing a connection, it prints a message to the serial monitor.

### Loop

The `loop` function is called repeatedly after the `setup` function. It reads the state of the button connected to `buttonPin`. If the button is pressed, it increments the `buttonPushCounter`, prints a message to the serial monitor, and calls the `sendSMS` function with a test message.

The `loop` function also includes a delay to avoid multiple button presses being registered for a single press. The `lastButtonState` variable is used to store the previous state of the button and is updated at the end of each iteration.

That's the explanation of the provided code. Remember to configure the Wi-Fi and Signalwire settings before uploading the code to your ESP32 board.
