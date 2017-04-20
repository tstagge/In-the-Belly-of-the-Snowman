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
		int depPowerOpen = DEP_MOTOR_POWER_OPEN; //global variable defined in Driver.c
		int depPowerClose = DEP_MOTOR_POWER_CLOSE;
		openGate(depPowerOpen);
		sleep(300);
		//moveForward(5, 50);
		closeGate(depPowerClose);
}

//Linear Gate methods
void openGate(int power) {
	nMotorEncoder[motorC] = 0;
<<<<<<< HEAD
	nMotorEncoderTarget[motorC] = 300; //Needs testing
=======
	nMotorEncoderTarget[motorC] = 280;//320; //Needs testing
>>>>>>> origin/master
	motor[motorC] = power;
	int maxRuns = 0;
	while (nMotorRunState[motorC] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
		if (maxRuns > 10000000) {
			break;
		}
		else {
			maxRuns++;
		}
  }
  fullStop();
}

void closeGate(int power) {
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorC] = -220; //Needs testing
	motor[motorC] = -power;
	while (nMotorRunState[motorC] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }
  fullStop();
}

//Rotational Gate Methods

//void openGate(int power)
//{
//	nMotorEncoder[motorC] = 0;
//	nMotorEncoderTarget[motorC] = (360);
//	motor[motorC] = -power;
//	while (nMotorRunState[motorC] != runStateIdle) {
//		//Idle loop. Program waits until target value is reached.
//  }
//  fullStop();

//}

//void closeGate(int power)
//{
//	motor[motorC] = power;
//	while(SensorValue(S2) == 0) { //(IDLE) while the Touch Sensor is inactive
//  }
//  fullStop();
//}
