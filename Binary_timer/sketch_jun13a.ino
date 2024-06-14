#define LED_1 11
#define LED_2 10
#define LED_3 9
#define LED_4 6
#define LED_5 5
#define LED_6 3

int binaryArray[6] = {1, 2, 4, 8, 16, 32};
int storeOutput[6];
int storeNum = 0;
int pinValue = 0;
unsigned long targetNum = 0;

void setup() {
  digitalWrite(LED_6, LOW);
  digitalWrite(LED_5, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_1, LOW);
}

void loop() {
    delay(1000);
    targetNum++; //millis() / 1000;
    if (targetNum == 62) {
      targetNum = 0;
    }
//    Serial.begin(9600);
//    Serial.print(targetNum);
    for (int i = 5; i >= 0; i--) {
      if(storeNum + binaryArray[i] <= targetNum) {
        storeNum += binaryArray[i];
        storeOutput[i] = 1;
      } else {
        storeOutput[i] = 0;
      }
    }
    storeNum = 0;

    for(int x = 5; x >= 0; x--) {
      if (storeOutput[x] == 1) {
        pinValue = 1;
      } else {
        pinValue = 0;
      }
      switch(x) {
        case 5:
          digitalWrite(LED_6, pinValue);
          break;
        case 4:
          digitalWrite(LED_5, pinValue);
          break;
        case 3:
          digitalWrite(LED_4, pinValue);
          break;
        case 2:
          digitalWrite(LED_3, pinValue);
          break;
        case 1:
          digitalWrite(LED_2, pinValue);
          break;
        case 0:
          digitalWrite(LED_1, pinValue);
          break;
        default:
          break;
          }
    }
}
