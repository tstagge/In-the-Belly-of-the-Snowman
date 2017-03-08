//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//GENERAL SENSOR INTERPRETATION MODULE [Sensors.c]
//
//This file contains the functions required to operate and interpret most
//sensors utilized by the ALV; see Driver.c for pragmas and global variables

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
int calibrateHallEffect();
int getHallEffect(int base);
bool nearBeacon(int base);
bool atBeacon(int base);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
int calibrateHallEffect()
{
	return SensorValue(S3);
}

int getHallEffect(int base)
{
	return -(SensorValue(S3) - base);
}

bool nearBeacon(int base)
{
	int thresh1 = HALL_EFFECT_THRESH_1;
	return (getHallEffect(base) >= thresh1);
}

bool atBeacon(int base)
{
	int thresh3 = HALL_EFFECT_THRESH_3;
	return (getHallEffect(base) >= thresh3);
}
