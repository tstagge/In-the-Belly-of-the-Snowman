//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//PRIMARY DRIVER [Driver.c]
//
// This file contains the main function from which all other functions are
// called, in addition to the robot's complete sweep of pragmas

/*----------------------------------PRAGMAS-----------------------------------*/
#pragma config(Motor,  motorA,          motorLeft,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorDep,      tmotorNXT, PIDControl, encoder)
#pragma config(Sensor, S2,              touchSensor,   sensorTouch)

#define DEP_MOTOR_POWER 50 //Power used for deposition system
#define WHEEL_RADIUS 4.1   //cm
#define TURN_RADIUS 7.0    //cm
#define PI (4 * atan(1))

#include "Utility.c"
#include "BasicMovement.c"
#include "Deposition.c"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//TESTS
void runCOTTest(); //Code for a center-of-turning test
void runPointTurnTest(int angle); //, float radiusW, float radiusT);
void moveForwardTest(float distance);
//PROOF-OF-COMPETENCY TASKS
void pocTask1();
void pocTask2();
void pocTask3();
void pocTask4();
void pocTask5();
void pocTAsk6();

/*-----------------------------------MAIN-------------------------------------*/
task main()
{
	clearDebugStream();
	//float distance = 90; //cm
	//moveForwardTest(distance);
	//moveForward(10,1.0);
	//int i = 0;
	//for(i = 0; i < 1; i++)
	arcTurn(-60,20.0,90);
	//pivotTurn(60,2000);
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

void pocTask1()
{

}

void pocTask2()
{

}

void pocTask3()
{

}

void pocTask4()
{

}

void pocTask5()
{

}

void pocTAsk6()
{

}
