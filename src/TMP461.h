/*
* TMP461.h
*
* Created: 10/27/2019 9:56:36 PM
* Author: wes
*/


#ifndef __TMP461_H__
#define __TMP461_H__


#include "Arduino.h"
#include "Wire.h"

#define R_LOCALTEMP_H				0x00
#define R_LOCALTEMP_L				0x15
#define R_REMOTETEMP_H				0x01
#define R_REMOTETEMP_L				0x10

#define R_STATUS_REG				0x02
#define R_CONFIG_REG				0x03
#define W_CONFIG_REG				0x09

#define R_CONV_RATE					0x04
#define W_CONV_RATE					0x0A

#define R_LOCAL_HIGH_LIMIT			0x05
#define W_LOCAL_HIGH_LIMIT			0x0B

#define R_LOCAL_LOW_LIMIT			0x06
#define W_LOCAL_LOW_LIMIT			0x0C

#define R_LOCAL_HIGH_LIMIT			0x05
#define W_LOCAL_HIGH_LIMIT			0x0B

#define R_REMOTE_LOW_LIMIT_H		0x08
#define W_REMOTE_LOW_LIMIT_H		0x0E

#define R_REMOTE_HIGH_LIMIT_H		0x07
#define W_REMOTE_HIGH_LIMIT_H		0x0D

#define R_REMOTE_LOW_LIMIT_L		0x14
#define W_REMOTE_LOW_LIMIT_L		0x14

#define R_REMOTE_HIGH_LIMIT_L		0x13
#define W_REMOTE_HIGH_LIMIT_L		0x13

#define W_ONE_SHOT_START			0x0F

#define W_REMOTE_TEMP_OFFSET_H		0x11
#define R_REMOTE_TEMP_OFFSET_H		0x11

#define W_REMOTE_TEMP_OFFSET_L		0x12
#define R_REMOTE_TEMP_OFFSET_L		0x12

#define R_CHANNEL_EN				0x16
#define w_CHANNEL_EN				0x16

#define W_REMOTE_TEMP_THERM_LIMIT	0x19
#define R_REMOTE_TEMP_THERM_LIMIT	0x19

#define W_LOCAL_TEMP_THERM_LIMIT	0x20
#define R_LOCAL_TEMP_THERM_LIMIT	0x20

#define W_THERM_HYSTERESIS			0x21
#define R_THERM_HYSTERESIS			0x21

#define W_CONSECUTIVE_ALERT			0x22
#define R_CONSECUTIVE_ALERT			0x22


#define W_NFACTOR					0x23
#define R_NFACTOR					0x23

#define W_DIGITAL_FILTER			0x24
#define R_DIGITAL_FILTER			0x24

#define R_MFG_ID					0xFE







class TMP461
{
	//variables
	public:
	protected:
	private:
	uint8_t _i2caddr;
	TwoWire *_i2c;

	//functions
	public:
	
	TMP461(uint8_t addr = 0x48);
	TMP461(TwoWire *i2c, uint8_t addr = 0x48);
	void begin(void);
	void resetAll(void);
	
	float readLocalTemp();
	float readRemoteTemp();
	
	void setFilterLevel(uint8_t);
	void setNFactor(uint8_t);
	
	protected:
	private:


	
	//uint8_t read8(uint8_t addr);
	//void write8(uint8_t addr, uint8_t d);

}; //TMP461

#endif //__TMP461_H__
