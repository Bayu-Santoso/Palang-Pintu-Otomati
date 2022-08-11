#include <Servo.h>

#define ECHO_PIN 3
#define TRIG_PIN 2
#define pinBuzzer 5
#define pinRelay 7
#define P1 8
#define P2 9

Servo myservo; 
Servo myservo2; 

//int potpin = 0;  
int val;  

//Mendeteksi objek yang menelawti sensor Ultrasonic
float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115200);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinRelay, OUTPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  myservo.attach(10);  
  myservo2.attach(11); 
}

void loop() {
  float distance = readDistanceCM();
  int nilaiSwitch = digitalRead((distance));
  Serial.print("Measured distance: ");
  Serial.println(readDistanceCM());
  

  if(distance <= 200){  
    if(nilaiSwitch <= 200){
    digitalWrite(pinRelay, HIGH);
    delay(500);
    digitalWrite(pinRelay, LOW);
    digitalWrite(P1, HIGH);
    digitalWrite(P2, HIGH);
    tone(pinBuzzer, 1000);
    delay(400);     
    tone(pinBuzzer, 500);
    }                   
    myservo.write(90);
    myservo2.write(90);
    delay(15);
   }
  else{
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
    myservo.write(0);
    myservo2.write(0);
    noTone(pinBuzzer); 
  }                           
}
