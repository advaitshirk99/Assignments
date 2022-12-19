const int SSPin = 8;
const int SCKPin = 9;
const int MISOPin = 10;
const int MOSIPin = 11;

byte sendData=85;

byte bitBangData(byte _send)  // This function transmit the data via bitbanging
{
  byte _receive = 0;

  for(int i=0; i<8; i++)  // 8 bits in a byte
  {
    digitalWrite(MISOPin, bitRead(_send, i));    // Set MOSI
    digitalWrite(SCKPin, HIGH);                  // SCK high
    bitWrite(_receive, i, digitalRead(MOSIPin)); // Capture MISO
    digitalWrite(SCKPin, LOW);                   // SCK low
  } 
  return _receive;        // Return the received data
}

void setup(){
 pinMode(MISOPin,OUTPUT);
 pinMode(SSPin, INPUT);
 pinMode(SCKPin, INPUT);
 pinMode(MOSIPin, INPUT);
 Serial.begin(9600);
}

void loop() {
while(digitalRead(SSPin));
byte recv=bitBangData(sendData);
Serial.println("Master Data:"+(String)recv);
}