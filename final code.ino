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
 Serial.print("light intenity : ");
 Serial.println(light);//light intensity
 Serial.print("humidity : ");
 Serial.println(DHT.humidity);// humidity using DHT
 Serial.print("temperature : ");// temperature using DHT
 Serial.println(DHT.temperature);
 Serial.println("Surroundings Status: ");
 //Displaying lighting forecast
  if(light<250)
  {
    digitalWrite(13,HIGH);
    Serial.println("Dark ,");
  }
  else if(light>=250&&light<600)
  {
    Serial.println("Good lighting ,");
    digitalWrite(13,LOW);
  }
  else
  {
    Serial.println("Bright ,");
    digitalWrite(13,LOW);
  }
  
  // Displaying temperature forecast
  if(DHT.temperature<5)
  {
    Serial.print(" Freezing cold");
  }
  else if(DHT.temperature<15)
  {
    Serial.print(" Cold");
  }
  else if(DHT.temperature<30)
  {
    Serial.print(" Warm");
  }
  else
  {
    Serial.print(" Hot");
  }
  
  // Displaying Humidity forecast
  if(DHT.humidity<50)
  {
    Serial.print(" and Dry");
  }
  else
  {
    Serial.print(" and Humid");
  }
 delay(5000);
}