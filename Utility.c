//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BASIC MATHEMATICAL UTILITY FUNCTIONS [Utility.c]

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//CONVERSIONS
float deg2Rad(float deg);
float rad2Deg(float rad);

//BASIC CALCULATIONS
float getArcLength(float angleDeg, float wheelRadiusCM);
float calcTrap(float b,float h);

//OTHER
void motorRampUp(byte powerTarget); //Wasn't quite the intent of this file, but alright with me
void motorTurnRampUp(byte powerTarget);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
float deg2Rad(float deg)
{
	return deg * (PI / 180);
}

float rad2Deg(float rad)
{
	return rad * (180 / PI);
}

float getArcLength(int angleDeg, float radiusCM)
{
	return deg2Rad(angleDeg) * radiusCM;
}

float calcTrap(float b,float h)
{
	return ( 0.5 * b * h);
}

void motorRampUp(byte powerTarget) {
	short power;
	for(power = -30; power >= -powerTarget; power--) { //Starts the power at 30 and ramps up to inputted power value
    motor[motorA] = power;
    motor[motorB] = power;
    displayCenteredTextLine(3, "%d", power);
    wait1Msec(20); //Waits 20 milliseconds before increasing the power.
  }
}

void motorTurnRampUp(byte powerTarget) {
	short power;
	for(power = -30; power >= -powerTarget; power--) { //Starts the power at 30 and ramps up to inputted power value
    motor[motorA] = power;
    motor[motorB] = -power;
    wait1Msec(10); //Waits 10 milliseconds before increasing the power.
  }
}
