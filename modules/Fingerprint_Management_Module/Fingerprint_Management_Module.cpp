#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Fingerprint_Management_Module.h"

// GPIO định nghĩa cảm biến vân tay
#define FINGERPRINT_RX 16
#define FINGERPRINT_TX 17

extern LiquidCrystal_I2C lcd;

HardwareSerial fingerprintSerial(2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerprintSerial);

void setupFingerprintSensor() {
    fingerprintSerial.begin(57600, SERIAL_8N1, FINGERPRINT_RX, FINGERPRINT_TX);
}

bool isFingerprintSensorAvailable() {
    if (finger.verifyPassword()) {
        Serial.println("Tìm thấy cảm biến vân tay!");
        return true;
    } else {
        Serial.println("Không tìm thấy cảm biến vân tay!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("LOI CAM BIEN");
        lcd.setCursor(0, 1);
        lcd.print("VAN TAY!");
        delay(2000);
        return false;
    }
}
