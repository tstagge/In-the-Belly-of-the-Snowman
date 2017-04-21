//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//GENERAL SENSOR shortERPRETATION MODULE [Sensors.c]
//
//This file contains the functions required to operate and shorterpret most
//sensors utilized by the ALV; see Driver.c for pragmas and global variables

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
	short hallNum = 0;
	short i = 0;
	while (i < 50) {
		hallNum = hallNum + SensorValue(S3);
		sleep(1);
		i++;
	}
	hallNum = hallNum / 50;
	return hallNum;
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
	return (getHallEffect(base) < thresh3);
	//short thresh3 = HALL_EFFECT_THRESH_3;

	//return (getHallEffect(base) < thresh3);
	return (getHallEffect(base) >= thresh3);
}

int calibrateGyro()
{
	if(SensorType(S1) != sensorAnalogInactive) {
		setSensorType(S1, sensorAnalogInactive);
	}
	int count = 0;
	int sensorValSum = 0;
	for(count = 0; count < 500; count++) {
		sensorValSum = sensorValSum + SensorValue(S1);
		wait1Msec(5);
	}
	int sensorValAvg = sensorValSum / 500;
	return sensorValAvg;
}

short getGyro(int base)
{
	//Note: for raw gyro readings, positive is right, negative is left
	//      Thus they are being flipped to be consistent with the standard that positive is left
	return -(SensorValue(S1) - base);
}
