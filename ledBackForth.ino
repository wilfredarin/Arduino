int ledArray[] = {2,3,4,5,6,7,8,9};
int delayTime = 150;


void setup() {
  // initilaliseledArray as outputs
  for(int i; i<10; i++)
  {
    pinMode(ledArray[i],OUTPUT);
  }

}

void loop() {
  // Turns LEDs on from 0-7
  for(int i; i<= 7; i++)
  {
    digitalWrite(ledArray[i],HIGH);
    delay(delayTime);
  }
  // Turns leds off from 7-0
  for(int i =7; i >= 0; i--)
  {
    digitalWrite(ledArray[i],LOW);
    delay(delayTime);

  }
}
  
}
