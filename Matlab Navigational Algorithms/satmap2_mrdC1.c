void executeOperation(byte op, byte power, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + 0) != 0)
			{
				pointTurn(power, startTurnToNorth + 0);
			}
			moveForward(power, 42);
 			pointTurn(power, -90);
			moveForward(power, 2);
 			dropAC();
			break;
		case 2:
			moveForward(power, 91);
 			pointTurn(power, 90);
			moveForward(power, 158);
 			dropAC();
			break;
		case 3:
			pointTurn(power, -90);
			moveForward(power, 128);
 			pointTurn(power, -90);
			moveForward(power, 93);
 			dropAC();
			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
