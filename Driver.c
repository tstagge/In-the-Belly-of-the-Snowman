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

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void runCOTTest(); //Code for a center-of-turning test

/*-----------------------------------MAIN-------------------------------------*/
task main()
{
	runCOTTest();
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
