/**************

Techeonics

DHT11 With ESP8266/esp32 to send data 
to the thingspeak cloud and display on the dashboard
https://techeonics.com/setup-thingspeak-with-esp-dht11/

By Gaurav Kumar (Techeonics) 
<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

********************/
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

const char* ssid = "xxx"; // Name of the Network.
const char* password = "xxxx"; // Password of the Network.

WiFiClient client; // Create a Wi-Fi client to connect to ThingSpeak.

unsigned long myChannelNumber = 1; // Channel No
const char * myWriteAPIKey = "xxxxxxxxx"; // API write key.


#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); // This will connect the Node MCU with WiFi.
  WiFi.mode(WIFI_STA); // Set the Node MCU as a Wi-Fi station.
  ThingSpeak.begin(client); // Initialize ThingSpeak.

  dht.begin();
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("\nConnected. ");
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
   //the channel number.
  //the field number (in our case, we just have one field).
  //the value you want to publish (x).
  //your write API key.
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
 
}
