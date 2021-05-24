#pragma once
#include <stdint.h>

struct DataRaw
{
	float acc[3]; // X, Y, Z
	float w[3]; // X, Y, Z
	float tRaw;
};

struct DataParsed
{
	float sysTime;
	float acc[3];
	float temp; // темрература, С
	float w[3];
	float dphi[3];
	float accAng;
	float s, v;
	int pwmVal;
};

struct ContolStr
{
	float angVal;

	ContolStr() : angVal(0.) { };
};

struct AvrgIMU
{
	float acc[3][10];
	float dPhi[3][10];
	int cnt;
};