#ifndef PASSWORD_MANAGEMENT_MODULE_H
#define PASSWORD_MANAGEMENT_MODULE_H

#include <Arduino.h>

void loadPasswordFromEEPROM();

extern String correctPassword;
extern String inputPassword;
extern String newPassword;
extern bool isChangingPassword;
extern int changeStage;

#endif
