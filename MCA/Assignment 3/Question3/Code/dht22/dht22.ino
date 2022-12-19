#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>                         // Include DHT library code
 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
#define DHTPIN  8                        // DHT11 data pin is connected to Arduino pin 8
#define DHTTYPE DHT11                    // DHT11 sensor is used
DHT dht(DHTPIN, DHTTYPE);                // Configure DHT library
 
char temperature[] = "00.0 C";
char humidity[]    = "00.0 %";
 
void setup(void) {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
 
  dht.begin();                // Initialize the DHT library
 
  delay(1000);
 
  // Clear the display buffer.
  display.clearDisplay();
 
  display.drawFastHLine(0, 32, SSD1306_LCDWIDTH, WHITE);
 
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(10, 5);
  display.print("DHT11 TEMPERATURE:");
  display.setCursor(19, 37);
  display.print("DHT11 HUMIDITY:");
  display.display();
}
 
void loop() {
  // Read humidity
  byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  byte Temp = dht.readTemperature();
 
  temperature[0] = Temp / 10 + 48;
  temperature[1] = Temp % 10 + 48;
  humidity[0]    = RH / 10 + 48;
  humidity[1]    = RH % 10 + 48;
 
  display.setCursor(46, 20);
  display.print(temperature);
  display.setCursor(46, 52);
  display.print(humidity);
  display.drawRect(71, 20, 3, 3, WHITE);     // Put degree symbol ( ° )
  display.display();
 
  delay(1000);
 
}