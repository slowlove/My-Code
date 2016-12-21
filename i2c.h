#ifndef	_I2C_H_
#define	_I2C_H_

void i2c_start();
void i2c_stop();
void i2c_init();
unsigned char i2c_read(unsigned char ack);
				// ack = 1: Not Acknowledge
				// ack = 0: Acknowledge
unsigned char i2c_write(unsigned char d);
				// d: 8-bit data
#endif