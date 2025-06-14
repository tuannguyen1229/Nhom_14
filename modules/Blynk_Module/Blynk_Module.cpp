#include <BlynkSimpleEsp32.h>
#include "Blynk_Module.h"

#define BLYNK_TEMPLATE_ID "TMPL69KGNKrTW"
#define BLYNK_TEMPLATE_NAME "SMART DOOR"
#define BLYNK_AUTH_TOKEN "7mnt23AXWcLs8Mr6yxY6RAIiryu9jT12"

void setupBlynk() {
    Blynk.begin(BLYNK_AUTH_TOKEN, "TP-Link_5C84", "75583521");
}

void runBlynk() {
    Blynk.run();
}
