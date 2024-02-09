/**************

Techeonics

DHT11 WITH (NodeMCU)ESP8266 / ESP32
https://techeonics.com/interface-dht-11-sensor-with-esp8266/

By Gaurav Kumar (Techeonics) 
<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

********************/

/************************* Declaring Library *********************************/

#include "DHT.h" // https://github.com/adafruit/DHT-sensor-library


/************************* Declaring Pin *********************************/

#define DHTPIN D5     // Digital pin connected to the DHT sensor D5 or D2 for esp8266 / 2 for esp32


/************************* Declaring DHT Sensor Type  *********************************/
#define DHTTYPE DHT11   // DHT 11  and DHT22 for dht22 module 


/************************* Declaring Object for DHT class  *********************************/
DHT dht(DHTPIN, DHTTYPE);


void setup()
{
  Serial.begin(115200); // Beginning Serial Communication with Computer

  dht.begin(); // beginning communication with Sensor
}

void loop()
{

  // Read humidity
  float h = dht.readHumidity();

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  /************************* Printing Data on Serial Monitor  *********************************/
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  delay(2000);
}
