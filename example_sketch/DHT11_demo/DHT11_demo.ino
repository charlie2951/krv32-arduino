#include "dht11.h"

#define DHT_PIN 0 //gpio-0 i.e. JB[1]
uint32_t temperature, humidity;

void setup() {
  // put your setup code here, to run once:
dht11_init(DHT_PIN);//DHT pin 
Serial.println("DHT11 interfacing demo...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int ret = dht11_read_temperature_humidity(&temperature, &humidity);
  if(!ret)
  Serial.print("Temp:");
  Serial.println(temperature);
  Serial.print("Humidity:");
  Serial.println(humidity);
  delay(5000);

}
