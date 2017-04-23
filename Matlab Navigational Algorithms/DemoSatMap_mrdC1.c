void executeOperation(byte op, byte power, int base, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + 90) != 0)
			{
				pointTurn(power, startTurnToNorth + 90);
			}
			moveForward(power, 10);
 			gyroTurn(power, base, -90);
			moveForward(power, 154);
 			dropAC();
			expLoc[0] = 76; expLoc[1] = 235;
			break;
		case 2:
			gyroTurn(power, base, -90);
			moveForward(power, 195);
 			gyroTurn(power, base, -90);
			moveForward(power, 58);
 			dropAC();
			expLoc[0] = 271; expLoc[1] = 177;
			break;
		case 3:
			gyroTurn(power, base, 90);
			moveForward(power, 48);
 			gyroTurn(power, base, -90);
			moveForward(power, 92);
 			dropAC();
			expLoc[0] = 319; expLoc[1] = 85;
			break;
		case 4:
			gyroTurn(power, base, -90);
			moveForward(power, 233);
 			gyroTurn(power, base, 90);
			moveForward(power, 4);
 			expLoc[0] = 86; expLoc[1] = 81;
			break;
		default:
			writeDebugStream("Error. Not a valid operation: %d", op);
	}
}
