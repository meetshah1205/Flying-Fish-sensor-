/*
  MWAFP: Maximum Working And Flexy Product
  Proximity + Sound Activated Trigger System with Serial Plotter
  
  What it does:
  - Uses a Flying Fish IR sensor to detect proximity (LOW when object is near)
  - Uses a Keyes sound sensor to detect loud sounds (HIGH on noise)
  - If both sensors are triggered → activates built-in LED
  - Data is visualized live in the Arduino Serial Plotter:
      Fish Sensor   = Blue Line
      Mic Sensor    = Red Line
      Activated     = Orange Line
  
  Components:
  - Arduino Uno
  - Flying Fish IR Sensor (3-pin)
  - Keyes Sound Sensor (3-pin)
  - Jumper wires

  Wiring:
  Flying Fish:
    VCC  → 5V
    GND  → GND
    OUT  → D2

  Keyes Sound Sensor:
    VCC  → 5V
    GND  → GND
    OUT  → D3

  Serial Plotter: Tools > Serial Plotter @ 9600 baud

  Made by Meet Shah (GitHub: @meetshah1205).
*/

const int fishSensorPin = 2;
const int micSensorPin = 3;
const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(fishSensorPin, INPUT);
  pinMode(micSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int fishState = digitalRead(fishSensorPin); // LOW = object close
  int micState = digitalRead(micSensorPin);   // HIGH = sound detected
  int activated = (fishState == LOW && micState == HIGH) ? 1 : 0;

  digitalWrite(ledPin, activated);

  // Clean tab-separated values (no text!)
  Serial.print(fishState);   // Blue
  Serial.print("\t");
  Serial.print(micState);    // Red
  Serial.print("\t");
  Serial.println(activated); // Orange

  delay(100);
}
