int ledPin = 13;
int switchPin = 8;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

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
  //If lastButton is LOW and current is HIGH the switch has just been pressed

    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(ledPin, ledOn);
}
