#include<NewPing.h>
#include<Servo.h>
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//Motor A
const int motorPin1 = 5;
const int motorPin2 = 6;
//Motor B
const int motorPin3 = 9;
const int motorPin4 = 10;
Servo myservo;
int pos =0;
void setup(){
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
Serial.begin(9600);
myservo.attach(11);{
for(pos = 90; pos <= 180; pos += 1){
myservo.write(pos);
delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
myservo.write(pos);
delay(15);
}for(pos = 0; pos<=90; pos += 1) {
myservo.write(pos);
delay(15);
}
}
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);
}
void loop(){
unsigned int distance = sonar.ping_cm();
Serial.print("distance");
Serial.println(distance);
int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);
Serial.print("RIGHT");
Serial.println(Right_Value);Serial.print("LEFT");
Serial.println(Left_Value);
if((Right_Value==0) && (distance>=5 && distance<=100)&&(Left_Value==0)){
//forward
analogWrite(motorPin3, 255);
analogWrite(motorPin4, 0);
analogWrite(motorPin1, 0);
analogWrite(motorPin2, 0);
}
else if((Right_Value==0) && (Left_Value==1)) {
//right forword
analogWrite(motorPin1, 255);
analogWrite(motorPin2, 0);
analogWrite(motorPin3, 255);
analogWrite(motorPin4, 0);
}
else if((Right_Value==1)&&(Left_Value==0)) {
//left forward .
analogWrite(motorPin1, 0);
analogWrite(motorPin2, 255);
analogWrite(motorPin3, 255);
analogWrite(motorPin4, 0);
}
else {
//And this code will stop motors
analogWrite(motorPin1, 0);
analogWrite(motorPin2, 0);analogWrite(motorPin3, 0);
analogWrite(motorPin4, 0);
} }