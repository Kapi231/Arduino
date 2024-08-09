#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )

short years = 1;
short months = 12;
short days = 365;
short mm, dd = 0;

void setup()
{
    lcd.init();
    lcd.backlight();
}

void Display() 
{
  lcd.setCursor(0, 1); 
  if(years<10)
  {
    lcd.print(" ");
    lcd.print(years);
    lcd.print("Y");
  }
  else
  {
    lcd.print(years);
    lcd.print("Y");
  }

  if(months<100)
  {
    lcd.print("  ");
    lcd.print(months);
    lcd.print("M");
  }
  else
  {
    lcd.print(months);
    lcd.print("M");
  }

  lcd.print(" ");
  if(days<1000)
  {
    lcd.print(" ");
    lcd.print(days);
    lcd.print("D");
  }
  else
  {
    lcd.print(days);
    lcd.print("D");
  }

  delay(5000);
}

void loop()
{
  //short hours = 0;
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print(" O+S RAZEM OD:");
  int seconds = 0;
  int now, last_time;

  while (now - last_time < 1000)  {
  now = millis();    
  }
  last_time = now;
  seconds++;
  if(seconds>=86400)
  {
    dd++;
    days++;
    seconds = 0;
  }
  if(dd>=30)
  {
    mm++;
    months++;
    dd = 0;
  }
  if(mm>=12)
  {
    years++;
    mm = 0;
  }
  Display();
}

