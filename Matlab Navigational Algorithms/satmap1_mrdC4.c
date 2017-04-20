void executeOperation(byte op, byte power, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + 90) != 0)
			{
				pointTurn(power, startTurnToNorth + 90);
			}
			moveForward(power, 61);
 			pointTurn(power, -90);
			moveForward(power, 110);
 			dropAC();
			break;
		case 2:
			moveForward(power, 37);
 			pointTurn(power, -90);
			moveForward(power, 98);
 			pointTurn(power, 90);
			moveForward(power, 72);
 			pointTurn(power, -90);
			moveForward(power, 50);
 			dropAC();
			break;
		case 3:
			moveForward(power, 56);
 			pointTurn(power, -90);
			moveForward(power, 208);
 			pointTurn(power, 90);
			moveForward(power, 29);
 			dropAC();
			break;
		case 4:
			pointTurn(power, -90);
			moveForward(power, 11);
 			pointTurn(power, -90);
			moveForward(power, 172);
 			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
