\\using DHT11 sensor
#include<dht.h>
#define dht_pin A0
dht DHT;

void Setup()
{ 
Serial.begin(9600);
  Serial.print("temp and humidity sensor");
}
void loop()
{DHT.readll(dht_pin);
 Serial.print("humidity= ");
Serial.print(DHT.humidity);
 Serial.print("temperature=");
 Serial.print(DHT.temperature)
delay(5000);
}