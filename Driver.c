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

#include "BasicMovement.c"

#define WHEEL_RADIUS 4.1 //cm
#define TURN_RADIUS 7.0 //cm
#define DEP_MOTOR_POWER 50

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void runCOTTest(); //Code for a center-of-turning test
void runPointTurnTest(int angle, float radiusW, float radiusT);
<<<<<<< HEAD
void moveForwardTest(float radius, float distance);
=======
void pocTask1();
void pocTask2();
void pocTask3();
void pocTask4();
void pocTask5();
void pocTAsk6();

>>>>>>> origin/master
/*-----------------------------------MAIN-------------------------------------*/
task main()
{
	float radiusWheel = 4.1 //cm
	float radiusBot = 7; //cm
	float distance = 10; //cm

	moveForwardTest(radiusWheel,distance);
}

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
void runCOTTest()
{
	int numTurns = 4;
	int turnPower = 50;

	int i = 0;
	for(i = 0; i < numTurns; i++)
	{
		pointTurn(turnPower,1600);
		sleep(300);
		pointTurn(-turnPower,1600);
		sleep(300);
	}
}

void runPointTurnTest(int angle, float radiusW, float radiusT)
{
	int power = 30;

	pointTurnAngle(power, angle, radiusW, radiusT);

}

<<<<<<< HEAD
void moveForwardTest(float radius, float distance) {
	int power = 50;

	moveForward(power, distance, radius);
=======
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
>>>>>>> origin/master

}
