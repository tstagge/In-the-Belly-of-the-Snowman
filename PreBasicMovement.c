//ENGR 142 Project 3
//Team 57
//   Jillian Hestle, Emily Schott, Tyler Stagge, Nicholas Vilbrandt

//Test Module 1: Pre-Basic Movement

#pragma config(Motor,  motorA,          motorLeft,     tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "PreBasicMovement_Header.h"

void turnLeft();
void turnRight();
void stopMotors();

task main()
{
	clearDebugStream();

	sleep(250);

	turnRight();
	stopMotors();
	turnLeft();
	stopMotors();
	//driveStraight();
	//stopMotors();
	/*turnRight();
	stopMotors();
	turnLeft();
	stopMotors();*/

}

void turnLeft()
{
	motor[motorA] = -50;
	motor[motorB] = 50;
	sleep(1400);
}

void turnRight()
{
	motor[motorA] = 50;
	motor[motorB] = -50;
	sleep(1400);
}

void stopMotors()
{
	motor[motorA] = 0;
	motor[motorB] = 0;
	sleep(250);
}
