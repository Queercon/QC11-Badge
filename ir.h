/*
 * ir.h
 *
 *  Created on: Jun 28, 2014
 *      Author: George
 */

#ifndef IR_H_
#define IR_H_

#include <stdint.h>

void init_serial();
void ir_write_single_byte(uint8_t);
void ir_write(uint8_t*, uint8_t );
uint8_t ir_check_crc();

#endif /* IR_H_ */