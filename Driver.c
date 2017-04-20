//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//PRIMARY DRIVER [Driver.c]
//
// This file contains the main function from which all other functions are
// called, in addition to the robot's complete sweep of pragmas

//FIXME: Still need to figure out why its not letting us refer to our motors
//       and sensors by the names we assign them

/*----------------------------------PRAGMAS-----------------------------------*/
#pragma config(Motor,  motorA,          motorLeft,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorDep,      tmotorNXT, PIDControl, encoder)
#pragma config(Sensor, S1,     gyroSensor,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S2,              touchSensor,   sensorTouch)
#pragma config(Sensor, S3,     hallEffect,     sensorAnalog)
//#pragma config(Sensor, S1,     gyroSensor,           sensorDigitalIn)

//Mathematical Constants
#define PI (4 * atan(1))

//Defined powers and threshholds
#define BASE_MOTOR_POWER 40
<<<<<<< HEAD
#define DEP_MOTOR_POWER_OPEN 50 //Power used to open deposition system
#define DEP_MOTOR_POWER_CLOSE 60 //Power used to close the deposition system
#define HALL_EFFECT_THRESH_1 8 //We're going to need to compare to the actual beacon magnets
//#define DEP_MOTOR_POWER_OPEN 8 //10//50 //Power used to open deposition system
//#define DEP_MOTOR_POWER_CLOSE 35 //60 //Power used to close the deposition system
//#define HALL_EFFECT_THRESH_1 3 //We're going to need to compare to the actual beacon magnets
=======
#define DEP_MOTOR_POWER_OPEN 8//10//50 //Power used to open deposition system
#define DEP_MOTOR_POWER_CLOSE 35//60 //Power used to close the deposition system
#define HALL_EFFECT_THRESH_1 8 //Calibrated to actual beacon magnet
>>>>>>> origin/master
#define HALL_EFFECT_THRESH_2 15
#define HALL_EFFECT_THRESH_3 -5

//Physical characteristics of robot
#define WHEEL_RADIUS 4.1   //cm
#define TURN_RADIUS 7.0    //cm; distance between wheels' contact points
#define BOT_LENGTH 22.0    //cm; distance from center of turning to AC deposition
#define HEIGHT_OF_MARKER 10 //cm; height of the LSTS marker, FIXME
#define MOTOR_GEAR_RATIO 1

//Filenames
#define MRD_CODE_FILENAME "satmap1nav9.txt"

//Struct Definitions

//File Imports
#include "Utility.c"
#include "Sensors.c"
#include "BasicMovement.c"
#include "IntegratedMovement.c"
#include "Deposition.c"
#include "Bluetooth.c"
//#include "SatelliteNavigation.c"
#include "Navigation.c"
#include "PathInterpreter.c"
//#include "Navigation.c" //FIXME: Some serious errors when trying to import this

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//DRIVERS
void driver1();
void driverPath(byte power);
void pocDriver();

//TESTS
void runCOTTest(); //Code for a center-of-turning test
void runPointTurnTest(int angle); //, float radiusW, float radiusT);
void moveForwardTest(float distance);
void hallEffectBoolStream(short base);
void bluetoothTest(int height);
void readGyro(int base);
void ioTest();
void runSpeedTest();
//PROOF-OF-COMPETENCY TASKS
<<<<<<< HEAD
void pocTask1(short power);
void pocTask2(int height);
void pocTask3(short power);
void pocTask4(short power, int hallBase);
void pocTask5(short power);
void pocTask45Combo(short power, int hallBase);
void pocTask6(int height);
=======
>>>>>>> origin/master
void pocTask1(byte power);
void pocTask2();
void pocTask3(byte power);
void pocTask4(byte power, short hallBase);
void pocTask5(byte power);
void pocTask45Combo(byte power, short hallBase);
<<<<<<< HEAD
void pocTask6();
=======
void pocTask6(int height);
>>>>>>> origin/master
//PROOF-OF-COMPETENCY SUB-ROUTINES
void pocTask4Search2(byte power, short hallBase); //Searches the 10cm x 30cm region
void pocTask5Path(byte power); //Runs that weird path with the two turns

/*-----------------------------------MAIN-------------------------------------*/
task main()
{
<<<<<<< HEAD
	clearDebugStream();
	writeDebugStreamLine("Battery level (mV): %d", nImmediateBatteryLevel);
	//driver2();
	//clearDebugStream();
	//writeDebugStream("*: %d\nspace: %d\n-: %d\nnewline: %d\n",'*',' ','-','\n');

	//runSpeedTest();

	driver1();

	//dropAC();
	//openGate(DEP_MOTOR_POWER_OPEN);

//	openGate2(DEP_MOTOR_POWER_OPEN);
//	sleep(300);
//	closeGate2(DEP_MOTOR_POWER_CLOSE);
}


