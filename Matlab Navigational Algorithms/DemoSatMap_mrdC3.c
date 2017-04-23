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
			expLoc[0] = 34; expLoc[1] = 205;
			break;
		case 2:
			gyroTurn(power, base, -90);
			moveForward(power, 195);
 			gyroTurn(power, base, -90);
			moveForward(power, 58);
 			dropAC();
			expLoc[0] = 229; expLoc[1] = 147;
			break;
		case 3:
			gyroTurn(power, base, 90);
			moveForward(power, 48);
 			gyroTurn(power, base, -90);
			moveForward(power, 92);
 			dropAC();
			expLoc[0] = 277; expLoc[1] = 55;
			break;
		case 4:
			gyroTurn(power, base, -90);
			moveForward(power, 233);
 			gyroTurn(power, base, 90);
			moveForward(power, 4);
 			expLoc[0] = 44; expLoc[1] = 51;
			break;
		default:
			writeDebugStream("Error. Not a valid operation: %d", op);
	}
}
