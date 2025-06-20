#include "Password_Management_Module.h"
#include <EEPROM.h>

String correctPassword = "1234";
String inputPassword = "";
String newPassword = "";
bool isChangingPassword = false;
int changeStage = 0;

void loadPasswordFromEEPROM() {
  String password = "";
  for (int i = 0; i < 20; i++) {
    char c = EEPROM.read(i);
    if (c == ' ') break;
    password += c;
  }
  if (password.length() > 0) {
    correctPassword = password;
  }
}