void driver1()
=======
	//-----CALIBRATIONS/CONSTANTS-----/
	halt();
	sleep(50);
	int HALL_BASE = calibrateHallEffect();
	int GYRO_BASE = calibrateGyro();
	sleep(50);
	byte BASE_POW = BASE_MOTOR_POWER;

	driverPath(BASE_POW);
	//writeDebugStream("0: %d\n",'0');
	//dropAC();
}

/*void driver1()
>>>>>>> origin/master
{
	//-----CALIBRATIONS/CONSTANTS-----/
	//halt();
	sleep(50);
	int HALL_BASE = calibrateHallEffect();
	int GYRO_BASE = calibrateGyro();
	sleep(50);
	//GYRO g;
	short BASE_POW = BASE_MOTOR_POWER;
	displayCenteredTextLine(3, "%d", HALL_BASE);
	writeDebugStreamLine("HALL_BASE: %d", HALL_BASE);

	//------TEST  CODE------/
<<<<<<< HEAD
	//bluetoothTest(HEIGHT_OF_MARKER);
=======

	//float distance = 100; //cm

	//moveForwardTest(distance);

	//runPointTurnTest(90);

	gyroTurn(50, GYRO_BASE, 90)

	//bluetoothTest(HEIGHT_OF_MARKER);

	//openGate(60);
>>>>>>> origin/master
	//closeGate(60);
	//dropAC();
	//readGyro(GYRO_BASE);
	//gyroTurn(BASE_POW, GYRO_BASE, 90);
	//clearTimer(T1);
	//int i = 0;
	//for(i = 0; i<200; i++)
	//{
	//	writeDebugStream("%f\n", time1[T1]);
	//	sleep(5);
	//}


	//pocTask5Path(BASE_POW);
	//bool fuckThis = beaconSweep(-BASE_POW, HALL_BASE, 90);
	//writeDebugStream("%d", fuckThis);
	//hallEffectTest(HALL_BASE);
	//pocTask4Search2(BASE_POW, HALL_BASE);


	//pocTask1(60);
	//pocTask2(HEIGHT_OF_MARKER);
	//pocTask3(BASE_POW);
	//pocTask4(BASE_POW, HALL_BASE);
	//pocTask5(BASE_POW);
	//pocTask45Combo(BASE_POW, HALL_BASE);
	//pocTask6(HEIGHT_OF_MARKER);
}//*/

void driverPath(byte power)
{
	clearDebugStream();
	clearDebugStream();
	writeDebugStream("--NEW TEST------------------------------------------\n");

	//byte test[200];
	//readMRDstream(MRD_CODE_FILENAME, test);
	short mrdCommands[35];
	short mrdParameters[35];
	byte numCommands = readMRDstream2(MRD_CODE_FILENAME, mrdCommands, mrdParameters);
	executeAllCommands(numCommands, power, mrdCommands, mrdParameters);
<<<<<<< HEAD
=======
	byte test[200];
	readMRDstream(MRD_CODE_FILENAME, test);
	writeDebugStream("RAW---");
	short i = 0;
	for(i = 0; i < 174; i++)
	{
		writeDebugStream("%c\n", test[i]);
	}
<<<<<<< HEAD
=======
>>>>>>> origin/master
>>>>>>> origin/master
>>>>>>> origin/master
=======
>>>>>>> origin/master
}

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
void runCOTTest()
{
	int numTurns = 4;
	int turnPower = 50;

	int i = 0;
	for(i = 0; i < numTurns; i++)
	{
		pointTurnTime(turnPower,1600);
		sleep(300);
		pointTurnTime(-turnPower,1600);
		sleep(300);
	}
}


//Tests the speed of the robot at 100 power level
void runSpeedTest() {
	byte power = 100;
	float startEncoderA = nMotorEncoder[motorA];
	float startEncoderB = nMotorEncoder[motorB];

	drive(power, 1000);

	float endEncoderA = nMotorEncoder[motorA];
	float endEncoderB = nMotorEncoder[motorB];

	float diffA = abs(endEncoderA - startEncoderA);
	float diffB = abs(endEncoderB - startEncoderB);

	float turnsA = diffA / 360;
	float turnsB = diffB / 360;

	float distTravelA = turnsA * (2 * WHEEL_RADIUS * PI);
	float distTravelB = turnsB * (2 * WHEEL_RADIUS * PI);

	writeDebugStreamLine("At %d % power, wheel A traveled %f cm.", power, distTravelA);
	writeDebugStreamLine("At %d % power, wheel B traveled %f cm.", power, distTravelB);
}

void runPointTurnTest(int angle)
{
<<<<<<< HEAD
	short power = 40;
	//byte power = 60;
=======
	byte power = 60;
>>>>>>> origin/master
	pointTurn(power, angle);
}

