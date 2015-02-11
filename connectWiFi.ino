#include <SPI.h>
#include <WiFi.h>

char ssid[] = " ";    // Your SSID
char pass[] = " ";    // Your Network Password

int status = WL_IDLE_STATUS;      // the Wifi radio's status
IPAddress server(10,0,0,2);       // Your Server IP 

WiFiClient client;
int AnalogPin = 0;
int val = 0;

void setup() {
  // connect to wifi
  connectNetwork();
}

void loop() {
  // check for connection to server and start sending data.
  if (client.connect(server, 6880)) {
    val = analogRead(A0);
    client.println(val);
    delay(2000);
  }
}

void connectNetwork() {
  // attempt to connect using WPA2 encryption:
  Serial.print("Attempting to connect to WPA2 network: ");
  Serial.println(ssid);
  Serial.print("using password: ");
  Serial.println(pass);
  status = WiFi.begin(ssid, pass);
  Serial.println(status);
  // if you're not connected, try again:
  if ( status != WL_CONNECTED) { 
    connectNetwork();
  }
}
