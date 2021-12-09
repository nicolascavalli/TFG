String a;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  
  if (Serial.available())
  {                  
           a = Serial1.read();
           Serial2.println(a);
           delay(500);                          

  }
}
