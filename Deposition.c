//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//CARGO and DEPOSITION FUNCTIONS [Deposition.c]
//
//This file contains all functions related to the bin drop off system.
//See Driver.c for pragmas and global variables

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void dropAC();
void openGate(short power);
void closeGate(short power);
void closeGate2(short power);

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

//-----Linear Gate methods-----
void openGate(short power) {
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorC] = 250;//280;//320; //280 for what we had at PoC2
	motor[motorC] = power;
	while (nMotorRunState[motorC] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }
  fullStop();
}

void openGate2(short power)
{
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorC] = 250;//280;//320; //280 for what we had at PoC2
	clearTimer(T1);
	motor[motorC] = power;
	while ((nMotorRunState[motorC] != runStateIdle)&&(time1[T1] < 3000)) {
		//Idle loop. Program waits until target value is reached.
  }
  fullStop();
}

void closeGate(short power) {
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorC] = -170;//-280; //Needs testing
	motor[motorC] = -power;
	while (nMotorRunState[motorC] != runStateIdle) {
		//Idle loop. Program waits until target value is reached.
  }
  fullStop();
}

void closeGate2(short power)
{
	motor[motorC] = -power;
	while(SensorValue(S2) == 0) { //(IDLE) while the Touch Sensor is inactive
	}
	fullStop();
}

//-----Rotational Gate Methods------

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
