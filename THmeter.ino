#include <Adafruit_Sensor.h>
#include "DHT.h"  
#include <Wire.h>  
#include "SSD1306Wire.h" 

#define DHTPIN 2     // Digital pin connected to the DHT sensor
DHT dht(DHTPIN,DHT11);  // DHT11 LIBRARY  

SSD1306Wire  display(0x3c, D2, D1);  //Initialize the OLED display, D2=SDK  D1=SCK  As per labeling on NodeMCU

 void setup()  
 {  
  Serial.begin(115200);  
  Serial.println("");

  dht.begin();

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
 }  
 void loop()  
 {  
   delay(2000);  
   Serial.println("Temperature in C:");  
   float t = dht.readTemperature( );
   Serial.println(t);  
   Serial.println("Humidity in C:");  
   float h = dht.readHumidity();
   Serial.println(h); 
   if (!isnan(t) && !isnan(h)) {
    displayValues(t, h);
  } 
 }  

 void displayValues(float temp, float humi) {
  // clear the display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.setColor(WHITE);
  display.drawString(0, 0, "Temperature: ");
  display.drawString(0, 32, "Humidity: ");
   display.drawString(56, 16, String(temp)+" °C");
  display.drawString(56, 48, String(humi)+" %");
  // write the buffer to the display
  display.display();
}
