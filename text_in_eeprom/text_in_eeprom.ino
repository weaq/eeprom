#include <EEPROM.h>
char tmpData[300];
String stringOne = "1,2,3,4,5,6,#####0:47520:60#0:47520:60";
String arrServResp[6];
void setup() {
  EEPROM.begin(512);  // setup
  Serial.begin(115200);

  // Write data to eeprom
  stringOne.toCharArray(tmpData, 300);
  EEPROM.put(0, tmpData);
  EEPROM.commit();

  // Read data from eeprom
  EEPROM.get(0, tmpData);
  String serverResponse = String(tmpData);

  //=== split server response to arrServResp array
  //String serverResponse = "weekOfDay,minInDay,relayActiveInWeek";
  char sz[300];
  serverResponse.toCharArray(sz, sizeof(sz));

  // split string to array
  char *str, *p = sz;
  int i = 0;
  while (str = strtok (p, ",")){
    arrServResp[i] = str;
    p = NULL;
    ++i;
  }

  
}
void loop() {
  Serial.println(arrServResp[5]);
  Serial.println(arrServResp[4]);
}
