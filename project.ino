//using DHT11 sensor
#include<dht.h>//humidity
#define dht_pin A1
dht DHT ;
int light;//to store analog values of intensity
void setup()
{ 
  Serial.print(" intensity,temp and humidity sensor");
  Serial.begin(9600);//begin interaction with serial 
}
void loop()
{
 light=analogRead(A0);//read the intensity
 DHT.readll(dht_pin);//reading humidity and temp
 if(light<250)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
 Serial.print("light intenity : ");
 Serial.println(light);//light intensity
 Serial.print("humidity : ");
 Serial.println(DHT.humidity);// humidity using DHT
 Serial.print("temperature : ");// temperature using DHT
 Serial.println(DHT.temperature)
 delay(5000);
}