void setup() {
  Serial.begin(115200);
}

void loop() {
  Fingerprint_Management_Module();  
  RFID_Management_Module();         
  Numpad_Module();       
}
