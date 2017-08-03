//Hold Button for On
int ledPin = 13;
int switchPin = 8;

void setup(){
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  digitalWrite(ledPin, LOW);
  //If the button is pressed (HIGH), Turn LED on
  if(digitalRead(switchPin) == HIGH){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}

