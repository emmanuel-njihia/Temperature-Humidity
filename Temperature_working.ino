#include <DHT.h>
#include <DHT_U.h>



#define DHTPIN 2
#define DHTTYPE DHT22

//Declare DHT object:
DHT dht(DHTPIN, DHTTYPE);
//Intialize the sensor.
int dt=2000; //3 seconds



void setup (){
  Serial.begin(115200); 
  dht.begin();
    pinMode(buzzPin,OUTPUT);
}

void loop (){
// delay(300000);
 delay(2 seconds);
//read humidity
float humi = dht.readHumidity();
//read temperature as Celsius
float tempC = dht.readTemperature();
//read temperature as Farenheit
float tempF = dht.readTemperature(true);



//Trigger Sensor
  if (tempC>30){
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  }

//check if any leads failed
if (isnan(humi) || isnan(tempC) || isnan(tempF)){
  Serial.println("Failed to read from DHT sensor!");

}else {
// Serial.print("The Temp is:");
//   Serial.print(humi);
   Serial.print("Temperature:");
  Serial.print(tempC);
  Serial.print(",");
    
 

  Serial.print("Humidity:");
  Serial.println(humi);
    // Serial.print(",");
   
 

}
}


