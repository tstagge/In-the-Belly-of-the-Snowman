//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BASIC ROBOT MOBILITY FUNCTIONS [BasicMovement.c]
//
// This file contains all the functions the robot will use to move or otherwise
// operate its drive system. See [Driver.c] for all pragmas.

//FIXME: Need to figure out how to properly refer to motors by their assigned
// names as opposed to "motorA" and "motorB"

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void halt(); //Stops drive motors only
void fullStop(); //Stops all motors
void drive(byte power, int timeMS);
void driveIndef(byte power);
void pointTurn(byte power, int angle);
void pointTurnTime(byte power, int timeMS); //Positive is LEFT
void pointTurnIndef(byte power);
void pivotTurn(byte power, int timeMS); //Positive is LEFT
void arcTurn(byte power, float turnRadius, int turnAngle);
void moveForward(byte power, float distance);


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

void driveIndef(byte power)
{
	motor[motorA] = power;
	motor[motorB] = power;
}

void drive(byte power, int timeMS)
{
	motor[motorA] = power;
	motor[motorB] = power;
	sleep(timeMS);
	halt();
}

//FOLLOWING COMMENT IS WRONG!!!!!!!!!
//IN: Power (abs taken); angle [deg], Postive ==> Left
void pointTurn(byte power, int angle)
{
	float radiusWheel = WHEEL_RADIUS;
	float radiusBot = TURN_RADIUS;

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	nMotorEncoderTarget[motorA] = (-abs(angle) * radiusBot) / (radiusWheel);
	nMotorEncoderTarget[motorB] = (abs(angle) * radiusBot) / (radiusWheel);

	motor[motorA] = power;
	motor[motorB] = -power;

	while (nMotorRunState[motorA] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }
  halt();
}

//IN: Positive power ==> Left
void pointTurnTime(byte power, int timeMS)
{
	motor[motorA] = -power;
	motor[motorB] = power;
	sleep(timeMS);
	halt();
}

void pointTurnIndef(byte power)
{
	motor[motorA] = power;
	motor[motorB] = -power;
}

void pivotTurn(byte power, int timeMS)
{
	if(power > 0)    //If left
		motor[motorB] = -power; //power right
	else             //If right
		motor[motorA] = -power; //power left
	sleep(timeMS);
	halt();
}

//IN: Average Power, radius of desired arc, angle of turn (int)
// Sign of power indicates forward/backward; sign of angle indicates direction of turn (Positive ==> Left)
void arcTurn(byte power, float turnRadius, int turnAngle)
{
	float pointTurnRadius = TURN_RADIUS;
	float wheelRadius = WHEEL_RADIUS;

	float innerRadius = (turnRadius - pointTurnRadius);
	float outerRadius = (turnRadius + pointTurnRadius);

	float innerArc = getArcLength(turnAngle, innerRadius);
	float outerArc = getArcLength(turnAngle, outerRadius);

	//Assumption: Motor power roughly proportional with tangential velocity
	//omega = power/turnRadius; -- angular velocity
	float innerPower = -(power/turnRadius) * innerRadius;
	float outerPower = -(power/turnRadius) * outerRadius;
	if(power < 0)
	{
		innerPower *= -1;
		outerPower *= -1;
	}
	writeDebugStream("innerArc: %f\nouterArc: %f\ninnerPower: %f\nouterPower: %f\n", innerArc,outerArc,innerPower,outerPower);

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	if(turnAngle > 0.0){   //Left
		//nMotorEncoderTarget[motorA] = (innerArc / getArcLength(360, wheelRadius) ) / 360;
		nMotorEncoderTarget[motorA] = rad2Deg((innerArc / wheelRadius));
		nMotorEncoderTarget[motorB] = rad2Deg((outerArc / wheelRadius));
		motor[motorA] = innerPower;
		motor[motorB] = outerPower;
		writeDebugStream("Turn left %f\n", (innerArc/wheelRadius));
		//sleep(1000);
	}else{               //Right
		nMotorEncoderTarget[motorA] = rad2Deg((outerArc / wheelRadius));
		nMotorEncoderTarget[motorB] = rad2Deg((innerArc / wheelRadius));
		motor[motorA] = outerPower;
		motor[motorB] = innerPower;
		writeDebugStream("Turn right %f\n", (innerArc/wheelRadius));
		//sleep(1000);
	}
	//sleep(5000);
	while (nMotorRunState[motorB] != runStateIdle ) {
	//Idle loop. Program waits until target value is reached.
  }
  halt();
}


//Move forward a set Distance with inputted power
//CM??
void moveForward(byte power, float distance)
{
	float radiusWheel = WHEEL_RADIUS;
	float angleRad = distance / radiusWheel;

	float angleDegrees = angleRad * (180.0/PI);

	writeDebugStreamLine("%f", -angleDegrees);

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	nMotorEncoderTarget[motorA] = -angleDegrees;
	nMotorEncoderTarget[motorB] = -angleDegrees;

	motorRampUp(power);

	//int kill = 0; //Not currently used

	while (nMotorEncoder[motorB] > -(angleDegrees -100) ) {
		//Idle loop. Program waits until target value is reached.
		//if (kill > 100000) {
		//	kill = 0;
		//	break;
		//}
		//kill++;
  }
  motorRampDown(power);
}
