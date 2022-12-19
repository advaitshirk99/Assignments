#include <LiquidCrystal.h>
// include Wire library code (needed for I2C protocol devices)
#include <Wire.h>

// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
pinMode(8, INPUT_PULLUP);                       // button1 is connected to pin 8
pinMode(9, INPUT_PULLUP);                      // button2 is connected to pin 9
// set up the LCD's number of columns and rows
lcd.begin(16, 2);
Wire.begin();                                  // Join i2c bus
}

char Time[] = "TIME : : : ";
char Calendar[] = "DATE: / /20";
byte i, second, minute, hour, date, month, year;

void DS3231_display(){
  // Convert BCD to decimal
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour   = (hour >> 4)   * 10 + (hour & 0x0F);
  date   = (date >> 4)   * 10 + (date & 0x0F);
  month = (month >> 4)  * 10 + (month & 0x0F);
  year   = (year >> 4)   * 10 + (year & 0x0F);
  // End conversion
  Time[12]     = second % 10 + 48;
  Time[11]     = second / 10 + 48;
  Time[9]      = minute % 10 + 48;
  Time[8]      = minute / 10 + 48;
  Time[6]      = hour   % 10 + 48;
  Time[5]      = hour   / 10 + 48;
  Calendar[14] = year   % 10 + 48;
  Calendar[13] = year   / 10 + 48;
  Calendar[9]  = month  % 10 + 48;
  Calendar[8]  = month  / 10 + 48;
  Calendar[6]  = date   % 10 + 48;
  Calendar[5]  = date   / 10 + 48;
  lcd.setCursor(0, 0);
  lcd.print(Time);                               // Display time
  lcd.setCursor(0, 1);
  lcd.print(Calendar);                           // Display calendar
}
void blink_parameter(){
  byte j = 0;
  while(j < 10 && digitalRead(8) && digitalRead(9)){
    j++;
    delay(25);
  }
}
byte edit(byte x, byte y, byte parameter){
  char text[3];
  while(!digitalRead(8));                        // Wait until button (pin #8) released
  while(true){
    while(!digitalRead(9)){                      // If button (pin #9) is pressed
    parameter++;
    if(i == 0 && parameter > 23)               // If hours > 23 ==> hours = 0
      parameter = 0;
    if(i == 1 && parameter > 59)               // If minutes > 59 ==> minutes = 0
      parameter = 0;
    if(i == 2 && parameter > 31)               // If date > 31 ==> date = 1
      parameter = 1;
    if(i == 3 && parameter > 12)               // If month > 12 ==> month = 1
      parameter = 1;
    if(i == 4 && parameter > 99)               // If year > 99 ==> year = 0
      parameter = 0;
    sprintf(text,"%02u", parameter);
    lcd.setCursor(x, y);
lcd.print(text);
delay(200);                                // Wait 200ms
}
lcd.setCursor(x, y);
lcd.print("  ");                             // Display two spaces
blink_parameter();
sprintf(text,"%02u", parameter);
lcd.setCursor(x, y);
lcd.print(text);
blink_parameter();
if(!digitalRead(8)){                         // If button (pin #8) is pressed
  i++;                                       // Increament 'i' for the next parameter
  return parameter;                          // Return parameter value and exit
}
}
}

void loop() {
if(!digitalRead(8)){                           // If button (pin #8) is pressed
  i = 0;
  hour   = edit(5, 0, hour);
minute = edit(8, 0, minute);
date   = edit(5, 1, date);
month = edit(8, 1, month);
year   = edit(13, 1, year);
      // Convert decimal to BCD
minute = ((minute / 10) << 4) + (minute % 10);
hour = ((hour / 10) << 4) + (hour % 10);
date = ((date / 10) << 4) + (date % 10);
month = ((month / 10) << 4) + (month % 10);
year = ((year / 10) << 4) + (year % 10);
      // End conversion
      // Write data to DS3231 RTC
Wire.beginTransmission(0x68);               // Start I2C protocol with DS3231 address
Wire.write(0);                              // Send register address
Wire.write(0);                              // Reset sesonds and start oscillator
Wire.write(minute);                         // Write minute
Wire.write(hour);                           // Write hour
Wire.write(1);                              // Write day (not used)
Wire.write(date);                           // Write date
Wire.write(month);                          // Write month
Wire.write(year);                           // Write year
Wire.endTransmission();                     // Stop transmission and release the I2C bus
delay(200);                                 // Wait 200ms
}
Wire.beginTransmission(0x68);                 // Start I2C protocol with DS3231 address
Wire.write(0);                                // Send register address
Wire.endTransmission(false);                  // I2C restart
Wire.requestFrom(0x68, 7);                    // Request 7 bytes from DS3231 and release I2C bus at end of reading
second = Wire.read();                         // Read seconds from register 0
minute = Wire.read();                         // Read minuts from register 1
hour   = Wire.read();                         // Read hour from register 2
Wire.read();                                  // Read day from register 3 (not used)
date   = Wire.read();                         // Read date from register 4
month = Wire.read();                         // Read month from register 5
year   = Wire.read();                         // Read year from register 6
DS3231_display();                             // Diaplay time & calendar
delay(50);                                    // Wait 50ms
}