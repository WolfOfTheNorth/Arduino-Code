//Change LED --- USING PWM 
int ledPin = 11;
int switchPin = 8;
boolean lastButton = LOW;
boolean currentButton = LOW;
//The led will have a  0 - 255 range or 256 Resolution (16 bit)
int ledLevel = 0;


void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);  

}

boolean debounce(boolean last){
  //Current value of pin
  boolean current = digitalRead(switchPin);
  // If the last value & current are not equal create a 5ms delay and return current value.
  if(last != current){
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() {
  //Get current button from debounce
  currentButton = debounce(lastButton);  
  if(lastButton == LOW  &&  currentButton == HIGH ){
    //Increment brightness (by 51 because it is divisible by 255)
    ledLevel = ledLevel +51;
  }
  lastButton = currentButton;
  //Consider case over 255
  if(ledLevel > 255) ledLevel = 0;
  analogWrite(ledPin, ledLevel);
}
