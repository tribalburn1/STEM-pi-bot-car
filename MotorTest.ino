/*
STEM Center USA, Inc.
Pi-Bot: Motor Test Program
Download this program and run it. If everything is hooked up as 
shown in the wiring diagram, the wheels will turn forward 
for 2 seconds, stop for 1 second, reverse for 1 second, and 
then stop for 1 second. If your robot is spinning or not moving forward, 
check your wiring again. You may have to swap the motor connection 
leads on the H-Bridge.

Once you have determined the robot is running the program correctly, 
you can modify the program to do different tasks.

STEM Board Pins 3 (IN1) and 5 (In2) control the left motor
IN1 and IN2 both cannot be a positive value simultaneously
  A positive value for IN1 & zero for IN2 moves the left motor forward
  A zero for IN1 & a positive value for IN2 moves the left motor backward

STEM Board Pins 6 (IN3) and 11 (IN4) control the right motor
IN3 and IN4 both cannot be a positive value simultaneously
  A positive value for IN3 & zero for IN4 moves the right motor forward
  A zero for IN3 & a positive value for IN4 moves the right motor backward
  
We are going to use the analogWrite function to control the motors. 
This will allow the motors to change speed. 

 */
 
const int In1 = 3;      
const int In2 = 5;      
const int In3 = 6;      
const int In4 = 11;     

void setup() 
{
  // initialize the pins as output:
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT); 
}

void loop()
{
  int speed1;
  int speed2;
 // speed1 and speed2 are two variables
 // You can change these values from 0 to 255
 // We will use 150 for now
 
  speed1 = 150; 
  speed2 = 150; 
  while(1==1)
  {
    //Go Forward
    analogWrite(In4, 0); 
    analogWrite(In3, speed1); 
    analogWrite(In2, 0); 
    analogWrite(In1, speed2); 
    delay(2000);
    
    //STOP
    analogWrite(In4, 0); 
    analogWrite(In3, 0); 
    analogWrite(In2, 0); 
    analogWrite(In1, 0);
    delay(1000); 
    
    //Reverse
    analogWrite(In4, speed1); 
    analogWrite(In3, 0); 
    analogWrite(In2, speed2); 
    analogWrite(In1, 0);
    delay(1000);
   
   //STOP 
    analogWrite(In4, 0); 
    analogWrite(In3, 0); 
    analogWrite(In2, 0); 
    analogWrite(In1, 0);
    delay(1000); 
  }
}

