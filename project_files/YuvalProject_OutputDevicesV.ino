#include <LiquidCrystal.h>

/*
  Temperature Sensor
  For use with Yuvalduino
  Yuval Gonczarowski
  HTMAA
  November 2016

  RS =     My 5, LCD 4
  LCD E =  My 7, LCD 6
  D4 =     My 10, LCD 11               
  D5 =     My 9, LCD 12
  D6 =     My 8, LCD 13
  D7 =     My 6, LCD 14
  R/W = GND LCD 5
  VSS = GND
  VCC = 5V
  Wiper to LCD V0
  
*/

int NTCPin = 4;
int NTCValue = 0;
int RTDPin = 3;
int RTDValue = 0;
int LEDPin = 13;
int RotateButtonPin = 11;
int numRotations = 0;
int current_state;
int last_state;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


LiquidCrystal lcd(5, 7, 10, 9, 8, 6);

// the setup function runs once when you press reset or power the board
void setup() {
  lcd.begin(16, 2);
  lcd.print("Rotations | Temp");
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDPin, OUTPUT);
  pinMode(RotateButtonPin, INPUT);
  current_state = digitalRead(RotateButtonPin);
  last_state = current_state;
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LEDPin, HIGH);
  delay(25);
  digitalWrite(LEDPin, LOW);
  delay(25);
  NTCValue = analogRead(NTCPin);
  RTDValue = analogRead(RTDPin);
  lcd.setCursor(0, 1);
  int reading = digitalRead(RotateButtonPin);
  if (last_state != reading) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != current_state) {
      current_state = reading;
      // only toggle the LED if the new button state is HIGH
      if (current_state == LOW) {
        ++numRotations;
      }
    }
  }
  last_state = reading;
  lcd.print(numRotations);
  lcd.setCursor(12,1);
  lcd.print(NTCValue);
  Serial.print("The NTC / RTD Temperature is: ");
  Serial.print(NTCValue,DEC);
  Serial.print ('/');
  Serial.print(RTDValue,DEC);
  Serial.print('\n');
}
