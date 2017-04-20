void executeOperation(byte op, byte pow, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + 90) != 0)
			{
				pointTurn(pow, startTurnToNorth + 90);
			}
			moveForward(61);
 			pointTurn(pow, -90);
			moveForward(110);
 			dropAC();
			break;
		case 2:
			moveForward(37);
 			pointTurn(pow, -90);
			moveForward(98);
 			pointTurn(pow, 90);
			moveForward(72);
 			pointTurn(pow, -90);
			moveForward(50);
 			dropAC();
			break;
		case 3:
			moveForward(56);
 			pointTurn(pow, -90);
			moveForward(208);
 			pointTurn(pow, 90);
			moveForward(29);
 			dropAC();
			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
