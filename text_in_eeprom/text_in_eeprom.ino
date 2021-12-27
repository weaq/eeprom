#include <EEPROM.h>
float value;
float x = 123.45;
char txt[30] ;
char data[] = "text in eeprom";
void setup() {
  EEPROM.begin(512);  // setup
  Serial.begin(115200);
  // write data (put use update function)
  EEPROM.put(0, x);
  EEPROM.put(sizeof(x), data);
  EEPROM.commit();

  // read data
  EEPROM.get(0, value);
  EEPROM.get(sizeof(x), txt);
}
void loop() {
  Serial.println(value);
  Serial.println(txt);
}
