byte myArray[3];
int16_t bigNum = 800;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  myArray[0] = 0x44;
  myArray[1] = (bigNum >> 8)&0xFF;
  myArray[2] = bigNum & 0xFF;
  Serial.write(myArray, 3);
  delay(1000);         
}
