#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <sstream>


const char * ssid = "Cluecon23"; //Change to the wifi ssid
const char * password = "Signalwire123"; //Change to the wifi password

const char * space_url = "replace-me.signalwire.com"; //Replace with your Signalwire space name
const char * api_path = "/api/laml/2010-04-01/Accounts/"; 
const char * account_sid = "fd222264-0000-9999-6666-0545aaa90b65"; //Replace with your Signalwire space account sid
const char * plus = "%2B";
const char * tooo = "17244445555"; //Replace with the number you send sms to
const char * from = "14125551234"; //Replace with the number from your Signalwire space
const char * sw_token = "PT123"; //Replace with your Signalwire space API Token

const int buttonPin = 14; // the pin number for the button
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button

#define DHTPIN 21 // Replace with the actual pin number connected to the DHT11 sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

bool sendSMS(const char* body) {
  float temperatureC = dht.readTemperature(); // Read temperature from DHT11 sensor in Celsius
  float temperatureF = temperatureC * 1.8 + 32.0; // Convert temperature to Fahrenheit
  
  std::stringstream url;
  url << "https://" << space_url << api_path << account_sid << "/Messages.json";

  std::stringstream urlEncodedBody;
  urlEncodedBody << "account_sid=" << account_sid << "&To=" << plus << "" << tooo << "&From=" << plus << "" << from << "&Body=" << body << " Current temperature: " << temperatureF << "F";

  Serial.print("\nURL: ");
  Serial.println(url.str().c_str());
  Serial.print("Encoded body: ");
  Serial.println(urlEncodedBody.str().c_str());

  HTTPClient http;

  http.begin(url.str().c_str());
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.setAuthorization(account_sid, sw_token);

  int httpCode = http.POST(urlEncodedBody.str().c_str());

  if (httpCode > 0) {
    String payload = http.getString();

    Serial.print("\nHTTP code: ");
    Serial.println(httpCode);

    Serial.print("\nResponse: ");
    Serial.println(payload);
  } else {
    Serial.println("Error on HTTP request:");
    Serial.println(httpCode);
  }

  http.end();

  return httpCode == 201;
}

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

 Serial.println("Connected to the WiFi network");

dht.begin(); // Initialize the DHT11 sensor
}

void loop() {
buttonState = digitalRead(buttonPin);

if (buttonState == lastButtonState) {
if (buttonState == HIGH) {
buttonPushCounter++;
Serial.println("on");
Serial.print("number of button pushes: ");
Serial.println(buttonPushCounter);
bool result = sendSMS("Button pushed on ESP32. Thank you for choosing https://signalwire.com");
delay(1000);
} else {
delay(500);
}
}

lastButtonState = buttonState;
}
