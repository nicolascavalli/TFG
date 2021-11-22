#include <SPI.h>
#include <DHT.h>

#define dht_1 7
#define DHTTYPE DHT11
DHT dht(dht_1, DHTTYPE);

const int slaveSelectPin = 10;

void setup() 
{
  SPI.begin();
  pinMode(slaveSelectPin, OUTPUT);
  Serial.begin(9600); 
  dht.begin();
}

void loop() 
{
  
  digitalWrite(slaveSelectPin, LOW);
  delay(100);
  
  int temp = dht.readTemperature();
  Serial.println(temp);
  
  // Master sends decimal 65 to slave
  //test variable recieves any data sent by the slave to the master
  char test=SPI.transfer(temp);
  delay(500);
  digitalWrite(slaveSelectPin, HIGH);
  //Serial.println(test);

}
