String a;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  
  if (Serial.available())                        // checking if data is received/available 
  {                  
           a = Serial1.read();
           Serial2.println(a);
           delay(500);                          

  }
}
