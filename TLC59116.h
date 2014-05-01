/*
 * Copyright (c) 2014, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 * 
 *  3. Neither the name of Majenko Technologies nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _TLC59116_H
#define _TLC59116_H

#if (ARDUINO >= 100) 
# include <Arduino.h>
#else
# include <WProgram.h>
#endif

#include <Wire.h>

#define TLC59116_BASEADDR   0b1100000
#define TLC59116_ALLCALL    0b1101000
#define TLC59116_SUB1       0b1101001
#define TLC59116_SUB2       0b1101010
#define TLC59116_SUB3       0b1101100
#define TLC59116_RESET      0b1101011

#define TLC59116_MODE1      0x00
#define TLC59116_MODE2      0x01
#define TLC59116_PWM0       0x02
#define TLC59116_PWM1       0x03
#define TLC59116_PWM2       0x04
#define TLC59116_PWM3       0x05
#define TLC59116_PWM4       0x06
#define TLC59116_PWM5       0x07
#define TLC59116_PWM6       0x08
#define TLC59116_PWM7       0x09
#define TLC59116_PWM8       0x0A
#define TLC59116_PWM9       0x0B
#define TLC59116_PWM10      0x0C
#define TLC59116_PWM11      0x0D
#define TLC59116_PWM12      0x0E
#define TLC59116_PWM13      0x0F
#define TLC59116_PWM14      0x10
#define TLC59116_PWM15      0x11
#define TLC59116_GRPPWM     0x12
#define TLC59116_GRPFREQ    0x13
#define TLC59116_LEDOUT0    0x14
#define TLC59116_LEDOUT1    0x15
#define TLC59116_LEDOUT2    0x16
#define TLC59116_LEDOUT3    0x17
#define TLC59116_SUBADR1    0x18
#define TLC59116_SUBADR2    0x19
#define TLC59116_SUBADR3    0x1A
#define TLC59116_ALLCALLADR 0x1B
#define TLC59116_IREF       0x1C
#define TLC59116_EFLAG1     0x1D
#define TLC59116_EFLAG2     0x1E

class TLC59116 {
    private:
        // Private functions and variables here.  They can only be accessed
        // by functions within the class.
        uint8_t _addr;
        void writeRegister(uint8_t reg, uint8_t val);

    public:
        // Public functions and variables.  These can be accessed from
        // outside the class.
        TLC59116();
        TLC59116(uint8_t addr);
        void begin();
        void analogWrite(uint8_t chan, uint8_t b);


};
#endif
