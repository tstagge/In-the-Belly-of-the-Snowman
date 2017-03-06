//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BIN DROP OFF FUNCTIONS [BinDropOff.c]
//
//This file contains all functions related to the bin drop off system.


/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void dropAC();
void openGate(int power);
void closeGate(int power);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
void dropAC()
{
		int depPower = DEP_MOTOR_POWER; //global variable defined in Driver.c
		openGate(depPower);
		closeGate(depPower);
}

void openGate(int power)
{
	//Rotate x degrees at power
}

void closeGate(int power)
{
	//Rotate at power until touch sensor is pressed
}
