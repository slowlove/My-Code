#include <htc.h>
#include "i2c.h"

void i2c_start(){
	SEN = 1;
	while(SEN);
}
void i2c_stop(){
	PEN = 1;
	while(PEN);
}
unsigned char i2c_read(unsigned char ack){
	RCEN = 1;
	while(RCEN);
	ACKDT = ack;
	ACKEN = 1;
	while(ACKEN);
	return SSPBUF;
}
unsigned char i2c_write(unsigned char d){
	WCOL = 0;
	SSPIF = 0;
	SSPBUF = d;
	asm("nop");
	asm("nop");
	asm("nop");
	if(WCOL) return 2;			// write collision
	else {
		while(!SSPIF);
		if(ACKSTAT) return 1;	// not acknowledge
		return 0;				// everything is ok
	}
}

void i2c_init(){
	
	RC3 = 1;
	RC4 = 1;
	TRISC3 = 1;
	TRISC4 = 1; //	control by mssp
	
	SSPADD = 9;		// Baudrate = Fosc/4/(SSPADDR+1)
	SMP = 1; 		// slew rate control disabled for 100KHz baudrate
	SSPCON2 = 0;	
	SSPCON = 0x28; //I2C Master Hardware mode
}
