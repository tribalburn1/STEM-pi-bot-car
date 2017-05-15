/*
STEM Center USA, Inc.
Pi-Bot: Motor Test Program using Function Calls
*/
const int In1 = 3;      
const int In2 = 5;      
const int In3 = 6;      
const int In4 = 11;  
void setup()

{
// initialize the pins an output:
pinMode(In1, OUTPUT);
pinMode(In2, OUTPUT);
pinMode(In3, OUTPUT);
pinMode(In4, OUTPUT);
}
void loop()
{
int speed1, speed2;
int delayTime;
speed1 = 150;
speed2 = 150;
while(1==1)
{
forward(speed1, speed2);
delay(2000);
stopNow();
delay(1000);
reverse(speed1, speed2);
delay(1000);
stopNow();
delay(1000);
}
}
void forward(int speed1, int speed2)
{
analogWrite(In4, 0);
analogWrite(In3, speed1);
analogWrite(In2, 0);
analogWrite(In1, speed2);
}
void reverse (int speed1, int speed2)
{
analogWrite(In4, speed1);
analogWrite(In3, 0);
analogWrite(In2, speed2);
analogWrite(In1, 0);
return;
}
void stopNow()
{
analogWrite(In4, 0);
analogWrite(In3, 0);
analogWrite(In2, 0);
analogWrite(In1, 0);
return;
}
