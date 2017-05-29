// AdvancedLineFollowing.ino

const int Line1 = 7;     // Left Line Sensor
const int Line2 = 8;     // Center Line Sensor
const int Line3 = 10;    // Right Sensor 
const int In1 = 3;      // In1
const int In2 = 5;      // In2
const int In3 = 6;      // In3
const int In4 = 11;     // In4
const int batPin = A0;
#define num 6
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
  int rLED[num], cLED[num], lLED[num];
  int  lSum, cSum, rSum;
  int fast;
  int speed1;
  int speed2;
  float scale1, scale2, scale3;
  boolean debugPrint;
  int L1, L2, L3;
  int batVoltage;
  
  for(int i=0; i<num; i++)
  {
    rLED[i]=0;
    cLED[i]=1;
    lLED[i]=0;
  }
  rSum = 0;
  cSum = 0;
  lSum = 0;
//************ Turn on debuging here ****************
  //debugPrint = true;
  debugPrint = false;
//***************************************************
  delay(100);
  forward(0, 0);
  while(1==1)
  {
    batVoltage = analogRead(batPin);
    L1 = digitalRead(Line1);
    L2 = digitalRead(Line2);
    L3 = digitalRead(Line3); 
    if ((L1 == 1) && (L2 == 1) && (L3 ==1))
    {
      speed1 = 0;
      speed2 = 0;
      forward(speed1, speed2);
      if(debugPrint)
      {
        Serial.println("In Lift Mode"); 
      }
    }
    else if ((L1 != 0) || (L2 != 0) || (L3 !=0))
    {
      rSum = 0;
      cSum = 0;
      lSum = 0;
      for(int i=0; i<num-1; i++)
      {
        rLED[i]=rLED[i+1];
        cLED[i]=cLED[i+1];
        lLED[i]=lLED[i+1];
      }
      
      rLED[num-1]=L1;
      cLED[num-1]=L2;
      lLED[num-1]=L3;
      
      for(int i=0; i<num; i++)
      {
        rSum = rSum + rLED[i] * (8-i);
        cSum = cSum + cLED[i] * (8-i);
        lSum = lSum + lLED[i] * (8-i);
      }
      
      if(debugPrint)
      {
        Serial.println(""); 
        Serial.print(L1);
        Serial.print(", ");
        Serial.print(L2);
        Serial.print(", ");
        Serial.println(L3); 
        Serial.print(rSum);
        Serial.print(", ");
        Serial.print(cSum);
        Serial.print(", ");
        Serial.println(lSum);  
      }
        scale1= (float) rSum + (float) cSum;
        scale2= (float) lSum + (float) cSum;
        scale3= (float) lSum + cSum + rSum;

         fast= 80000. / (float) batVoltage;
         
         if(rSum > lSum)
         {
           speed1 = fast;
           speed2 = scale2/scale1 * fast;
         }
         else
         {
           speed2 = fast;
           speed1 = scale1/scale2 * fast;
         }
         
         forward(speed1, speed2);
      
        if(debugPrint)
        {
          Serial.print(scale1);
          Serial.print(", "); 
          Serial.println(scale2);
          Serial.print(speed1);
          Serial.print(", "); 
          Serial.println(speed2);
          Serial.print("battery Voltage = ");
          Serial.println(batVoltage);
          Serial.print("fast = ");
          Serial.println(speed2);
          delay(500);
        }
    }
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
