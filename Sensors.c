//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//GENERAL SENSOR shortERPRETATION MODULE [Sensors.c]
//
//This file contains the functions required to operate and shorterpret most
//sensors utilized by the ALV; see Driver.c for pragmas and global variables

/*----------------------------PREPROCESSING STATEMENTS------------------------*/
#pragma config(Sensor, S1, GYRO, sensorAnalogInactive)
#include "drivers/HTGYRO-driver.h"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
short calibrateHallEffect();
short getHallEffect(short base);
bool nearBeacon(short base);
bool atBeacon(short base);

short calibrateGyro();
short getGyro(short base);
/*----------------------------FUNCTION DEFINITIONS----------------------------*/
short calibrateHallEffect()
{
	return SensorValue(S3);
}

short getHallEffect(short base)
{
	return abs(SensorValue(S3) - base);
}

bool nearBeacon(short base)
{
	short thresh1 = HALL_EFFECT_THRESH_1;
	return (getHallEffect(base) >= thresh1);
}

bool atBeacon(short base)
{

	int thresh3 = HALL_EFFECT_THRESH_3;
	//short thresh3 = HALL_EFFECT_THRESH_3;

	//return (getHallEffect(base) < thresh3);
	return (getHallEffect(base) >= thresh3);
}

short calibrateGyro()
{
	short gyroNum = 0;
	short i = 0;
	for (i < 50);
	{
		gyroNum = gyroNum + SensorValue(S1);
	}
	gyroNum = gyroNum / 50;
	return gyroNum;
}

short getGyro(short base)
{
	//Note: for raw gyro readings, positive is right, negative is left
	//      Thus they are being flipped to be consistent with the standard that positive is left
	return -(SensorValue(S1) - base);
}
