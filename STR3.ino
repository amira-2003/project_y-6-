#define Echo1 A0
#define Trig1 A1
#define Echo2 A2 
#define Trig2 A3
#define Echo3 A4
#define Trig3 A5 
#define motorA1 2
#define motorA2 3
#define motorB1 4
#define motorB2 5
#define enable1 9
#define enable2 10
#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 11
#define LED5 12
#define LED6 13
int Left_Distance = 0,Right_Distance = 0,Middle_Distance = 0 ;
int PWM = 150;//ATUR KECEPATAN 10 SAMPAI 255
void _Forward()
{
digitalWrite(motorA1,HIGH);
digitalWrite(motorA2,LOW);
digitalWrite(motorB1,HIGH);
digitalWrite(motorB2,LOW);
analogWrite(enable1,PWM);
analogWrite(enable2,PWM);
Serial.println("Forward");
}
void _Back()
{
digitalWrite(motorA1,LOW);
digitalWrite(motorA2,HIGH);
digitalWrite(motorB1,LOW);
digitalWrite(motorB2,HIGH);
analogWrite(enable1,PWM);
analogWrite(enable2,PWM);
Serial.println("Back");
}
void _left()
{
digitalWrite(motorA1,LOW);
digitalWrite(motorA2,HIGH);
digitalWrite(motorB1,HIGH);
digitalWrite(motorB2,LOW);
analogWrite(enable1,PWM);
analogWrite(enable2,PWM);
Serial.println("Left");
}
void _right()
{
digitalWrite(motorA1,HIGH);
digitalWrite(motorA2,LOW);
digitalWrite(motorB1,LOW);
digitalWrite(motorB2,HIGH);
analogWrite(enable1,PWM);
analogWrite(enable2,PWM);
Serial.println("Right");
}
void _Stop()
{
digitalWrite(motorA1,LOW);
digitalWrite(motorA2,LOW);
digitalWrite(motorB1,LOW);
digitalWrite(motorB2,LOW);
digitalWrite(enable1,LOW);
digitalWrite(enable2,LOW);
Serial.println("Stop");
}
int Left_Distance_test()
{
digitalWrite(Trig1, LOW);
delayMicroseconds(2);
digitalWrite(Trig1, HIGH);
delayMicroseconds(10);
digitalWrite(Trig1, LOW);
float Fdistance = pulseIn(Echo1, HIGH);
delay(10);
Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
int Middle_Distance_test()
{
digitalWrite(Trig2, LOW);
delayMicroseconds(2);
digitalWrite(Trig2, HIGH);
delayMicroseconds(10);
digitalWrite(Trig2, LOW);
float Fdistance = pulseIn(Echo2, HIGH);
delay(10);
Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
int Right_Distance_test()
{
digitalWrite(Trig3, LOW);
delayMicroseconds(2);
digitalWrite(Trig3, HIGH);
delayMicroseconds(10);
digitalWrite(Trig3, LOW);
float Fdistance = pulseIn(Echo3, HIGH);
delay(10);
Fdistance= Fdistance/ 29 / 2;
return (int)Fdistance;
}
void setup()
{
Serial.begin(9600);
pinMode(Echo1, INPUT);
pinMode(Trig1, OUTPUT);
pinMode(Echo2, INPUT);
pinMode(Trig2, OUTPUT);
pinMode(Echo3, INPUT);
pinMode(Trig3, OUTPUT);
pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode(enable1,OUTPUT);
pinMode(enable2,OUTPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);
pinMode(LED6,OUTPUT);
_Stop();
}
void loop()
{
Left_Distance = Left_Distance_test();
delay(10);
Middle_Distance = Middle_Distance_test();
delay(10);
Right_Distance = Right_Distance_test();
delay(10);
if(Middle_Distance<=35)
{
/* _Stop();
delay(1000);*/
if(Right_Distance>Left_Distance)
{
if((Right_Distance<=15)&&(Left_Distance<=15))
{_Stop();
delay(200);
_Back();
delay(2000);
}
else{
// _Back();
// delay(2000);
_right();
delay(500);}
}
else if(Right_Distance<Left_Distance)
{
if((Right_Distance<=15)&&(Left_Distance<=15))
{_Stop();
delay(200);
_Back();
delay(1000);
}
else{
// _Back();
// delay(3000);
_left();
delay(500);
}
}
}
else if(Right_Distance<=15)
{
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
digitalWrite(LED6,LOW);

_left();
delay(500);
}
else if(Left_Distance<=15)
{
  digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,LOW);
digitalWrite(LED6,HIGH);
_right();
delay(500);
}
else{
 digitalWrite(LED1,LOW);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
digitalWrite(LED6,LOW);
_Forward();
}
//delay(500);
}