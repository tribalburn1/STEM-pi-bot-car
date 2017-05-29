/* Light Sensors Test
*/
const int Line1 = 7;     // Left Line Sensor
const int Line2 = 8;     // Center Line Sensor
const int Line3 = 10;    // Right Sensor 
void setup() 
{
  // initialize the pins
  pinMode(Line1, INPUT); 
  pinMode(Line2, INPUT); 
  pinMode(Line3, INPUT); 
  Serial.begin(9600);
}
void loop()
{
  int L1;
  int L2;
  int L3;
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
    delay(10);
  }