void moveForwardTest(float distance)
{
<<<<<<< HEAD
	short power = 70;
	//byte power = 100;
=======
	byte power = 100;
>>>>>>> origin/master
	moveForward(power, distance);
}

void hallEffectBoolStream(int base)
{
	int i = 0;
	for(i = 0; i < 2000; i++)
	{
		writeDebugStream("%d\t%d\n", nearBeacon(base), atBeacon(base));
		sleep(15);
	}
}

void bluetoothTest(int height) {
	sendAMessage(height);
}

void readGyro(int base)
{
	int i = 0;
	for(i = 0; i < 5000; i++)
	{
		writeDebugStream("%f\n", SensorValue(S1));//getGyro(base));
		sleep(15);
	}
}

void ioTest()
{
	clearDebugStream();

	TFileHandle navFile;
	TFileIOResult isFileFailure;
	short nFileSize = 0;
	string iFileName = MRD_CODE_FILENAME;

	OpenRead(navFile, isFileFailure, iFileName, nFileSize);
	writeDebugStream("\nFile test\n");
	writeDebugStream("Correct?: %d\n", isFileFailure);
	writeDebugStream("Lines: %d\n", nFileSize);
	short i = 0;
	byte read = -1;
	for(i = 0; i < nFileSize; i++)
	{
		ReadByte(navFile,isFileFailure,read);
		writeDebugStream("%c\n", read);
	}
		writeDebugStream("Correct?: %d\n", isFileFailure);

	Close(navFile, isFileFailure);
}


/*------------------------------POC BULLSHIT------------------------------*/
void pocDriver()
{
	clearDebugStream();

	//-----CALIBRATIONS/CONSTANTS-----/
	sleep(50);
	int HALL_BASE = calibrateHallEffect();
	int GYRO_BASE = calibrateGyro();
	sleep(50);
	short BASE_POW = BASE_MOTOR_POWER;
	readGyro(GYRO_BASE);

	//pocTask5Path(BASE_POW);
	//pocTask4Search2(BASE_POW, HALL_BASE);

	//pocTask1(BASE_POW);
	//pocTask3(BASE_POW);
	//pocTask4(BASE_POW, HALL_BASE);
	//pocTask5(BASE_POW);
	//pocTask45Combo(BASE_POW, HALL_BASE);
}

void pocTask1(byte power)
{
	pointTurn(40, 30); //Left
	sleep(0.5);
	moveForward(power, 1000); //NICK!: I don't know the actual distance here
}

void pocTask2(int height)
{
	task2(height);
}

void pocTask3(byte power)
{
	moveForward(power, 1000.0); //NICK!: I don't know the actual distance here
}

void pocTask4(byte power, short hallBase)
{
	moveForward(power, 50.0);
	pocTask4Search2(power, hallBase);
	//moveForward(power, 35);
	sleep(0.25);
	//dropAC();
	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15); //Sound does not play, brick only plays three sounds with 4 calls
}

void pocTask5(byte power)
{
	pocTask5Path(power);
	moveForward(power, (30.0 + BOT_LENGTH));
	//moveForward(power, BOT_LENGTH);
	fullStop();
	sleep(25);
	dropAC();
}

void pocTask45Combo(byte power, short hallBase)
{
	pocTask5Path(power);
	moveForward(power, 12.0);
	sleep(0.25);
	pocTask4Search2(power, hallBase);
	moveForward(power, 35);
	sleep(0.25);
	dropAC();
	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15); //Sound does not play, brick only plays three sounds with 4 calls
}

void pocTask4Search2(byte power, short hallBase)
{
	int distTraveled = 0;
	bool n = false;
	//bool at = false;

	while( (!n) && (distTraveled < 51))
	{
		if(beaconSweep(-power, hallBase, 20)) {
			n = true;
			break;
		}
		sleep(250);
		if(beaconSweep(power, hallBase, 40)) {
			n = true;
			break;
		}
		sleep(250);
		pointTurn(power, 18);
		sleep(250);
		moveForward(power,6);
		sleep(250);
		if(nearBeacon(hallBase))
		{
			n = true;
			break;
		}
		distTraveled += 6;
	}
}

void pocTask5Path(byte power)
{
	moveForward(power, 45.0);
	sleep(250);
	pointTurn(20, -90);
	sleep(250);
	moveForward(power, 15.0); //Changed from 20 to 15
	sleep(250);
	arcTurn(20, 15.0, -90);
	sleep(250);
	//moveForward(power, (30.0 + ));
	//moveForward(power, 30.0);
	//sleep(250);BOT_LENGTH
	//dropAC();
}

void pocTask6(int height)
{
	int i = 0;
	while( i == 0 ) {
		sendAMessage(height);
	}
}
