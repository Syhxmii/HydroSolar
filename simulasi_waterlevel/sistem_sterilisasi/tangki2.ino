// Tangki 2
void monitorTank2(){

  if (isTank1HighActive && !isTank2LowActive) {
      // Tangki 1 sudah penuh, pompa 2 dihidupkan
      Serial.println("Memindahkan air ke Tangki 2 (Pompa 2 Hidup)");
      digitalWrite(relay2, LOW); 
  } else {
      // Tangki 2 kosong (switch atas tidak kontak, switch bawah tidak kontak atau kontak)
      Serial.println("Menunggu tangki 1 penuh");
      digitalWrite(relay2, HIGH); 
  }
  
    if (!isTank2HighActive && isTank2LowActive) {
      // Switch atas belum kontak (belum penuh) dan switch bawah sudah kontak (ada air)
      Serial.println("sedang mengisi... (Pompa 2 Hidup)");
      digitalWrite(relay2, LOW); 
  } else if (isTank2HighActive && isTank2LowActive) {
      // Tangki 2 sudah penuh (switch atas dan switch bawah kontak)
      Serial.println("Tangki 2 sudah penuh, (Pompa 2 Dimatikan)");
      digitalWrite(relay2, HIGH); 
  } else if (isTank2HighActive && !isTank2LowActive) {
      // Switch atas kontak dan switch bawah tidak kontak (error)
      Serial.println("Error: Switch bawah pada Tangki 2");
      digitalWrite(relay2, HIGH); 
  }
}