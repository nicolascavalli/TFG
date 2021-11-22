#include<SPI.h>

bool flag=0;
byte s_recv;

void setup() {
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);

  //SPI slave mode
  SPCR = (1<<SPE)|(1<<SPIE); //enable spi module and interrupt
  sei(); //global interrupt enable
}

ISR (SPI_STC_vect)
{
  s_recv= SPDR; //data received from master is stored in SPDR
  flag=1;
}


void loop() {

  Serial.println(s_recv);
  if(flag)
  {
    SPDR = 'F'; //send data back to master
  }
  delay(500);

}
