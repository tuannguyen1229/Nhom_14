#include "RFID_Management_Module.h"
#include <EEPROM.h>

#define RFID_EEPROM_START_ADDR 200
#define RFID_MAX_CARDS 20
#define RFID_UID_LENGTH 8

bool isRFIDRegistered(const String& uid) {
  for (int i = 0; i < RFID_MAX_CARDS; i++) {
    String storedUID = "";
    for (int j = 0; j < RFID_UID_LENGTH; j++) {
      char c = EEPROM.read(RFID_EEPROM_START_ADDR + i * RFID_UID_LENGTH + j);
      storedUID += c;
    }
    if (storedUID == uid) {
      return true;
    }
  }
  return false;
}

void registerRFIDCard(const String& uid) {
  for (int i = 0; i < RFID_MAX_CARDS; i++) {
    String storedUID = "";
    for (int j = 0; j < RFID_UID_LENGTH; j++) {
      storedUID += char(EEPROM.read(RFID_EEPROM_START_ADDR + i * RFID_UID_LENGTH + j));
    }
    if (storedUID == "FFFFFFFF") {
      for (int j = 0; j < RFID_UID_LENGTH && j < uid.length(); j++) {
        EEPROM.write(RFID_EEPROM_START_ADDR + i * RFID_UID_LENGTH + j, uid[j]);
      }
      EEPROM.commit();
      break;
    }
  }
}

void removeRFIDCard(const String& uid) {
  for (int i = 0; i < RFID_MAX_CARDS; i++) {
    String storedUID = "";
    for (int j = 0; j < RFID_UID_LENGTH; j++) {
      storedUID += char(EEPROM.read(RFID_EEPROM_START_ADDR + i * RFID_UID_LENGTH + j));
    }
    if (storedUID == uid) {
      for (int j = 0; j < RFID_UID_LENGTH; j++) {
        EEPROM.write(RFID_EEPROM_START_ADDR + i * RFID_UID_LENGTH + j, 'F');
      }
      EEPROM.commit();
      break;
    }
  }
}
