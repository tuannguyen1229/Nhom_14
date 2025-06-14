#ifndef RFID_MANAGEMENT_MODULE_H
#define RFID_MANAGEMENT_MODULE_H

#include <Arduino.h>

bool isRFIDRegistered(const String& uid);
void registerRFIDCard(const String& uid);
void removeRFIDCard(const String& uid);

#endif
