const int sensorPin = 2;  // Connect OUT of flying fish sensor to digital pin 2
const int ledPin = 13;    // Built-in LED pin

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue == LOW) {   // Usually LOW means object detected, but test both LOW and HIGH
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
