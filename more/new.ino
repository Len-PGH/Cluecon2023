const char * MediaUrl = "https://i.ibb.co/QJgF9wr/unnamed.jpg"; //Replace with an image.

std::string sms_url_string = "https://" + std::string(space_sub_url) + ".signalwire.com/api/laml/2010-04-01/Accounts/{account_sid}/Messages.json";
const char* sms_url = sms_url_string.c_str(); // Replace with your Signalwire space SMS URL
std::string call_url = std::string("https://") + space_sub_url + ".signalwire.com/api/laml/2010-04-01/Accounts/{account_sid}/Calls.json";
const char* call_url_cstr = call_url.c_str(); // Replace with your Signalwire space call URL

const int buttonPins[] = {14, 19};  // Array of button pin numbers
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);  // Number of buttons

int buttonStates[numButtons];        // Array to store current button states
int lastButtonStates[numButtons];    // Array to store previous button states
int buttonPushCounter = 0;           // Counter for the number of button presses

const int lcdPrintInterval = 5000;  // Interval between each LCD print in milliseconds
const int numLcdPrints = 4;         // Number of LCD prints to loop through

unsigned long previousMillis = 0;   // Variable to store the previous time
int lcdPrintCounter = 0;            // Counter to keep track of the current LCD print

float temperatureF; // Global variable to store temperature in Fahrenheit

hd44780_I2Cexp lcd; // Create an instance of the LCD class

#define DHTPIN 21 // Replace with the actual pin number connected to the DHT11 sensor
#define DHTTYPE DHT11
#define LED_PIN 1  // For GPIO1

DHT dht(DHTPIN, DHTTYPE);

bool sendSMS(const char* body) {
  float temperatureC = dht.readTemperature(); // Read temperature from DHT11 sensor in Celsius
  float temperatureF = temperatureC * 1.8 + 32.0; // Convert temperature to Fahrenheit
  
  std::stringstream url;
  url << sms_url;

  std::stringstream urlEncodedBody;
  urlEncodedBody << "account_sid=" << account_sid << "&To=" << plus << "" << tooo << "&From=" << plus << "" << from << "&MediaUrl=" << MediaUrl << "&Body=" << body << " Current temperature: " << temperatureF << "F";

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

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Calling ");
    lcd.setCursor(0, 1);
    lcd.print("  ");
    lcd.print(tooo);
    lcd.print("     ");
    delay(2000);

    Serial.print("\nResponse: ");
    Serial.println(payload);
  } else {
    Serial.println("Error on HTTP request:");
    Serial.println(httpCode);
  }

  http.end();

  return httpCode == 201;
}

bool makeCall(const char* body) {
  float temperatureC = dht.readTemperature(); // Read temperature from DHT11 sensor in Celsius
  float temperatureF = temperatureC * 1.8 + 32.0; // Convert temperature to Fahrenheit

  std::stringstream url;
  url << call_url;

  std::stringstream urlEncodedBody;
  urlEncodedBody << "account_sid=" << account_sid << "&From=" << plus << "" << from << "&To=" << plus << "" << tooo << "&Url=" << body;

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
  for (int i = 0; i < sizeof(buttonPins) / sizeof(buttonPins[0]); i++) {
    pinMode(buttonPins[i], INPUT);
  }
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

  dht.begin(); // Initialize the DHT11 sensor
  lcd.begin(16, 2);  // Initialize the LCD

}


