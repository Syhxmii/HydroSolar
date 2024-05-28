const int relay1 = 22; // Relay 1 untuk pompa 1
const int relay2 = 23; // Relay 2 untuk pompa 2
const int relay3 = 21; // Relay 3 untuk pompa 3
// const int relay4 = 19; // Relay 4 untuk pompa 4
// const int relay5 = 18;  // Relay 5 untuk ozone generator
// const int relay6 = 5;  // Relay 6 untuk lampu UV 1
// const int relay7 = 17;  // Relay 7 untuk lampu UV 2
// const int relay8 = 16; // Relay 8

const int tank1Bawah = 13;  // Switch bawah Tangki 1
const int tank1Atas = 12; // Switch atas Tangki 1
const int tank2Bawah = 14;  // Switch bawah Tangki 2
const int tank2Atas = 27; // Switch atas Tangki 2
// const int tank3Low = 26;  // Switch bawah Tangki 2
// const int tank3High = 25; // Switch atas Tangki 2

void setup() {
  Serial.begin(115200);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  // pinMode(relay4, OUTPUT);
  // pinMode(relay5, OUTPUT);
  // pinMode(relay6, OUTPUT);
  // pinMode(relay7, OUTPUT);
  // pinMode(relay8, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  // digitalWrite(relay3, LOW);
  // digitalWrite(relay4, LOW);
  // digitalWrite(relay5, LOW);
  // digitalWrite(relay6, LOW);
  // digitalWrite(relay7, LOW);
  // digitalWrite(relay8, LOW);

  pinMode(tank1Bawah, INPUT_PULLUP);
  pinMode(tank1Atas, INPUT_PULLUP);
  pinMode(tank2Bawah, INPUT_PULLUP);
  pinMode(tank2Atas, INPUT_PULLUP);

  Serial.println("Sistem Sterilisasi Dimulai");
}

void loop() {
  bool isTank1LowActive = digitalRead(tank1Low) == LOW;
  bool isTank1HighActive = digitalRead(tank1High) ==LOW;
  bool isTank2LowActive = digitalRead(tank2Low) == LOW;
  bool isTank2HighActive = digitalRead(tank2High) == LOW;
  
  monitorTank1();
  monitorTank2();

  delay(1000);
}