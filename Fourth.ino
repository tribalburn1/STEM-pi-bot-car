void setup()
{
Serial.begin(9600);
}
void loop()
{
int var1;
var1 = 3;
Serial.print("var1 = ");
Serial.print(var1, DEC);
if( var1 == 1)
{
Serial.println(" is equal to 1");
}
else if( var1 < 1)
{
Serial.println(" is less than 1");
}
else if( var1 <= 4)
{
Serial.println(" is less than or equal to 4");
}
else
{
Serial.println(" unknown");
}
delay(1000);
}
