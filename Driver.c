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
#pragma config(Sensor, S2,              touchSensor,   sensorTouch)
#pragma config(Sensor, S3,     hallEffect,     sensorAnalog)

//Mathematical Constants
#define PI (4 * atan(1))

//Defined powers and threshholds
#define BASE_MOTOR_POWER 40
#define DEP_MOTOR_POWER 50 //Power used for deposition system
#define HALL_EFFECT_THRESH_1 3 //We're going to need to compare to the actual beacon magnets
#define HALL_EFFECT_THRESH_2 15
#define HALL_EFFECT_THRESH_3 40

//Physical characteristics of robot
#define WHEEL_RADIUS 4.1   //cm
#define TURN_RADIUS 7.0    //cm; distance between wheels' contact points
#define BOT_LENGTH 22    //cm; distance from center of turning to AC deposition


#include "Utility.c"
#include "Sensors.c"
#include "BasicMovement.c"
#include "IntegratedMovement.c"
#include "Deposition.c"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//TESTS
void runCOTTest(); //Code for a center-of-turning test
void runPointTurnTest(int angle); //, float radiusW, float radiusT);
void moveForwardTest(float distance);
void hallEffectTest(int base);
//PROOF-OF-COMPETENCY TASKS
void pocTask1();
void pocTask2();
void pocTask3();
void pocTask4(int power, int hallBase);
void pocTask5(int power);
void pocTask6();
void pocTask4Search(int power, int hallBase);
void pocTask4Search2(int power, int hallBase);
void pocTask5Path(int power);

/*-----------------------------------MAIN-------------------------------------*/
task main()
{
	clearDebugStream();

	//-----CALIBRATIONS-----/
	int HALL_BASE = calibrateHallEffect();
	int BASE_POW = BASE_MOTOR_POWER;

	//------TEST  CODE------/

	//float distance = 90; //cm
	//moveForwardTest(distance);

	//pocTask5Path(BASE_POW);
	//bool fuckThis = beaconSweep(-BASE_POW, HALL_BASE, 90);
	//writeDebugStream("%d", fuckThis);
	//hallEffectTest(HALL_BASE);
	pocTask4Search2(BASE_POW, HALL_BASE);
	pocTask4(BASE_POW, HALL_BASE);
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
	int power = 60;
	pointTurn(power, angle);
}

void moveForwardTest(float distance)
{
	int power = 60;
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

void pocTask1()
{

}

void pocTask2()
{

}

void pocTask3()
{

}

void pocTask4(int power, int hallBase)
{
	pocTask4Search2(power, hallBase);
	moveForward(power, 35);
	sleep(0.25);
	dropAC();
}

void pocTask5(int power)
{
	pocTask5Path(power);
	dropAC();
}

/*void pocTask4Search(int power, int hallBase)
{
	//Search region is 10cm wide and 30cm long
	bool near = false;
	int distTraveled = 0;
	//short at = 0;

	while((!near) && (distTraveled < 31))
	{
		if(beaconSweep(power, hallBase, -10)) {
			near = true; break;
		}
		if(beaconSweep(power, hallBase, 20)) {
			near = true; break;
		}
		moveForward(power, 6);
		distTraveled += 6;
	}
}*/

void pocTask4Search2(int power, int hallBase)
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
		pointTurn(-power, 18);
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

void pocTask5Path(int power)
{
	moveForward(power, 45.0);
	sleep(250);
	pointTurn(-power, 90);
	sleep(250);
	moveForward(power, 15.0); //Changed from 20 to 15
	sleep(250);
	arcTurn(power, 15.0, 90);
	sleep(250);
	moveForward(power, (30.0 + BOT_LENGTH));
	sleep(250);
	//dropAC();
}

void pocTask6()
{

}
