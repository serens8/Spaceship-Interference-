const int buttonPin = 2;
const int greenLED = 3;
const int redLED1 = 4;
const int redLED2 = 5;

int switchState = 0;

void setup() {
  // Set our LED pins as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);

  // Set button pin as input. (If you aren't using an external resistor on your breadboard, change this to INPUT_PULLUP)
  pinMode(buttonPin, INPUT); 
}

void loop() {
  // Read the state of the button
  switchState = digitalRead(buttonPin);

  if (switchState == LOW) {
    // The button is NOT pressed: Green LED is on, Red LEDs are off
    digitalWrite(greenLED, HIGH); 
    digitalWrite(redLED1, LOW); 
    digitalWrite(redLED2, LOW); 
  }
  else { 
    // The button IS pressed: Green LED goes off, Reds blink alternatively
    digitalWrite(greenLED, LOW);
    
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, HIGH);
    delay(250); // wait for a quarter second 
    
    // Toggle the red LEDs 
    digitalWrite(redLED1, HIGH); 
    digitalWrite(redLED2, LOW);
    delay(250); // wait for a quarter second 
  }
} // Go back to the beginning of the loop