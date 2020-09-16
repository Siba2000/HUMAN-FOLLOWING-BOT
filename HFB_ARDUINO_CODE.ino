#include<Wire.h>


#include <ESP8266WiFi.h>
const char* ssid = "SPRATHA";    // Enter SSID here
const char* password = "22200000";  //Enter Password here
const char* server = "192.168.1.105";

WiFiClient server1;
int s1,s2;
void setup() {
  Serial.begin(9600);
  delay(1000);
 
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
    Serial.println("WiFi connected");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (! server1.connect(server, 8080))
    Serial.println("Failed to connect to server");
  while (1)
  {
    while (server1.available()) {
      s1 = server1.readStringUntil('*').toInt();
      if(s1!=0)
      Serial.println(s1);
      s2 = server1.readStringUntil('*').toInt();
      if(s2!=0)
      Serial.println(s2);
      
    }
  }
 
}  
