void setup() {
  // initialise Serial port
  Serial.begin(9600);

}

void loop() {
  int a;
  int b;
  float result;

  
  // print instructions, and wait untill there is something in the serial buffer
  Serial.print("Enter a side value: ");
  while(!Serial.available())//keep chekking for input
  a = readSerial();

  Serial.print("Enter the other side value: ");
  while(!Serial.available());
  b = readSerial();

  findSide(a,b);
  Serial.println();
  
  
}


//readSerial takes the next intiger in the Serial buffer
//clears the buffer, then returns it
int readSerial()
{
  int i = Serial.parseInt();
  if(i < 1)
  {
    return;
  }
  Serial.println(i);
  Serial.parseInt();
  return i;
}

int findSide(int x,int y)
{
  //calculate c squared by A aquared + B squared
  float hypotenuse = sqrt(x*x + y*y);

  //print out the result
  Serial.print("Hypotenuse = ");
  Serial.println(hypotnuse);
}
}
}
