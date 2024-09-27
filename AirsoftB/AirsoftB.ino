#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27, 16, 2);

char PIN[7];
char def_pin[7];
short curPos = 0;
short t = 0;
bool isPlanted = false;
bool isDefused = false;

int now = 0;
int last_time;
int sec;
short set_time = 60;

void timer()
{
  now = millis();
  if (now - last_time > 1000) 
  { 
    last_time = now;
    sec++; 
  }
}

void setup() {
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);

  lcd.init();
  lcd.backlight();
}

void loop() 
{ 
  char key = keypad.getKey();

  if (!isPlanted)
  {
    lcd.setCursor(0, 0);
    lcd.print("Insert PIN:");
    lcd.setCursor(0, 1);
    lcd.print(PIN);
    
    if (key)
    {
      digitalWrite(10, HIGH);
      if (key == 'D')
      {
        if (curPos > 0)
        {
          PIN[curPos - 1] = 0;
          curPos--;
        }
      }

      else if (curPos < 6)
      {
        PIN[curPos] = key;
        curPos++;
      }
      lcd.clear();
      delay(100);
      digitalWrite(10, LOW);

      key = 0;
    }

    if(curPos == 6)
    {
      isPlanted = true;
      lcd.clear();
      lcd.print(" BOMB HAS BEEN ");
      lcd.setCursor(0,1);
      lcd.print("   PLANTED !");
      delay(2000);
      lcd.clear();
      curPos = 0;
    }
  }

  if (isPlanted)
  {
    timer();

    if (!isDefused)
    {
      lcd.setCursor(0, 0);
      lcd.print("  DEFUSING ...");
      lcd.setCursor(0,1);
      lcd.print("Time: ");
      lcd.print(set_time - sec);
      lcd.print("  ");
      lcd.print(def_pin);

      if (key)
      {
        digitalWrite(10, HIGH);
        if (curPos < 6)
        {
          def_pin[curPos] = key;
          curPos++;
        }
        lcd.clear();
        delay(100);
        digitalWrite(10, LOW);

        key = 0;
      }

      if (curPos == 6)
      {
        //lcd.print("dupa");
        lcd.clear();
        if (strcmp(PIN, def_pin) == 0) // trzeba ogarnac jak przyrownac dwie tablice charow do siebie 
        {                                   // Above done ! 
          isDefused = true;
          lcd.print("   WELL DONE");
          lcd.setCursor(0,1);
          lcd.print("    SOLDIER");
          delay(2000);
        }
        else
        {
          isDefused = true;
          t += 1;
          if(t == 3)
          {
            lcd.print("  YOU ARE DEAD!");
            lcd.setCursor(0,1);
            lcd.print( "   SKULL.JPG  ");
            delay(2500);
          }
          else
          {
            isDefused = true;
            curPos = 0;
            lcd.clear();
            lcd.print("     WRONG!");
            delay(1000);
            lcd.setCursor(0,1);
            lcd.print("Chances left: ");
            lcd.print(3-t);
            delay(2000);
            lcd.clear();
            short size = sizeof(def_pin)/sizeof(def_pin[0]);
            for (short i = 0; i<size; i++)  // zwalnianie(zerowanie) miejsca w tablicy def_pin[]
            {
              def_pin[i] = 0;
            }
            isDefused = false;
          }
        }
      }
    }
  }
}
