/*

This is a work in progress but hopefully it will help someone else by providing
a base to start and work from.
Please check out my Youtube videos here and consider a thumbs up if this helped you!
Youtube : http://www.youtube.com/mkmeorg
Website, Forum and store are at http://mkme.org

0X3C is address for cheap ebay units
Used I2C Scanner to find address
SDA connected to pin Analog 4
SCL connected to pin Analog 5

*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  Serial.println(value);
// text display tests
display.clearDisplay();
display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(value);
  


  
 if(value<200)
  {
      Serial.println("You are sober.");
      display.println("Sober");
  }
  if (value>=200 && value<280)
  {
      Serial.println("Alcohol detected");
      display.println("Alcohol Detected");
  }
  if (value>=280 && value<350)
  {
      Serial.println("More than one drink going on here....");
      display.println("Many Drinks");
  }
  if (value>=350 && value <450)
  {
      Serial.println("Serious Booze here! ");
      display.println("Huge Booze");
  }
  if(value>450)
  {
     Serial.println("You are drunk!");
     display.println("Too Much!");
  }


display.display();
  delay (500);
}
