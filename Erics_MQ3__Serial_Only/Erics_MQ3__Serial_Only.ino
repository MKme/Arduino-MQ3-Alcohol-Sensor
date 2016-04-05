/*

This is a work in progress but hopefully it will help someone else by providing
a base to start and work from.
Please check out my Youtube videos here and consider a thumbs up if this helped you!
Youtube : http://www.youtube.com/mkmeorg
Website, Forum and store are at http://mkme.org

*/

const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  Serial.println(value);
 if(value<200)
  {
      Serial.println("You are sober.");
  }
  if (value>=200 && value<280)
  {
      Serial.println("Alcohol detected");
  }
  if (value>=280 && value<350)
  {
      Serial.println("More than one drink going on here....");
  }
  if (value>=350 && value <450)
  {
      Serial.println("Serious Booze here! ");
  }
  if(value>450)
  {
     Serial.println("You are drunk!");
  }

  delay (500);
}
