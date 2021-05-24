
#include "Utils.h"


// Двигатель A
#define in1 5  
#define in2 0  
// Двигатель B
#define in3 4  
#define in4 2  

#define D5 14
#define D6 12

ContolStr ctrlPack;
DataParsed dat;

void setup()
{
  Wire.begin(12, 14); // D2, D1

  i2cWrite(0x6B, 0x00); // Disable sleep mode      
  Serial.begin(115200);
}

void loop()
{
  /* Update all the values */
  uint8_t* data = i2cRead(0x3B, 14);
  parseData(dat, data);

  serialPrint(dat);
}
