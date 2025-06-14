#include "RFID_Module.h"

extern MFRC522 mfrc522;

bool readRFIDCard(String &uidOut) {
  if (!mfrc522.PICC_IsNewCardPresent()) return false;
  if (!mfrc522.PICC_ReadCardSerial()) return false;

  uidOut = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uidOut += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    uidOut += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidOut.toUpperCase();

  mfrc522.PICC_HaltA();
  return true;
}
