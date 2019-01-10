//pin definitions
int ledPin = 13;
int buttonPin = 2;

//global varaiables
int toggleState;
int buttonState = 1;

void setup()
{

  //setup pin modes
  pinMode(ledPin , OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  
}



void loop() {
  buttonState = digitalRead(buttonPin);
  while(buttonState ==0) //while button is pressed
  {
    toggleState =! toggleState;//change the state
    digitalWrite(ledPin,toggleState);//write the state
    delay(50);//keep it in same state for 50 mill sec
    buttonState = digitalRead(buttonPin);//again check if its still pressed or not  
  } 
  toggleState =!toggleState;
  //so if it comes out of loop it means its state changed 
 //so register that change in toggleState variable
  digitalWrite(ledPin,toggleState);
  delay(200); 
 }


 
