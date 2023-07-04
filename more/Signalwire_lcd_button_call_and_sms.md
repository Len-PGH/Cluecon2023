# Monitoring Temperature and Displaying on LCD using ESP32 and DHT11

![image](https://github.com/Len-PGH/Cluecon2023/assets/13131198/092c2d1b-82dc-4710-b27b-9e8a2f630d32)


In this tutorial, we will learn how to monitor temperature using the DHT11 sensor and display the temperature readings on an LCD screen using the ESP32 microcontroller. We will also demonstrate how to send SMS and make a call using the Signalwire API based on button input.

## Components Used
- ESP32 microcontroller
- DHT11 temperature and humidity sensor
- 16x2 LCD screen (HD44780 compatible)
- Push button (Adafruit Colorful Square Tactile Button Switch)
- Vibration Sensor Module SW-420 (Can be used in place of push button)

## Libraries Required
- DHT sensor library (DHT.h)
- WiFi library (WiFi.h)
- HTTPClient library (HTTPClient.h)
- Wire library (Wire.h)
- hd44780 library (hd44780.h)
- hd44780 I2Cexp library (hd44780_I2Cexp.h)

## Connections
- Connect the data pin of the DHT11 sensor to pin 21 of the ESP32.
- Connect the SDA pin of the LCD to pin 8 of the ESP32.
- Connect the SCL pin of the LCD to pin 9 of the ESP32.
- Connect one leg of the push button to pin 14 of the ESP32.

## Code Explanation

1. Include the necessary libraries for DHT, WiFi, HTTPClient, Wire, and hd44780.

2. Set up the Wi-Fi credentials and Signalwire account details.

3. Initialize global variables and create an instance of the LCD class.

4. Implement the `sendSMS()` function to send an SMS using the Signalwire API. This function reads the temperature from the DHT11 sensor, converts it to Fahrenheit, and includes it in the SMS body.

5. Implement the `makeCall()` function to make a call using the Signalwire API. This function reads the temperature from the DHT11 sensor, converts it to Fahrenheit, and includes it in the call URL.

6. In the `setup()` function, initialize the button pin as an input, start the serial communication, connect to the Wi-Fi network, initialize the DHT11 sensor, and initialize the LCD.

7. In the `loop()` function, read the temperature from the DHT11 sensor, convert it to Fahrenheit, and display it on the LCD screen. The LCD backlight is turned on, and the temperature value is printed on the second line of the LCD.

8. Check the state of the push button. If the button is pressed, increment the buttonPushCounter variable, print the number of button presses to the serial monitor, and make a call using the Signalwire API.

9. Add delays to the loop to avoid continuous reading and display of temperature values.

## Conclusion

In this tutorial, we learned how to monitor temperature using the DHT11 sensor, display the temperature readings on an LCD screen using the ESP32 microcontroller, and interact with the Signalwire API to send an SMS and make a call. You can further extend this project by adding more functionality or integrating it with other IoT devices. Happy experimenting!
