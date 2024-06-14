//www.kuongshun.com
//2023.10.11

// Define Pins
#define BLUE 5
#define GREEN 3
#define RED 6

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
  #define delayTime 10 // fading time between colors
  
  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 255;
  blueValue = 0;

  analogWrite(RED, redValue);
  analogWrite(BLUE, blueValue);
  analogWrite(GREEN, greenValue);
}
