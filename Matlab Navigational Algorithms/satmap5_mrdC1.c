void executeOperation(byte op, byte power, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + -90) != 0)
			{
				pointTurn(power, startTurnToNorth + -90);
			}
			moveForward(power, 12);
 			pointTurn(power, 90);
			moveForward(power, 139);
 			dropAC();
			break;
		case 2:
			pointTurn(power, -90);
			moveForward(power, 127);
 			pointTurn(power, 90);
			moveForward(power, 65);
 			dropAC();
			break;
		case 3:
			pointTurn(power, -90);
			moveForward(power, 108);
 			pointTurn(power, -90);
			moveForward(power, 195);
 			dropAC();
			break;
		case 4:
			moveForward(power, 9);
 			pointTurn(power, -90);
			moveForward(power, 247);
 			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
