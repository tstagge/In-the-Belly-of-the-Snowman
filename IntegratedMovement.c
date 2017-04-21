//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//SENSOR-INTEGRATED MOVEMENT FUNCTIONS [IntegratedMovement.c]
//
// This file contains all sensor-reading-dependent movement functions (excluding
// encoder-based movement), including gyro-turns, hall-effect sweeps, and so on.

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
bool beaconSweep(byte power, int hallBase, int angle);
void gyroTurn(byte power, int gyroBase, int angle);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
//IN: Positive power ==>> Left
bool beaconSweep(byte power, int hallBase, int angle)
{
	bool nearB = false;
	float radiusWheel = WHEEL_RADIUS;
	float radiusBot = TURN_RADIUS;

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorA] = (-abs(angle) * radiusBot) / (radiusWheel);
	nMotorEncoderTarget[motorB] = (abs(angle) * radiusBot) / (radiusWheel);
	motor[motorA] = -power;
	motor[motorB] = power;
	while ((nMotorRunState[motorA] != runStateIdle)) {
		//Idle loop. Program waits until target value is reached.
		writeDebugStream("Waiting\n");
		writeDebugStream("%d\n", getHallEffect(hallBase));
		if(nearBeacon(hallBase) == true)
			break;
  }
  halt();
  writeDebugStream("Done, you fucking ****\n");
  if(nearBeacon(hallBase))
  {
  	nearB = true;
  	writeDebugStream("Found, motherfucker\n");
	}
 	return nearB;
}

//IN: Power(Positive ==> Left), gyro calibration base value, angle(magnitude)
//void gyroTurn(byte power, int gyroBase, int angle)
//{
//	float radiusWheel = WHEEL_RADIUS;
//	float radiusBot = TURN_RADIUS;
//	float angleTurned = 0;
//	float lastTime = 0;
//	float currentTime = 0;

//	motor[motorA] = -(power/2);
//	motor[motorB] = (power/2);

//	clearTimer(T1);
//	lastTime = time1[T1];
//	while(abs(angleTurned - angle) > 3) //3 is tolerance
//	{
//		currentTime = time1[T1]
//		angleTurned += calcTrap( (currentTime - lastTime), getGyro(gyroBase) );
//		writeDebugStream("dT = %f\tGyro = %f\tAngleTurned = %f\n", (currentTime - lastTime), getGyro(gyroBase), angleTurned);
//		lastTime = currentTime;
//	}
//	halt();
//}

void gyroTurn(byte power, int gyroBase, int angle)
{
	float radiusWheel = WHEEL_RADIUS;
	float radiusBot = TURN_RADIUS;
	float angleTurned = 0;

	pointTurnIndef(power);
	int gyroLast = 0;
	int gyroCurr = 0;

	while((abs(angle) - abs(angleTurned)) > 10) //3 is tolerance
	{
		gyroCurr = getGyro(gyroBase);
		sleep(20);
		angleTurned = angleTurned + (0.02/2 * (gyroLast + getGyro(gyroBase)));
		//angleTurned = angleTurned + ((0.5)*
		writeDebugStreamLine("dT = %f ms\tGyro = %f\tAngleTurned = %f", 5, getGyro(gyroBase), angleTurned);
		gyroLast = gyroCurr;
	}

	halt();
}
