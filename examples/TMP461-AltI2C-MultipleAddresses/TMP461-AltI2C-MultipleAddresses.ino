/*
 * This will probably only compile for SAMD21 based boards
 * 
 */


#include <Wire.h>
#include "wiring_private.h"
#include "TMP461.h"


//TMP461
void readTemps();

TwoWire alt_i2c(&sercom1, 11, 13);

TMP461 tmp[] = {
  TMP461(&alt_i2c, 0x48),
  TMP461(&alt_i2c, 0x49),
  TMP461(&alt_i2c, 0x4A),
  TMP461(&alt_i2c, 0x4B),
  
  TMP461(&alt_i2c, 0x4C),
  TMP461(&alt_i2c, 0x4D),
  TMP461(&alt_i2c, 0x4E),
  TMP461(&alt_i2c, 0x4F)
};


float temps[] = {
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0
};



void setup() {

  alt_i2c.begin();
  pinPeripheral(11, PIO_SERCOM); // SDA
  pinPeripheral(13, PIO_SERCOM); // SCL
  
  alt_i2c.setClock(400000);

}


void loop() {
  readTemps();
}


// saves temperatures to array
void readTemps(){
  for(int i = 0; i < 8 ; i++){
    temps[i*2] = tmp[i].readLocalTemp();
  }
  for(int i = 0; i < 8 ; i++){
    temps[i*2 + 1] = tmp[i].readRemoteTemp();
  }
}
