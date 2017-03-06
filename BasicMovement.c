//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BASIC MOBILITY and OPERATION FUNCTIONS [BasicMovement.c]
//
// This file contains all the functions the robot will use to move or otherwise
// operate its drive system. See [Driver.c] for all pragmas.

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
void pointTurnAngle(int power, int angle, float radiusWheel, float radiusBot);
void moveForward(int power, float distance, float radius);


/*----------------------------FUNCTION DEFINITIONS----------------------------*/
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
		motor[motorB] = power; //power right
	else             //If right
		motor[motorA] = power; //power left
	sleep(timeMS)
	halt();
}

//Positive and negitive values of power and angle vary direction
void pointTurnAngle(int power, int angle, float radiusWheel, float radiusBot) {
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	nMotorEncoderTarget[motorA] = (angle * radiusBot) / (radiusWheel);
	nMotorEncoderTarget[motorB] = (-angle * radiusBot) / (radiusWheel);

	motor[motorA] = power;
	motor[motorB] = -power;

	while (nMotorRunState[motorA] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }

  halt();
}

//Move forward a set Distance with inputted power and radius in centimeters
void moveForward(int power, float distance, float radius) {
	float angleRad = distance / radius;

	writeDebugStreamLine("%f", angleRad);

	float angleDegrees = angleRad * (180.0/PI);

	writeDebugStreamLine("%f", angleDegrees);

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	nMotorEncoderTarget[motorA] = -angleDegrees;
	nMotorEncoderTarget[motorB] = -angleDegrees;

	motor[motorA] = -power;
	motor[motorB] = -power;

	writeDebugStreamLine("%f", nMotorEncoder[motorA]);

	while (nMotorRunState[motorA] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
		writeDebugStreamLine("%f", nMotorEncoder[motorA]);
  }

  halt();
}
