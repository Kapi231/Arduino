#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )

int seconds = 0;
int minutes = 0;
int hours = 0;
int now, last_time, minutesBtn, hoursBtn;
String hDisplay, mDisplay, sDisplay; // Strings for display output

void setup()
{
    lcd.init();
    lcd.backlight();
    
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
}
 
void loop()
{
  hoursBtn = digitalRead(2);
  if (hoursBtn) {
    hours++;
  }
  minutesBtn = digitalRead(4);
  if (minutesBtn) {
    minutes++;
  }
  
  while (now - last_time < 1000)  {
    now = millis();    
  }
  last_time = now;
  seconds++;

  if (seconds >= 60){
    minutes++;
    seconds = 0;
  }
  if (minutes >= 60) {
    minutes = 0;
    hours++;
  }
  if (hours >= 24) {
    hours = 0;
  }

  if (hours < 10) {
    hDisplay = "0" + String(hours);
  } else {
    hDisplay = String(hours);
  }
  if (minutes < 10) {
    mDisplay = "0" + String(minutes);
  } else {
    mDisplay = String(minutes);
  }
  if (seconds < 10) {
    sDisplay = "0" + String(seconds);
  } else {
    sDisplay = String(seconds);
  }
  
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("CLOCK!");
  lcd.setCursor(0, 1);
  lcd.print(hDisplay + ":" + mDisplay + ":" + sDisplay);
}
