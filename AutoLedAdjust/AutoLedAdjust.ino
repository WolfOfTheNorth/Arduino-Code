//Automatic light on based on lighting in the room LED changes intensity based on darkness
int ana_pin = 1;
int led = 7;

void setup() {
  analogReference(DEFAULT); //Unnecessaty since it done by default
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ana_pin);
  
  val = constrain(val, 750, 900); // Check for value outside 750 or 900 and set min and max
  int ledLevel = map(val, 750, 900, 255, 0); // mapping analog to digital -- (0-1024(10 bit) to 0 -256 (8 bit) -- 750 -> 255 900 --> 0

  analogWrite(led, ledLevel);
 
  Serial.println(analogRead(ana_pin));
  Serial.println(digitalRead(led));
  delay(500);
  
}
