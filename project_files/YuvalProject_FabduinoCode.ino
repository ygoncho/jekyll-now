#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

/*
  LetIoT
  For use with Yuvalduino
  Yuval Gonczarowski
  HTMAA
  December 2016

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

int Dir_In_Pin = 4;
int Dir_Out_Pin = 3;
//int LEDPin = 13;
int externalGoIn = 13;
int externalGoOut = 12;
int RotateButtonPin = 11;
int numRotations = 0;
int iter = 0;
int current_stateBtn;
int last_stateBtn;
int current_ex;
int last_ex;
char myip[15];
int myipindex = 0;
char incomingByte = 0;   // for incoming serial data

unsigned long lastDebounceTimeBtn = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTimeEx = 0;  // the last time the output pin was toggled
unsigned long debounceDelayBtn = 20;    // the debounce time; increase if the output flickers
unsigned long debounceDelayEx = 20;    // the debounce time; increase if the output flickers


LiquidCrystal lcd(5, 7, 10, 9, 8, 6);

// the setup function runs once when you press reset or power the board
void setup() {
  lcd.begin(16, 2);
  lcd.print("Searching IP...");
  Serial.begin(9600);
  Serial.write("Welcome, Debugger!");
  // initialize digital pin LED_BUILTIN as an output.
//  pinMode(LEDPin, OUTPUT);
  pinMode(RotateButtonPin, INPUT);
  pinMode(Dir_In_Pin, INPUT);
  pinMode(externalGoIn, INPUT);
  pinMode(externalGoOut, OUTPUT);
  pinMode(Dir_Out_Pin, OUTPUT);
  current_stateBtn = digitalRead(RotateButtonPin);
  last_stateBtn = current_stateBtn;
  current_ex = digitalRead(externalGoIn);
  last_ex = current_ex;
}

int GoHandler(unsigned long* LDT, unsigned long* DD, int* current, int* last, int pin)
{
    int reading = digitalRead(pin);
  if (*last != reading) {
    *LDT = millis();
  }
  if ((millis() - *LDT) > *DD) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != *current) {
      *current = reading;
      // only toggle the LED if the new button state is HIGH
      if (*current == LOW) {
        ++numRotations;
      }
    }
  }
  *last = reading;
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(externalGoOut, digitalRead(externalGoIn));
//  digitalWrite(LEDPin, HIGH);
  delay(10);
//  digitalWrite(LEDPin, LOW);
  delay(10);
  GoHandler(&lastDebounceTimeBtn, &debounceDelayBtn, &current_stateBtn, &last_stateBtn, RotateButtonPin);
  GoHandler(&lastDebounceTimeEx, &debounceDelayEx, &current_ex, &last_ex, externalGoIn);
  lcd.setCursor(0, 1);
  lcd.print(numRotations);
  lcd.setCursor(12,1);
  if (digitalRead(Dir_In_Pin) == HIGH) {
    lcd.print("CW ");
    digitalWrite(Dir_Out_Pin, HIGH);
  }
  else {
    lcd.print("CCW");
    digitalWrite(Dir_Out_Pin, LOW);
  }
   // Loop runs every 20 ms. Every 10 seconds - refresh IP address
   if (iter == 500) {
        while (Serial.available() > 0) {
          incomingByte = Serial.read();
          if (((incomingByte >= '0') && (incomingByte <= '9')) || (incomingByte == '.')) {
              myip[myipindex++] = incomingByte;
           }
        } // say what you got:
        if (myipindex > 0) {
          while (myipindex < 16){
          myip[myipindex++] = ' ';
          }
        }
        lcd.setCursor(0, 0);
        Serial.println(myip);
        lcd.print(myip);
        myipindex = 0;
        iter = 0;
    }
  iter++;
}
