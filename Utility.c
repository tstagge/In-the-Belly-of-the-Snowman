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

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
float deg2Rad(float deg)
{
	return deg * (pi / 180);
}

float rad2Deg(float rad)
{
	return rad * (180 / pi);
}

float getArcLength(int angleDeg, float radiusCM)
{
	return deg2rad(angleDeg) * radiusCM;
}
