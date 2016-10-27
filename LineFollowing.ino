
const int Line1 = 7;     // Left Line Sensor
const int Line2 = 8;     // Center Line Sensor
const int Line3 = 10;    // Right Sensor 

const int In1 = 3;      // In1
const int In2 = 5;      // In2
const int In3 = 6;     // In3
const int In4 = 11;     // In4

void setup() 
{
  // initialize the pins
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT); 
  pinMode(Line1, INPUT); 
  pinMode(Line2, INPUT); 
  pinMode(Line3, INPUT); 
  Serial.begin(9600);
}

void loop()
{
  int slow, fast;
  int speed1;
  int speed2;
  fast=100;
  slow=0;
  int L1;
  int L2;
  int L3;
  int dir;
  while(1==1)
  {
    L1 = digitalRead(Line1);
    L2 = digitalRead(Line2);
    L3 = digitalRead(Line3);
    Serial.print(L1);
    Serial.print(", ");
    Serial.print(L2);
    Serial.print(", ");
    Serial.println(L3); 
    
    if(L1 == 1 & L2 == 0 & L3 == 0)
    {
      //Left sees black, center & right see white
      //Turn left
      dir = 1;
      speed1=slow;
      speed2=fast;
      forward(speed1, speed2);
    }
    else if (L1 == 1  & L2 == 1 & L3 == 1)
    {
      //All sensors see white
      speed1=0;
      speed2=0;
      forward(speed1, speed2);
    }
    else if (L1 == 0 & L2 == 1 & L3 == 0)
    {
      //left sees white, center black and right white
      //go forward fast
      speed1=fast;
      speed2=fast;
      forward(speed1, speed2);
    }
    else if (L1 == 0 & L2 == 0 & L3 == 1)
    {
      //left & center see white, right sees black
      //turn right
      dir=2;
      speed1=fast;
      speed2=slow;
      forward(speed1, speed2);
    }
    else
    {
      if(dir == 1)
      {
        speed1=fast;
        speed2=slow;
        forward(speed1, speed2);
      }
      else
      {
        speed1=slow;
        speed2=fast;
        forward(speed1, speed2);
      }
    }
    //delay(5);
  }
}

void reverse(int speed1, int speed2)
{
analogWrite(In4, speed1);
analogWrite(In3, 0);
analogWrite(In2, speed2);
analogWrite(In1, 0);
return;
} 

void forward (int speed1, int speed2)
{
analogWrite(In4, 0);
analogWrite(In3, speed1);
analogWrite(In2, 0);
analogWrite(In1, speed2);
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
