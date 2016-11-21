void setup()
{
Serial.begin(9600);
}
void loop()
{
int var1=0;
for(int count=1; count<=10; count++)
{
if(count < 5)
{
Serial.print(count, DEC);
Serial.println(" is less than 5 ");
}
else if(count > 5)
{
Serial.print(count, DEC);
Serial.println(" is greater than 5 ");
}
else
{
Serial.print(count, DEC);
Serial.println(" is equal to 5 ");
}
}
while(1==1);
}
