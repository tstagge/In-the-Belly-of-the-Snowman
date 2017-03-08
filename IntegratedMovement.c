//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//SENSOR-INTEGRATED MOVEMENT FUNCTIONS [IntegratedMovement.c]
//
// This file contains all sensor-reading-dependent movement functions (excluding
// encoder-based movement), including gyro-turns, hall-effect sweeps, and so on.

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
bool beaconSweep(int power, int hallBase, int angle);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
//IN: Positive power ==>> Left
bool beaconSweep(int power, int hallBase, int angle)
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
