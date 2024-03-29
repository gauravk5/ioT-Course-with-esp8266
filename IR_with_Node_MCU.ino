/**************

Techeonics

ir with esp8266

By Gaurav Kumar (Techeonics) 
<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

********************/
int IR = D1; //Define the pin Name.
void setup() {
  Serial.begin(9600); //Begin the serial communcation between Node MCU and Serial monitor.
  pinMode(IR, INPUT); // Declare the sensor as Input.
}

void loop() {
  int s = digitalRead(IR); //This will read the sensor data and store it in a variable.
  Serial.println(s); //This will print the sensor data to serial monitor.
}
