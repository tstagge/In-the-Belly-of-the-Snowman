//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//CARGO and DEPOSITION FUNCTIONS [Deposition.c]
//
//This file contains all functions related to the bin drop off system.
//See Driver.c for pragmas and global variables

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void dropAC();
void openGate(int power);
void closeGate(int power);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/

//Drop Antennae Container -- function that will be called by Driver
void dropAC()
{
		int depPower = DEP_MOTOR_POWER; //global variable defined in Driver.c
		openGate(depPower);
		sleep(300);
		closeGate(depPower);
}

void openGate(int power)
{
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorC] = (360);
	motor[motorC] = -power;
	while (nMotorRunState[motorC] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }
  fullStop();

}

void closeGate(int power)
{
	motor[motorC] = power;
	while(SensorValue(S2) == 0) { //(IDLE) while the Touch Sensor is inactive
  }
  fullStop();
}
