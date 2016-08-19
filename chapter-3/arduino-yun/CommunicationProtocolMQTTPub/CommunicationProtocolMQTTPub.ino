/***************************************************************************
 * Sketch Name: Communication Protocols - MQTT Publish
 * Description: This sketch illustrates how Arduino Yun can publish to an
                MQTT broker
 * Created On:  February 15, 2016
 * Author:      Adeel Javed
 * Book:        Building Arduino Projects for the Internet of Things
 * Chapter:     Chapter 03 - Communication Protocols
 * Website:     http://codifythings.com
 **************************************************************************/

/***************************************************************************
 * External Libraries
 **************************************************************************/
 
#include <Process.h>
#include <YunClient.h>
#include <PubSubClient.h>

/***************************************************************************
 * Internet Connectivity Setup - Variables & Functions
 **************************************************************************/
 
// Yun client already connected to the internet
YunClient client;

void printConnectionInformation() 
{  
  // Initialize a new process
  Process wifiCheck;

  // Run Command
  wifiCheck.runShellCommand("/usr/bin/pretty-wifi-info.lua");

  // Print Connection Information  
  while (wifiCheck.available() > 0) 
  {
    char c = wifiCheck.read();
    Serial.print(c);
  }

  Serial.println("-----------------------------------------------");
  Serial.println("");
}

/***************************************************************************
 * Data Publish - Variables & Functions
 **************************************************************************/

// IP address of the Mosquitto server
char server[] = {"test.mosquitto.org"};
int port = 1883;
char topic[] = {"codifythings/testMessage"};

PubSubClient pubSubClient(server, port, 0, client);

void publishData()
{
  // Publish to MQTT Topic
  if (pubSubClient.connected()) 
  {    
    Serial.println("Publishing to MQTT Broker");
    pubSubClient.publish(topic, "Test Message");
  }

  Serial.println("[INFO] Publish to MQTT Broker Complete");
  Serial.println("-----------------------------------------------");
  
  pubSubClient.loop();
}

/***************************************************************************
 * Standard Arduino Functions - setup(), loop()
 **************************************************************************/

void setup() 
{
  // Initialize serial port
  Serial.begin(9600);
  
  // Do nothing until serial monitor is opened
  while (!Serial);     

  // Contact the Linux processor
  Bridge.begin();  
  
  // Print connection information
  printConnectionInformation();
  
  // Connect MQTT Broker
  Serial.println("[INFO] Connecting to MQTT Broker");
  if (pubSubClient.connect("arduinoClient")) 
  {
    Serial.println("[INFO] Connection to MQTT Broker Successfull");
  }
  else
  {
    Serial.println("[INFO] Connection to MQTT Broker Failed");
  }
  
  // Publish data to MQTT broker
  publishData();
}

void loop() 
{    
  // Do nothing  
}
