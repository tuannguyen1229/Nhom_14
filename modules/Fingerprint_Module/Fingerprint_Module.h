#ifndef FINGERPRINT_MODULE_H
#define FINGERPRINT_MODULE_H

#include <Arduino.h>

uint8_t getNextAvailableID();
void markFingerprintID(uint8_t id, bool used);
bool enrollFingerprint();

#endif
