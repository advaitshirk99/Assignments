const int SSPin = 8;
const int SCKPin = 9;
const int MISOPin = 10;
const int MOSIPin = 11;

byte sendData = 32; 
byte slaveData = 0;  

byte bitBangData(byte _send)  // This function transmit the data via bitbanging
{
  byte _receive = 0;

  for(int i=0; i<8; i++)  // 8 bits in a byte
  {
    digitalWrite(MOSIPin, bitRead(_send, i));    // Set MOSI
    digitalWrite(SCKPin, HIGH);                  // SCK high
    bitWrite(_receive, i, digitalRead(MISOPin)); // Capture MISO
    digitalWrite(SCKPin, LOW);                   // SCK low
  } 
  return _receive;        // Return the received data
}

void setup() {
 pinMode(MISOPin, INPUT);
 pinMode(SSPin, OUTPUT);
 pinMode(SCKPin, OUTPUT);
 pinMode(MOSIPin, OUTPUT);
 digitalWrite(SSPin, HIGH);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(SSPin, LOW);       
  slaveData = bitBangData(sendData); 
  digitalWrite(SSPin, HIGH);    
  Serial.println("Slave data:"+(String)slaveData);  
  
}