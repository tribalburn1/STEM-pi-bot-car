// Program Led2

void setup()

  #define Left_Light 13
{
pinMode(Left_Light,OUTPUT);
}
void loop()
{
digitalWrite(Left_Light,HIGH);
delay(120);
digitalWrite(Left_Light,LOW);
delay(120);
}
