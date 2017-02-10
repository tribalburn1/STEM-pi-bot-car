#define var1 1
int const var3=1;
void setup()
{

Serial.begin(9600);
}
void loop()
{
const int var2 = 1;
int var4;
int var5=1;
boolean var6=false;
var4=1; // The value of c4 is now defined
Serial.print("var1 = ");
Serial.print(var1,DEC);
Serial.print(" var2 = ");
Serial.print(var2,DEC);
Serial.print(" var3 = ");
Serial.print(var3,DEC);
Serial.print(" var4 = ");
Serial.print(var4,DEC);
Serial.print(" var5 = ");
Serial.print(var5,DEC);
Serial.print(" var6 = ");
Serial.println(var6, DEC);
//var3++;
var4++;
var5++;
var6=true;
Serial.print("var1 = ");
Serial.print(var1,DEC);
Serial.print(" var2 = ");
Serial.print(var2,DEC);
Serial.print(" var3 = ");
Serial.print(var3,DEC);
Serial.print(" var4 = ");
Serial.print(var4,DEC);
Serial.print(" var5 = ");
Serial.print(var5,DEC);
Serial.print(" var6 = ");
Serial.println(var6, DEC);
Serial.println(" ");
delay(1000);
}
