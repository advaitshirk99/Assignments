#include <Wire.h>
#define i2c_addr 0x50
#define max_addr 20

void writeEeprom(int address, byte val){ //framing |start|i2c_addr|address to write(MSB)|address to write (LSB)|data (8-bits)|stop bit|
  Wire.beginTransmission(i2c_addr);
  Wire.write((int)(address >> 8));   
  Wire.write((int)(address & 0xFF)); 
  Wire.write(val);
  Wire.endTransmission();
  delay(5);
}

byte readEeprom(int address){ 
  byte rcvData = 0;
  Wire.beginTransmission(i2c_addr);
  Wire.write((int)(address >> 8));   
  Wire.write((int)(address & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr, 1);
  rcvData =  Wire.read();
  return rcvData;
}

void setup(){
  Wire.begin();
  Serial.begin(9600);
}

void loop(){
  unsigned int addr=0;
  //write to addr
  byte a[]={12,25,42,34,89,100,232,76,19,205,2,5,41,74,82,110,201,167,69,208};
  //write the array to eeprom starting address 0
  for(addr=0;addr<max_addr;addr++){ 
    writeEeprom(addr,a[addr]);
  }

   //read the array from the eeprom starting address 0
  for(addr=0;addr<max_addr;addr++){
    Serial.println("Value at addr "+(String)addr + ": " +readEeprom(addr));
      delay(100);
  } 

  Serial.println();
  Serial.println("----Read/Write Complete----");
  while(1);
}
