// Copyright Nat Weerawan 2015-2016
// MIT License

#include <ESP8266WiFi.h>
#include <WiFiConnector.h>

/*
  WIFI INFO
*/

#define WIFI_SSID        "Nat"
#define WIFI_PASSPHARSE  "guestguest"


/* 
  USE EMPTRY CONSTRUCTOR TO USE SMARTCONFIG CONFIGURATIONS
  LIKE THIS
  WiFiConnector wifi = WiFiConnector();
*/

WiFiConnector wifi = WiFiConnector(WIFI_SSID, WIFI_PASSPHARSE);

void init_hardware()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("BEGIN");

  // SETUP CALLBACKS
  wifi.on_connecting([&](const void* message)
  {
    char buffer[70];
    sprintf(buffer, "[%d] connecting -> %s ", wifi.counter, (char*) message);
    Serial.println(buffer);
    delay(500);
  });

  wifi.on_connected([&](const void* message)
  {
    // Print the IP address
    Serial.print("WIFI CONNECTED => ");
    Serial.println(WiFi.localIP());
  });

}

void setup()
{
  init_hardware();

  Serial.print("CONNECTING TO ");
  Serial.println(wifi.SSID() + ", " + wifi.psk());

  wifi.connect();

}

void loop()
{
  wifi.loop();
}