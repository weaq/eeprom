#include <EEPROM.h>

String data = "{\"freedom\":{\"0\":\"1\",\"1\":\"2\",\"2\":\"2\",\"3\":\"1\"},\"wDay\":{\"0\":{\"0\":\"1\",\"1\":\"1\",\"2\":\"1\",\"3\":\"1\",\"4\":\"1\",\"5\":\"1\",\"6\":\"1\"},\"1\":{\"0\":\"1\",\"1\":\"1\",\"2\":\"1\",\"3\":\"1\",\"4\":\"1\",\"5\":\"1\",\"6\":\"1\"},\"2\":{\"0\":\"1\",\"1\":\"1\",\"2\":\"1\",\"3\":\"1\",\"4\":\"1\",\"5\":\"1\",\"6\":\"1\"},\"3\":{\"0\":\"1\",\"1\":\"1\",\"2\":\"1\",\"3\":\"1\",\"4\":\"1\",\"5\":\"1\",\"6\":\"1\"}},\"sTime\":{\"0\":{\"0\":82800,\"1\":82800,\"2\":82800,\"3\":82800},\"1\":{\"0\":82800,\"1\":82800,\"2\":82800,\"3\":82800},\"2\":{\"0\":82800,\"1\":82800,\"2\":82800,\"3\":82800},\"3\":{\"0\":82800,\"1\":82800,\"2\":82800,\"3\":82800}},\"aTime\":{\"0\":{\"0\":\"3600\",\"1\":\"3600\",\"2\":\"3600\",\"3\":\"3600\"},\"1\":{\"0\":\"3600\",\"1\":\"3600\",\"2\":\"3600\",\"3\":\"3600\"},\"2\":{\"0\":\"3600\",\"1\":\"3600\",\"2\":\"3600\",\"3\":\"3600\"},\"3\":{\"0\":\"3600\",\"1\":\"3600\",\"2\":\"3600\",\"3\":\"3600\"}},\"unitTime\":4}";

void setup() {
  Serial.begin(115220);
  EEPROM.begin(1024);
  
  Serial.print("Write Data:");
  Serial.println(data);

  eeprom_write(10, data);  // Write at address 10
  delay(10);
}

void loop() {
  Serial.println(data.length());
  String recivedData = eeprom_read(10); // Read at address 10
  Serial.print("Read Data:");
  Serial.println(recivedData);
  delay(1000);
}

void eeprom_write(char add,String data) {
  int _size = data.length();
  for(int i=0;i<_size;i++) {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   // Add termination null character for String Data
  EEPROM.commit();
}

String eeprom_read(char add) {
  char data[1024]; // Max 1024 Bytes
  int len=0;
  unsigned char k = EEPROM.read(add);
  while(k != '\0' && len<1024) {   // Read until null character
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
