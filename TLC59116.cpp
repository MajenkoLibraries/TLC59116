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


#include <TLC59116.h>

static inline void wiresend(unsigned char x) {
#if ARDUINO >= 100
    Wire.write((unsigned char)x);
#else
    Wire.send(x);
#endif
}

static inline unsigned char wirerecv(void) {
#if ARDUINO >= 100
    return Wire.read();
#else
    return Wire.receive();
#endif
}

TLC59116::TLC59116() {
    _addr = 0;
}

TLC59116::TLC59116(uint8_t addr) {
    _addr = addr;
}

void TLC59116::begin() {
    Wire.begin();
    writeRegister(TLC59116_MODE1, 0x01);
    delay(1);
    writeRegister(TLC59116_MODE2, 0x00);
    writeRegister(TLC59116_LEDOUT0, 0b10101010);
    writeRegister(TLC59116_LEDOUT1, 0b10101010);
    writeRegister(TLC59116_LEDOUT2, 0b10101010);
    writeRegister(TLC59116_LEDOUT3, 0b10101010);
    this->analogWrite(0, 0);
    this->analogWrite(1, 0);
    this->analogWrite(2, 0);
    this->analogWrite(3, 0);
    this->analogWrite(4, 0);
    this->analogWrite(5, 0);
    this->analogWrite(6, 0);
    this->analogWrite(7, 0);
    this->analogWrite(8, 0);
    this->analogWrite(9, 0);
    this->analogWrite(10, 0);
    this->analogWrite(11, 0);
    this->analogWrite(12, 0);
    this->analogWrite(13, 0);
    this->analogWrite(14, 0);
    this->analogWrite(15, 0);
}


void TLC59116::writeRegister(uint8_t reg, uint8_t val) {
    Wire.beginTransmission(TLC59116_BASEADDR | (_addr & 0x0F));
    wiresend(reg);
    wiresend(val);
    Wire.endTransmission();
}

void TLC59116::analogWrite(uint8_t chan, uint8_t b) {
    writeRegister(TLC59116_PWM0 + (chan & 0x0F), b);
}
