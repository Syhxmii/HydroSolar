const int pinSwitch[] = {34, 35, 32, 33, 25, 26};
const int jumlahSwitch = sizeof(pinSwitch) / sizeof(pinSwitch[0]);
int statusSwitchSebelumnya[jumlahSwitch] = {LOW};

void setup() {
  for (int i = 0; i < jumlahSwitch; i++) {
    pinMode(pinSwitch[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int nilaiDesimal = 0;

  for (int i = 0; i < jumlahSwitch; i++) {
    int statusSwitch = digitalRead(pinSwitch[i]);
    if (statusSwitch == LOW) {
      nilaiDesimal |= (1 << i); 
    }
  }

  cetakJikaSwitchBerubah(nilaiDesimal);
}

void cetakJikaSwitchBerubah(int nilaiBaru) {
  static int nilaiLama = -1; 

  if (nilaiBaru != nilaiLama) {
    Serial.print("Switch: ");
    for (int i = jumlahSwitch - 1; i >= 0; i--) {
      int bitSwitch = (nilaiBaru >> i) & 1;
      Serial.print(bitSwitch);
    }
    Serial.println();
    nilaiLama = nilaiBaru;
  }
  delay(500);
}
