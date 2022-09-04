//TinkerCAD Link: https://www.tinkercad.com/things/8Kqzf9aeteB-copy-of-accident-avoiding-system/editel?tenant=circuits
#include <Servo.h>
#define RMS 5
#define RMP 6
#define RMN 7
#define LMS 3
#define LMP 2
#define LMN 4
const int trigPin = 9;
const int echoPin = 8;
float duration, distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RMS, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMS, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  digitalWrite(RMS, HIGH);
  digitalWrite(LMS, HIGH);
  Serial.begin(9600);
}
void loop() {
  sense();
  if(distance>50)
  {
    forword();
  }
  else
  {
    stops();
    delay(2000);
    backward();
    delay(300);
    right();
    delay(2500);
  }
}
void sense()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  if(distance > 200)
  {
    Serial.print("Distance is: ");
    Serial.print(distance);
    Serial.println(" then Safe Distance... Continue Driving");
  }
  else
  {
    Serial.print("Distance is: ");
    Serial.print(distance);
    Serial.println(" then No Safe Distance... Push the break");
    delay(100);
  }
}
void forword()
{ 
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
 }
void backward()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
}
void stops()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}
void left()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);

}
void right()
{
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
} 