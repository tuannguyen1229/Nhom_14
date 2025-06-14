#include "Fingerprint_Module.h"
#include <EEPROM.h>
#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
extern Adafruit_Fingerprint finger;

#define FINGERPRINT_START_ADDR 100
#define MAX_FINGERPRINTS 20

uint8_t getNextAvailableID() {
  for (int i = 1; i <= MAX_FINGERPRINTS; i++) {
    uint8_t value = EEPROM.read(FINGERPRINT_START_ADDR + i);
    if (value != 1) {
      return i;
    }
  }
  return 0;
}

void markFingerprintID(uint8_t id, bool used) {
  EEPROM.write(FINGERPRINT_START_ADDR + id, used ? 1 : 0);
  EEPROM.commit();
}

bool enrollFingerprint() {
  uint8_t id = getNextAvailableID();
  if (id == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DA DAY BO NHO!");
    lcd.setCursor(0, 1);
    lcd.print("XOA BOT VAN TAY");
    delay(2000);
    return false;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DANG KY VAN TAY");
  lcd.setCursor(0, 1);
  lcd.print("ID: ");
  lcd.print(id);
  lcd.setCursor(0, 2);
  lcd.print("DAT NGON TAY...");

  Serial.print("Dang ky van tay ID #");
  Serial.println(id);

  int p = -1;
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
      case FINGERPRINT_OK:
        Serial.println("- Da chup van tay");
        break;
      case FINGERPRINT_NOFINGER:
        lcd.setCursor(0, 3);
        lcd.print("CHO NGON TAY...");
        break;
      case FINGERPRINT_PACKETRECIEVEERR:
        lcd.setCursor(0, 3);
        lcd.print("LOI GIAO TIEP!");
        break;
      case FINGERPRINT_IMAGEFAIL:
        lcd.setCursor(0, 3);
        lcd.print("LOI HINH ANH!");
        break;
      default:
        break;
    }
    delay(500);
  }

  // Tiếp tục các bước đăng ký tại đây nếu cần

  return true;
}
