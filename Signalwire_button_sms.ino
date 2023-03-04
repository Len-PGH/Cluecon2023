#include <WiFi.h>
#include <HTTPClient.h>
#include <sstream>
 
const char* ssid = "Cluecon23"; //Change to the wifi ssid
const char* password =  "Signalwire123"; //Change to the wifi password

const char * space_url = "replace-me.signalwire.com"; //Replace with your Signalwire space name
const char * api_path = "/api/laml/2010-04-01/Accounts/"; 
const char * account_sid = "fd222264-0000-9999-6666-0545aaa90b65"; //Replace with your Signalwire space account sid
const char * plus = "%2B";
const char * tooo = "17244445555"; //Replace with the number you send sms to
const char * from = "14125551234"; //Replace with the number from your Signalwire space
const char * sw_token = "PT123"; //Replace with your Signalwire space API Token
 
// Define the button pin
const int buttonPin = 4; //connect button to pin 4 and VCC

bool sendSMS(const char * body){
 
  std::stringstream url;
  url << "https://" << space_url << api_path << account_sid <<"/Messages.json";
 
  std::stringstream urlEncodedBody;
  urlEncodedBody << "account_sid=" << account_sid << "&To=" << plus << "" << tooo << "&From=" << plus << "" << from << "&Body=" << body;
 

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
    }
 
  else {
    Serial.println("Error on HTTP request:");
    Serial.println(httpCode);
  }
 
  http.end();
 
  return httpCode == 201;
 
}

void setup() {
  
  Serial.begin(115200);
 
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");

  // Set the button pin as an input
  pinMode(buttonPin, INPUT);
 
}
  
 
void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, send an SMS
  if (buttonState == HIGH) {
    bool result = sendSMS("Button pushed on ESP32. Thank you for choosing https://signalwire.com");
 
    if(result){
      Serial.println("\nSMS sent");
    }else{
      Serial.println("\nSMS failed");
    }

    // Add a delay to debounce the button
    delay(1000);
  }
}
