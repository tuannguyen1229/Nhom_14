#include "Numpad_Module.h"
#include <Wire.h>

#define TTP229_ADDR 0x57

char readKeyChar() {
  Wire.requestFrom(TTP229_ADDR, 1);
  if (Wire.available()) {
    uint8_t key = Wire.read();
    if (key > 0 && key <= 16) {
      return '0' + key; // Cần map lại nếu cần đúng ký tự trên bàn phím
    }
  }
  return 0;
}
