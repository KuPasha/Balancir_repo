#pragma once

#include "Structs.h"
#include <Wire.h>
#include <SoftwareSerial.h>

const uint8_t IMUAddress = 0x68;

void parseData(DataParsed &parsedData, uint8_t *rawData);


void i2cWrite(uint8_t registerAddress, uint8_t data);
uint8_t* i2cRead(uint8_t registerAddress, uint8_t nbytes);

void serialPrint(DataParsed &dp);
