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
			expLoc[0] = 97; expLoc[1] = 169;
			break;
		case 2:
			pointTurn(power, -90);
			moveForward(power, 127);
 			pointTurn(power, 90);
			moveForward(power, 65);
 			dropAC();
			expLoc[0] = 224; expLoc[1] = 234;
			break;
		case 3:
			pointTurn(power, -90);
			moveForward(power, 108);
 			pointTurn(power, -90);
			moveForward(power, 195);
 			dropAC();
			expLoc[0] = 332; expLoc[1] = 39;
			break;
		case 4:
			moveForward(power, 9);
 			pointTurn(power, -90);
			moveForward(power, 247);
 			expLoc[0] = 85; expLoc[1] = 30;
			break;
		default:
			writeDebugStream("Error. Not a valid operation: %d", op);
	}
}
