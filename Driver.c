//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//PRIMARY DRIVER [Driver.c]
//
// This file contains the main function from which all other functions are
// called, in addition to the robot's complete sweep of pragmas

//FIXME: Still need to figure out why its not letting us refer to our motors
//       and sensors by the names we assign them

/*----------------------------------PRAGMAS-----------------------------------*/
#pragma config(Motor,  motorA,          motorLeft,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorDep,      tmotorNXT, PIDControl, encoder)
#pragma config(Sensor, S1,     gyroSensor,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S2,              touchSensor,   sensorTouch)
#pragma config(Sensor, S3,     hallEffect,     sensorAnalog)
//#pragma config(Sensor, S1,     gyroSensor,           sensorDigitalIn)

//Mathematical Constants
#define PI (4 * atan(1))

//Defined powers and threshholds
#define BASE_MOTOR_POWER 40
#define DEP_MOTOR_POWER_OPEN 50 //Power used to open deposition system
#define DEP_MOTOR_POWER_CLOSE 60 //Power used to close the deposition system
#define HALL_EFFECT_THRESH_1 3 //We're going to need to compare to the actual beacon magnets
#define HALL_EFFECT_THRESH_2 15
#define HALL_EFFECT_THRESH_3 40

//Physical characteristics of robot
#define WHEEL_RADIUS 4.1   //cm
#define TURN_RADIUS 7.0    //cm; distance between wheels' contact points
#define BOT_LENGTH 22    //cm; distance from center of turning to AC deposition
#define HEIGHT_OF_MARKER 10 //cm; height of the LSTS marker, FIXME

//Filenames
#define SAT_MAP_FILENAME "satmap1.txt" //FIXME once we know how they are giving us the file!

//Struct Definitions
typedef struct SatelliteMap_struct{
	short map[275][365];
}SatelliteMap;

typedef struct MapVector_struct{
	short startLoc[2];
	short endLoc[2];
	float magnitude;
}MapVector;

//File Imports
#include "Utility.c"
#include "Sensors.c"
#include "BasicMovement.c"
#include "IntegratedMovement.c"
#include "Deposition.c"
#include "Bluetooth.c"
#include "SatelliteNavigation.c"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//TESTS
void runCOTTest(); //Code for a center-of-turning test
void runPointTurnTest(int angle); //, float radiusW, float radiusT);
void moveForwardTest(float distance);
void hallEffectTest(int base);
void bluetoothTest(int height);
void readGyro(int base);
//PROOF-OF-COMPETENCY TASKS
void pocTask1(short power);
void pocTask2();
void pocTask3(short power);
void pocTask4(short power, int hallBase);
void pocTask5(short power);
void pocTask45Combo(short power, int hallBase);
void pocTask6();
//PROOF-OF-COMPETENCY SUB-ROUTINES
void pocTask4Search2(short power, int hallBase); //Searches the 10cm x 30cm region
void pocTask5Path(short power); //Runs that weird path with the two turns

/*-----------------------------------MAIN-------------------------------------*/

//int fuckYou = 69;
//SatelliteMap satmap;

task main()
{
	clearDebugStream();

	//-----CALIBRATIONS/CONSTANTS-----/
	//halt();
	sleep(50);
	int HALL_BASE = calibrateHallEffect();
	int GYRO_BASE = calibrateGyro()
	sleep(50);
	//GYRO g;
	short BASE_POW = BASE_MOTOR_POWER;

	//SatelliteMap satmap;
	//processMap(&satmap, SAT_MAP_FILENAME); //Initializes w/ fileIO

	//------TEST  CODE------/

	//float distance = 50; //cm
	//moveForwardTest(distance);

	//bluetoothTest(HEIGHT_OF_MARKER);

	//closeGate(60);
	//dropAC();
	readGyro(GYRO_BASE);
	//gyroTurn(BASE_POW, GYRO_BASE, 90);
	//clearTimer(T1);
	//int i = 0;
	//for(i = 0; i<200; i++)
	//{
	//	writeDebugStream("%f\n", time1[T1]);
	//	sleep(5);
	//}

	//pocTask5Path(BASE_POW);
	//bool fuckThis = beaconSweep(-BASE_POW, HALL_BASE, 90);
	//writeDebugStream("%d", fuckThis);
	//hallEffectTest(HALL_BASE);
	//pocTask4Search2(BASE_POW, HALL_BASE);


	//pocTask1(BASE_POW);
	//pocTask3(BASE_POW);
	//pocTask4(BASE_POW, HALL_BASE);
	//pocTask5(BASE_POW);
	//pocTask45Combo(BASE_POW, HALL_BASE);
}

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
void runCOTTest()
{
	int numTurns = 4;
	int turnPower = 50;

	int i = 0;
	for(i = 0; i < numTurns; i++)
	{
		pointTurnTime(turnPower,1600);
		sleep(300);
		pointTurnTime(-turnPower,1600);
		sleep(300);
	}
}

