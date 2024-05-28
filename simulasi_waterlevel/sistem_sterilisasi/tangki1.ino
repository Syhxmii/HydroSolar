// Tangki 1
void monitorTank1(){

  if (isTank1HighActive && !isTank1LowActive) {
      // Switch atas kontak dan switch bawah tidak kontak (error)
      Serial.println("Error: Switch Bawah Tangki 1");
      digitalWrite(relay1, HIGH); // Matikan pompa 1 jika dalam keadaan error
    } else if (!isTank1LowActive) {
      // Switch bawah belum kontak (air habis)
      Serial.println("Tangki 1 kosong, tidak ada air (Menghidupkan Pompa 1)");
      digitalWrite(relay1, LOW); // Hidupkan pompa 1
    } else {
      // Switch bawah kontak (ada air)
      if (!isTank1HighActive) {
        // Switch atas belum kontak (belum penuh)
        Serial.println("Tangki 1 belum penuh, mengisi... (Pompa 1 Hidup)");
        digitalWrite(relay1, LOW); // Hidupkan pompa 1
      } else {
        // Switch atas kontak (sudah penuh)
        Serial.println("Tangki 1 penuh, (Pompa 1 Dimatikan)");
        digitalWrite(relay1, HIGH); // Matikan pompa 1
      }
    }
  }