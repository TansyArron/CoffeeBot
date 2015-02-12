#include <SPI.h>
#include <WiFi.h>

const char ssid[] = " ";    // Your SSID
const char pass[] = " ";    // Your Network Password

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
  status = WiFi.begin(ssid, pass);
  // if you're not connected, try again:
  if ( status != WL_CONNECTED) { 
    connectNetwork();
  }
}
