/*EEPROM elephant in the room
 * 
 * solid state non volatile memory
 * small amount of data stored 
 * rated life expetency
 * 100000 ryt cycle
 * constantly updating the code : stops working
 well leveling 
 
 store eprom
 * 
 * 
 * 
 * typical size 512kb smalldata
 * specifying addres and action read write or erase
 * 1023 kb of eeprom to use
 * rated life expectancy
 * only write to each adrres limited time
 * constantly updating thng eeprom may fail
 * 
 * change to fresh adrss if it reaches a limit
 */
#include <EEPROM.h>
//

//pin definitions
int ledPin = 13;
int buttonPin = 2;

//global varibles
int lastButtonState = 1;
long unsigned int lastPress;
int debounceTime = 20;
int counter;

 
 void setup(){
 pinMode(ledPin,  OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);

 //initialise Serial port
 Serial.begin(9600);

  // toggle button function if statement
  //takes one arg address to read from -- 0
 //assign counter the value of address 0
 counter = EEPROM.read(0);

 //write a 0 to address 0.This allows for the consecuti
//2 arg adress to write to , value to rite to
 EEPROM.write(0,0);
 }

 void loop(){
    int buttonState = digitalRead(buttonPin);//read the state of the buttonPin and store it as 0 or 1 
    if((millis() - lastPress > debounceTime)) //if the time between the last buttonChange is greater than the debounceTime
    {
      lastPress = millis(); //update last press 
    }
    if(buttonState == 0 && lastButtonState == 1); //if the time between the last buttonChange is greater than the debounceTime
    {
      counter++;//increment by one
      EEPROM.write(0, counter);//write counter to address 0
      digitalWrite(ledPin, HIGH);//momentary LED
      lastButtonState = 0; //record the lastButtonState
      //print the results
      Serial.print("Counter: ");
      Serial.print(counter);
    }

    if (buttonState == 1 && lastButtonState ==0)// if buttom is not pressed, and was pressed last change 
    {
      lastButtonState = 1; // record the lastButtonState
      digitalWrite(ledPin, LOW); //momentary LED


    }

 }

      
   
 
