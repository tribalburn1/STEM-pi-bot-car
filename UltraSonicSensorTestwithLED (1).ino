/* Using HC-SR04 Sensor
STEM Center USA - Pi-Bot 
VCC pin connected to Arduino +5V
GND pin connected  to Arduino Ground
TRIG pin connected digital pin 2
ECHO pin connected digital pin 4

LED will light up if the distance between
ultrasonic sensor and an object falls below
the MaxDistance 

Don't forgte to use a resistor 
while connecting the LED 
*/
 
//Define integer constants
const int trigPin = 2; //Aduino pin 2
const int echoPin = 4; //Aduino pin 4

const int LED = 13; //Aduino pin 13

long duration, distance, inches, cm;
const int MaxDistance = 10; //10 cm

void setup() 
{
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED,OUTPUT);
}
 
void loop()
{
  ping();
  distance = cm;
  if (distance < MaxDistance)
   {
     digitalWrite(LED, HIGH);
   } 
   else
   {
     digitalWrite(LED, LOW);
   }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(10);
   
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
  inches = duration / 74 / 2;
  cm = duration / 29 /2;
  return;
}

