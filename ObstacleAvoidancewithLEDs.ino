/* Using HC-SR04 Sensor
STEM Center USA - Pi-Bot 

VCC pin connected to Arduino +5V
GND pin connected  to Arduino Ground
TRIG pin connected digital pin 2
ECHO pin connected digital pin 4

Motors Connected to Pins 3,5, 6 and 11
*/
 
//Define integer constants
const int trigPin = 2; //Arduino pin 2
const int echoPin = 4; //Arduino pin 3

const int RedLED = 13; //Arduino pin 13
const int GreenLED = 12; //Arduino pin 12

long duration, distance, inches, cm;
const int MaxDistance = 10; //10 cm
const int speed1 = 150;
const int speed2 = 150;


// Define constants for motors
const int In1 = 3;     // Arduino pin 3
const int In2 = 5;     // Arduino pin 5
const int In3 = 6;     // Arduino pin 6
const int In4 = 11;     // Arduino pin 11

void setup() 
{
  // initialize serial communication:
  //Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
     
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT); 
}
 
void loop()
{
  ping();
  distance = cm;
  //print 
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(10);

  if (distance > MaxDistance)
    {
      digitalWrite(GreenLED, HIGH);
      digitalWrite(RedLED, LOW);
      //Motor goes forward 
      GoForward(speed1, speed2);
    }
  else
    {  
      digitalWrite(GreenLED, LOW);
      digitalWrite(RedLED, HIGH);     
    StopMotors(); 
    delay(100); 
    //Motor goes backwards and turn left
    Reverse (speed1, speed2);
    delay(2000);
    TurnLeft(speed1,speed2);
    delay(2000); 
    }
}

void GoForward(int speed1, int speed2)
{
  Serial.println("Forward");
  analogWrite(In4, 0); 
  analogWrite(In3, speed1); 
  analogWrite(In2, 0); 
  analogWrite(In1, speed2);
  return;
} 

void Reverse (int speed1, int speed2)
{
  Serial.println("Reverse");
  analogWrite(In4, speed1); 
  analogWrite(In3, 0); 
  analogWrite(In2, speed2); 
  analogWrite(In1, 0);
  return;
}
void TurnLeft (int speed1, int speed2)
{ 
   Serial.println("Turn Left"); 
   analogWrite(In4, 0); 
   analogWrite(In3, speed1); 
   analogWrite(In2, speed2); 
   analogWrite(In1, 0); 
   return;
}   
void StopMotors()
{
  Serial.println("Stop Motors");
  analogWrite(In4, 0); 
  analogWrite(In3, 0); 
  analogWrite(In2, 0); 
  analogWrite(In1, 0);
  return;
}

void ping ()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);
  // convert the time into a distance
  // inches = duration / 74 / 2;
  cm = duration / 29 /2;
  return;
}

