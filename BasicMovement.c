//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BASIC MOBILITY and OPERATION FUNCTIONS [BasicMovement.c]
//
// This file contains all the functions the robot will use to move or otherwise
// actuate any of its components. See [Driver.c] for all pragmas.

//FIXME: Need to figure out how to properly refer to motors by their assigned
// names as opposed to "motorA" and "motorB"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void halt(); //Stops drive motors only
void fullStop(); //Stops all motors
void drive(int power, int timeMS);
void driveIndef(int power);
void pointTurn(int power, int timeMS); //Positive is LEFT
void pointTurnIndef(int power);
void pivotTurn(int power, int timeMS); //Positive is LEFT

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
task main(){
}

void halt()
{
	motor[motorA] = 0;
	motor[motorB] = 0;
	//sleep required?
}

void fullStop()
{
	motor[motorA] = 0;
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void driveIndef(int power)
{
	motor[motorA] = power;
	motor[motorB] = power;
}

void drive(int power, int timeMS)
{
	motor[motorA] = power;
	motor[motorB] = power;
	sleep(timeMS);
	halt();
}

void pointTurn(int power, int timeMS)
{
	motor[motorA] = -power;
	motor[motorB] = power;
	sleep(timeMS);
	halt();
}

void pointTurnIndef(int power)
{
	motor[motorA] = -power;
	motor[motorB] = power;
}

void pivotTurn(int power, int timeMS)
{
	if(power > 0)    //If left
		motor[motorB]; //power right
	else             //If right
		motor[motorA]; //power left
	sleep(timeMS)
	halt();
}