void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Check if it's time to perform the next LCD print
  if (currentMillis - previousMillis >= lcdPrintInterval) {
    previousMillis = currentMillis;  // Update the previous time

    // Perform the current LCD print
    switch (lcdPrintCounter) {
      case 0:
        {
          float temperatureC = dht.readTemperature(); // Read temperature from DHT11 sensor in Celsius
          float temperatureF = temperatureC * 1.8 + 32.0; // Convert temperature to Fahrenheit
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("  Temperature ");
          lcd.setCursor(0, 1);
          lcd.print("     ");
          lcd.print(temperatureF);
          lcd.print("F     ");
        }
        break;
      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("   Welcome to     ");
        lcd.setCursor(0, 1);
        lcd.print(" Cluecon 2023!!");
        break;
        case 2:
        {
          // Make the HTTP request to retrieve the message body
          HTTPClient http;

          // Set the authorization header
          String authHeader = "Authorization";
          String authValue = "Basic ZmQwYTMzNjQtYThiMS00NjFjLTk1MTItMDU0NWJjZTkwYjY1OlBUMmI4YzRjN2UzM2QxZTU0ZWVhYjkyMjFlMTM4MDEzYTlkMjFiY2FkMzg2ZmY5Z";

        // Set the request URL
          String url = "https://len.signalwire.com/api/laml/2010-04-01/Accounts/fd0a3364-a8b1-461c-9512-0545bce90b65/Messages.json?Status=received&direction=inbound&page_size=1&fields=body";

        // Specify additional headers
        http.begin(url);
        http.addHeader("Accept", "application/json");
        http.addHeader(authHeader, authValue);

        // Perform the HTTP GET request
        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {
          // Read the response
          String response = http.getString();

          // Parse the JSON response
          DynamicJsonDocument jsonDoc(1024);
          deserializeJson(jsonDoc, response);

          // Extract the body value
          String body = jsonDoc["messages"][0]["body"];

          // Update the LCD display with the received message body
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("  SMS Received");

          int messageLength = body.length();
          int startIndex = 0;
          int scrollIterations = 0;

          // Display the first 16 characters of the message
          lcd.setCursor(0, 1);
          lcd.print(body.substring(startIndex, startIndex + 16));

          // Check if scrolling is needed
          if (messageLength > 16) {
            delay(2000);  // Delay to display the first 16 characters

            while (startIndex < messageLength) {
              startIndex++;

              // Shift the characters to create scrolling effect
              lcd.setCursor(0, 1);
              lcd.print(body.substring(startIndex, startIndex + 16));

              delay(500);  // Delay to control the scrolling speed

              // Break out of the loop after all characters have been displayed
              if (startIndex + 16 >= messageLength) {
                break;
              }
            }
          }
        } else {
          Serial.println("Error occurred while retrieving the message. HTTP response code: " + String(httpResponseCode));
        }

        // Clean up
        http.end();
      }
      break;
      case 3:
        {
          // Update the time every lcdPrintInterval milliseconds
          // Make the HTTP GET request to TimeAPI
          HTTPClient http;
          http.begin("https://www.timeapi.io/api/Time/current/zone?timeZone=America/New_york");
          int httpCode = http.GET();

          if (httpCode == 200) {
            // Read the response and parse the JSON data
            String response = http.getString();
            DynamicJsonDocument doc(1024);
            deserializeJson(doc, response);

            // Extract the time from the JSON data
            int hour = doc["hour"];
            int minute = doc["minute"];
            int seconds = doc["seconds"];

            // Determine AM or PM
            String amPm = "AM";
            if (hour >= 12) {
              amPm = "PM";
            }

            // Convert to 12-hour format
            if (hour > 12) {
              hour = hour - 12;
            }
            else if (hour == 0) {
              hour = 12;
            }

            // Update the LCD with the current time
            lcd.clear();
            digitalWrite(LED_PIN, HIGH); 
            delay(200);
            digitalWrite(LED_PIN, LOW);
            lcd.setCursor(0, 0);
            lcd.print("  Current Time  ");
            lcd.setCursor(0, 1);
            lcd.print("   ");
            lcd.print(hour);
            if (minute < 10) lcd.print(":0");
            else lcd.print(":");
            lcd.print(minute);
            if (seconds < 10) lcd.print(":0");
            else lcd.print(":");
            lcd.print(seconds);
            lcd.print(" ");
            lcd.print(amPm);
            lcd.print("   ");
          }

          http.end(); // Close the HTTP connection
        }
        break;
      default:
        break;
    }

    lcdPrintCounter++;  // Increment the LCD print counter
    if (lcdPrintCounter >= numLcdPrints) {
      lcdPrintCounter = 0;  // Reset the LCD print counter if it exceeds the number of LCD prints
    }
  }

  for (int i = 0; i < numButtons; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);
  }

  // Check for button presses
  for (int i = 0; i < numButtons; i++) {
    if (buttonStates[i] == lastButtonStates[i]) {
      if (buttonStates[i] == HIGH) {
        buttonPushCounter++;
        Serial.println("on");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
        bool smsResult = sendSMS("Button pushed on ESP32. Thank you for choosing https://signalwire.com");
        bool callResult = makeCall("https://len.signalwire.com/laml-bins/bfccee39-219b-4c28-9659-31900d4da3b9"); // Example LAML Bin URL for makeCall

        delay(500);
      }
    }
  }

  // Update the last button states
  for (int i = 0; i < numButtons; i++) {
    lastButtonStates[i] = buttonStates[i];
  }
}