void runPointTurnTest(int angle)
{
	short power = 60;
	pointTurn(power, angle);
}

void moveForwardTest(float distance)
{
	short power = 100;
	moveForward(power, distance);
}

void hallEffectTest(int base)
{
	int i = 0;
	for(i = 0; i < 2000; i++)
	{
		writeDebugStream("%d\t%d\n", nearBeacon(base), atBeacon(base));
		sleep(15);
	}
}

void bluetoothTest(int height) {
	sendAMessage(height);
}

void readGyro(int base)
{
	int i = 0;
	for(i = 0; i < 5000; i++)
	{
		writeDebugStream("%f\n", SensorValue(S1));//getGyro(base));
		sleep(15);
	}
}

void pocTask1(short power)
{
	pointTurn(power, 30); //Left
	sleep(0.5);
	moveForward(power, 1000); //NICK!: I don't know the actual distance here
}

void pocTask2()
{

}

void pocTask3(short power)
{
	moveForward(power, 1000.0); //NICK!: I don't know the actual distance here
}

void pocTask4(short power, int hallBase)
{
	moveForward(power, 40.0);
	pocTask4Search2(power, hallBase);
	//moveForward(power, 35);
	sleep(0.25);
	//dropAC();
	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15); //Sound does not play, brick only plays three sounds with 4 calls
}

void pocTask5(short power)
{
	pocTask5Path(power);
	moveForward(power, (30.0 + BOT_LENGTH));
	//moveForward(power, BOT_LENGTH);
	sleep(0.25);
	dropAC();
}

void pocTask45Combo(short power, int hallBase)
{
	pocTask5Path(power);
	moveForward(power, 12.0);
	sleep(0.25);
	pocTask4Search2(power, hallBase);
	moveForward(power, 35);
	sleep(0.25);
	dropAC();
	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15); //Sound does not play, brick only plays three sounds with 4 calls
}

void pocTask4Search2(short power, int hallBase)
{
	int distTraveled = 0;
	bool n = false;
	//bool at = false;

	while( (!n) && (distTraveled < 31))
	{
		if(beaconSweep(-power, hallBase, 20)) {
			n = true;
			break;
		}
		sleep(250);
		if(beaconSweep(power, hallBase, 40)) {
			n = true;
			break;
		}
		sleep(250);
		pointTurn(power, 18);
		sleep(250);
		moveForward(power,6);
		sleep(250);
		if(nearBeacon(hallBase))
		{
			n = true;
			break;
		}
		distTraveled += 6;
	}
}

void pocTask5Path(short power)
{
	moveForward(power, 45.0);
	sleep(250);
	pointTurn(-power, 90);
	sleep(250);
	moveForward(power, 15.0); //Changed from 20 to 15
	sleep(250);
	arcTurn(power, 15.0, 90);
	sleep(250);
	//moveForward(power, (30.0 + ));
	//moveForward(power, 30.0);
	//sleep(250);BOT_LENGTH
	//dropAC();
}

void pocTask6(int height)
{
	int i = 0;
	while( i == 0 ) {
		sendAMessage(height);
	}
}
