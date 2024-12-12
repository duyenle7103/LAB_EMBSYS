#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

//Wifi name
#define WLAN_SSID       "Redmi Note 11"
//Wifi password
#define WLAN_PASS       "531327aA"

//Setup Adafruit
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
//Fill your username                   
#define AIO_USERNAME    "Duyen"
//Fill your key
#define AIO_KEY         ""

//Setup MQTT
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

//Setup publish
Adafruit_MQTT_Publish temperature_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");

int led_counter = 0;
int led_status = HIGH;

void setup() {
  //Put your setup code here, to run once:
  //Set pin 2,5 as OUTPUT
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  //Set busy pin HIGH
  digitalWrite(5, HIGH);

  Serial.begin(115200);

  //Connect Wifi
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  //Connect MQTT
  while (mqtt.connect() != 0) { 
    mqtt.disconnect();
    delay(500);
  }

  //Finish setup, set busy pin LOW
  digitalWrite(5, LOW);
}

void loop() {
  //Put your main code here, to run repeatedly:
  
  //Read serial
  if (Serial.available()) {
    String data = Serial.readStringUntil('#'); // Read data until '#'
    if (data.startsWith("!TEMP:")) {
      // Extract temperature value
      float temperature = data.substring(6).toFloat();
      Serial.print("Sending temperature: ");
      Serial.println(temperature);

      // Publish temperature to Adafruit
      if (!temperature_pub.publish(temperature)) {
        Serial.println("Failed to publish temperature!");
      }
    }
  }

  led_counter++;
  if (led_counter == 100) {
    //Every 1s
    led_counter = 0;
    //Toggle LED
    if (led_status == HIGH) led_status = LOW;
    else led_status = HIGH;
    digitalWrite(2, led_status);
  }
  delay(10);
}
