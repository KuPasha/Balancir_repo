#include "Utils.h"
#include <stdio.h>

void parseData(DataParsed &parsedData, uint8_t *rawData)
{
	int16_t accX, accY, accZ, tempRaw, gyroX, gyroY, gyroZ;
	accX = ((rawData[0] << 8) | rawData[1]);
	accY = ((rawData[2] << 8) | rawData[3]);
	accZ = ((rawData[4] << 8) | rawData[5]);
	tempRaw = ((rawData[6] << 8) | rawData[7]);
	gyroX = ((rawData[8] << 8) | rawData[9]);
	gyroY = ((rawData[10] << 8) | rawData[11]);
	gyroZ = ((rawData[12] << 8) | rawData[13]);

	parsedData.acc[0] = 9.81*accX / 16384.;
	parsedData.acc[1] = 9.81*accY / 16384.;
	parsedData.acc[2] = 9.81*accZ / 16384.;
	/* Calculate the angls based on the different sensors and algorithm */
	parsedData.temp = ((float) tempRaw) / 333.87 + 21.0;

	parsedData.dphi[0] = (double)gyroX / 131.0;
	parsedData.dphi[1] = -((double)gyroY / 131.0);
	parsedData.dphi[2] = -((double)gyroZ / 131.0);
};


void i2cWrite(uint8_t registerAddress, uint8_t data) {
	Wire.beginTransmission(IMUAddress);
	Wire.write(registerAddress);
	Wire.write(data);
	Wire.endTransmission(); // Send stop
}

uint8_t data[32];
uint8_t* i2cRead(uint8_t registerAddress, uint8_t nbytes) {

	Wire.beginTransmission(IMUAddress);
	Wire.write(registerAddress);
	Wire.endTransmission(false); // Don't release the bus
	Wire.requestFrom(IMUAddress, nbytes); // Send a repeated start and then release the bus after reading
	for (uint8_t i = 0; i < nbytes; i++)
		data[i] = Wire.read();
	return data;
}

void serialPrint(DataParsed &dp)
{
  char buf[128] = { 0 };
  sprintf(buf, "ax = %7.3f ay = %7.3f az = %7.3f wx = %7.2f wy = %7.2f wz = %7.2f",
    dp.acc[0],
    dp.acc[1],
    dp.acc[2],
    dp.dphi[0],
    dp.dphi[1],
    dp.dphi[2]
  );
  Serial.println(buf);
};
