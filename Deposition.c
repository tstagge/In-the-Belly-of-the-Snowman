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
	while(SensorValue(touchSensor) == 0)  // while the Touch Sensor is inactive
  {
    //Rotate at power
  }
}
