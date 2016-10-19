void setup()
{
Serial.begin(9600);
}
void loop()
{
int var1, var2;
var1 = 1;
var2 = 1;
if( var1 == 1)
{
var2 = 2;
}
Serial.print("var1 = ");
Serial.print(var1, DEC);
Serial.print(" var2 = ");
Serial.println(var2, DEC);
Serial.println(" ");
delay(1000);
}
