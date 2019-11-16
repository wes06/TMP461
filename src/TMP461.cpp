/*
* TMP461.cpp
*
* Created: 10/27/2019 9:56:35 PM
* Author: wes
*/


#include "TMP461.h"

/**************************************************************************/
/*!
@brief  Instantiates a new TMP461 chip with the I2C address on the Wire interface.
@param  addr The 7-bit I2C address to locate this chip, default is 0x48
*/
/**************************************************************************/
TMP461::TMP461(uint8_t addr) {
	_i2caddr = addr;
}

/**************************************************************************/
/*!
@brief  Instantiates a new TMP461 chip with the I2C address on the Wire interface.
@param  i2c  A pointer to a 'Wire' compatible object that we'll use to communicate with
@param  addr The 7-bit I2C address to locate this chip, default is 0x48
*/
/**************************************************************************/
TMP461::TMP461(TwoWire *i2c, uint8_t addr) {
	_i2c = i2c;
	_i2caddr = addr;
}



/**************************************************************************/
/*!
@brief  Setups the I2C interface and hardware
*/
/**************************************************************************/
void TMP461::begin(void) {
	//_i2c->begin();
	//reset();
}



/**************************************************************************/
/*!
@brief  Software resets all TMP461s on bus
*/
/**************************************************************************/
void TMP461::resetAll(void) {
	
	
	// general call address 0x00
	// second byte should be 0x06
}





/**************************************************************************/
/*!
@brief  Returns local temperature in Celcius
*/
/**************************************************************************/
float TMP461::readLocalTemp() {
	_i2c->beginTransmission(_i2caddr);
	_i2c->write(R_LOCALTEMP_H);
	_i2c->endTransmission();

	_i2c->requestFrom((uint8_t)_i2caddr, (uint8_t)1);
	return _i2c->read();
}



/**************************************************************************/
/*!
@brief  Returns remote temperature in Celcius
*/
/**************************************************************************/
float TMP461::readRemoteTemp() {
	_i2c->beginTransmission(_i2caddr);
	_i2c->write(R_REMOTETEMP_H);
	_i2c->endTransmission();

	_i2c->requestFrom((uint8_t)_i2caddr, (uint8_t)1);
	return _i2c->read();
}



/**************************************************************************/
/*!
@brief  Sets digital filter level
@param Level of digital filtering (0 = off, 1 = 4 Sample avg, 2 = 8 Sample avg)
*/
/**************************************************************************/
void TMP461::setFilterLevel(uint8_t level) {
	if(level == 0 || level == 1 || level == 2){
		_i2c->beginTransmission(_i2caddr);
		_i2c->write(W_DIGITAL_FILTER);
		_i2c->write(level);
		_i2c->endTransmission();
	};
}





/**************************************************************************/
/*!
@brief  Sets N Factor correction register
@param 
*/
/**************************************************************************/
void TMP461::setNFactor(uint8_t level) {
		_i2c->beginTransmission(_i2caddr);
		_i2c->write(W_NFACTOR);
		_i2c->write(level);
		_i2c->endTransmission();
}

/**************************************************************************/
/*!
@brief  Returns value from address
@param  address to read from
*/
/**************************************************************************/

/*
uint8_t TMP461::read8(uint8_t addr) {
	_i2c->beginTransmission(_i2caddr);
	_i2c->write(addr);
	_i2c->endTransmission();

	_i2c->requestFrom((uint8_t)_i2caddr, (uint8_t)1);
	return _i2c->read();
}*/


/**************************************************************************/
/*!
@brief  Writes a value to a given address
@param  address/pointer to write to
@param  data to write
*/
/**************************************************************************/


/*
void TMP461::write8(uint8_t addr, uint8_t d) {
	_i2c->beginTransmission(_i2caddr);
	_i2c->write(addr);
	_i2c->write(d);
	_i2c->endTransmission();
}*/


