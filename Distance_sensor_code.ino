// C++ code
//
const int trig = 13; //Declare variable "trig" as integer to store trigger data at pin 13
const int echo = 12; //Declare variable "echo" as integer to store echo data at pin 12

float duration, distance; //Declaring varibles for distance and duration

void setup()
{
  
  pinMode(trig, OUTPUT); //Setup trig as output
  pinMode(echo, INPUT);  //Setup echo as input
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);   //Setup pins 2,3,4 as input
  
  
  
  Serial.begin(9600); //Starting the serial monitor
  Serial.println("Setup complete"); //Checking the Serial monitor is ON
}

void loop()
{
  digitalWrite(trig, LOW); //To make sure the trig pin is off at the start
  delayMicroseconds (2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds (10); //Using trigger pin to send a pulse for 10 microseconds
  
  digitalWrite(trig, LOW);// Turning trig off 
  
  duration = pulseIn(echo, HIGH); //Pulse as the duration
  
  distance = (duration*.0343)/2; //Distance is the duration muiltiplied by the speed of sound which is 0.0343 centimeter/microsecond
                                  //The distance is doubled since it travels to the target and back again, so we need to divide it by 2
  
  Serial.println(distance);// displaying the distance in centimeters
  

  
  delay(100);
  
    if (distance >=150) // if statement to turn on LEDs as object moves closer to sensor
  {
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  else if (distance >= 100)
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
    
  else if (distance >= 50)
    
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }
  
  else 
    
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
}