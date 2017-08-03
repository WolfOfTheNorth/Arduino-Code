#include <Servo.h>
#include <LiquidCrystal.h>

#define trigPin 13
#define echoPin 12

int pos = 0;

LiquidCrystal lcd(10, 11, 5, 4, 3, 2);
Servo s1;

void setup() { 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  s1.attach(9);
  s1.write(180); 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  //distance = (duration / 2) * 0.0344;
  distance = (duration/2) / 29.1;
  
  if (distance >= 400 || distance <= 2){
    Serial.println("out of range");
    lcd.print("Out of range");
//    delay(500);
  }
  else if (distance < 5){
      for(pos = 0; pos < 180; pos++){
        s1.write(pos);
        delay(10);
      }
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    lcd.print(distance);
    lcd.print(" cm");
//    delay(500);
  }
  delay(500);
  lcd.clear();
}

