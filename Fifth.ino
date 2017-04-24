void setup()
{
Serial.begin(9600);
}
void loop()
{
  int var1;
for(int count=0; count<10; count++)
{
var1 = var1 + count;
}
delay(1000);
}
