const int sensorPin = 2;  
const int ledPin = 13;    

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue == LOW) {   
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
