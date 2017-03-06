//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BASIC MATHEMATICAL UTILITY FUNCTIONS [Utility.c]

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
//Conversions
float deg2Rad(float deg);

//Basic Calculations
float getArcLength(float angleDeg, float wheelRadiusCM);

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
float deg2Rad(float deg)
{
	return deg * ((2 * pi) / 180);
}

float getArcLength(float angleDeg, float wheelRadiusCM)
{
	return deg2rad(angleDeg) * wheelRadiusCM;
}
