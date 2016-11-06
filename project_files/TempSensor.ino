/*
  Temperature Sensor
  For use with Yuvalduino
  Yuval Gonczarowski
  HTMAA
  November 2016
*/

int NTCPin = 4;
int NTCValue = 0;
int RTDPin = 3;
int RTDValue = 0;
int LEDPin = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEDPin, HIGH);
  delay(1000);
  digitalWrite(LEDPin, LOW);
  delay(1000);
  NTCValue = analogRead(NTCPin);
  RTDValue = analogRead(RTDPin);
  Serial.print("The NTC / RTD Temperature is: ");
  Serial.print(NTCValue,DEC);
  Serial.print ('/');
  Serial.print(RTDValue,DEC);
  Serial.print('\n');
}
