//Automatic light on based on lighting in the room
int ana_pin = 1;
int led = 7;

void setup() {
  analogReference(DEFAULT); //Unnecessaty since it done by default
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ana_pin);
  if(val < 300) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
 
  Serial.println(analogRead(ana_pin));
  Serial.println(digitalRead(led));
  delay(500);
  
}
