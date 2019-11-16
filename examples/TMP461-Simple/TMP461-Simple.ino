/*
 * Untested
 * 
 */
#include <Wire.h>
#include "TMP461.h"

TMP461 tmp = TMP461(&Wire, 0x48);

void setup() {
  Wire.begin();

  Serial.begin(250000);
}


void loop() {
  Serial.print("Local temp: ");
  Serial.print(tmp.readLocalTemp());
  Serial.print("\t Remote temp: ");
  Serial.println(tmp.readLocalTemp());
  delay(1000);
}
