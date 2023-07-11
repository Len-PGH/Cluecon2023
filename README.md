# Cluecon2023


Welcome to the maker challenge at Cluecon 2023.  This years challenge is to connect a phone call from an Arduino or ESP32 board.  You can use any sensors provided at the maker tables.  The Arduiono sketch ino examples were made for an ESP32-S3 WROOM Board (FNK0082) kit https://www.amazon.com/gp/product/B0BMQ2CPQN/  You can form a team to create something awesome or create something awesome solo if you like!

The examples scale from if the ESP32 board connects to a wifi connection a phone call is made to more complex examples of including a weather sensor and push button.


<p align="center">
  
![image](https://github.com/Len-PGH/Cluecon2023/assets/13131198/a4db6512-fe8c-46cc-8ffc-c0c45dfa2bda)

  
</p>

### Things you will need:
---------------

1. ESP32-S3 WROOM Board
2. ESP32-S3 WROOM setup instructions [https://freenove.com/fnk0082/ ](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32_S3/archive/refs/heads/main.zip)
3. DH11 temperature sensor (optional)
4. 4 prong push button switch (optional)
5. Breadboard (optional)
6. 10K ohm resistor (optional)
7. Wires
8. USB cord
9. Computer
10. Arduino IDE (sketch software) installed https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE

.
![ESP32_Pinout](https://github.com/Len-PGH/Cluecon2023/assets/13131198/5299ce58-95a9-4804-9b1a-0e51573f9f35)

.

-------------------
## Please Note:: For SMS examples. You are welcome to use the SMS examples but the examples will only work if your Signalwire Space has a registered SMS campain. More info can be found at https://signalwire.com/blogs/industry/navigating-the-campaign-registry-with-signalwire. If you didn't want to setup a campaign just yet, there is also an opinion for (PFT) Platform Free Trial. [PFT docs](https://developer.signalwire.com/guides/messaging/platform-free-trial/).
---------------------

.

.

---------------
* Push button:  Sends an sms when the button is pushed
  - sketch: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_sms.ino
  - doc: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_sms.md
---------------
* Send sms when wifi connects to ESP32
  - sketch: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_wifi_connected_sms.ino
  - doc: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_wifi_connected_sms.md
---------------
* Push button with DH11 temperature sensor: Sends an sms with the current temperature from the DH11
  - sketch: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_dh11.ino
  - doc: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_dh11.md

<p align="center">
  
![image](https://github.com/Len-PGH/Cluecon2023/assets/13131198/ae366d4d-d592-4066-9ab9-84b9211fe337)

 </p> 

---------------
* Push button: Initiates a phone call with the push of a button.
  - sketch: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_phone_call.ino
  - doc: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_phone_call.md
---------------
* Push button: Initiates a phone call and sms message with the push of a button.
  - sketch: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_call_and_sms.ino
  - doc: https://github.com/Len-PGH/Cluecon2023/blob/main/Signalwire_button_call_and_sms.md


