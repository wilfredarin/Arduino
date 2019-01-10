//pin definitions
int ledPin = 13;
int buttonPin = 2;

//global variable
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress;//LONG DOUBLES THE SIZE
int debounceTime = 20;



void setup() {
  // set pin modes
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin ,INPUT_PULLUP);

}

void loop() {
  // put your main code here :- read the state of buttonPin as [0 or 1 ]
  int buttonState = digitalRead(buttonPin);

/*millis record the time since program initiated --
//debouncing
//solving the bouncing
//mechanical object has inertia
//bouncing when switch pressed
//in using as toggle switch happening very quickly 
//so it will register it the bounce
// so its a noise

//last press initalise at 0
*/
  
  if((millis() - lastPress) > debounceTime)
  {
      lastPress =millis();//update lastPress

      if (buttonState == 0 && lastButtonState ==1)//if button is pressed and was released last change
      {
        toggleState =! toggleState; //toggle the LED STATE
        digitalWrite(ledPin, toggleState);
        lastButtonState = 0; //record the last button state
      }

      if(buttonState ==1 && lastButtonState ==0) // if button is not pressed, and was presed last change
      {
        lastButtonState ==1; // record the lastButtonState
      }

  }
 
}
  
  
