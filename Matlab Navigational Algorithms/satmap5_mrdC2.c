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
 			expLoc = {97, 30};
			pointTurn(power, 90);
			moveForward(power, 139);
 			expLoc = {97, 169};
			dropAC();
			expLoc = {97, 169};
			break;
		case 2:
			pointTurn(power, -90);
			moveForward(power, 127);
 			expLoc = {224, 169};
			pointTurn(power, 90);
			moveForward(power, 65);
 			expLoc = {224, 234};
			dropAC();
			expLoc = {224, 234};
			break;
		case 3:
			pointTurn(power, -90);
			moveForward(power, 108);
 			expLoc = {332, 234};
			pointTurn(power, -90);
			moveForward(power, 195);
 			expLoc = {332, 39};
			dropAC();
			expLoc = {332, 39};
			break;
		case 4:
			moveForward(power, 9);
 			expLoc = {332, 30};
			pointTurn(power, -90);
			moveForward(power, 247);
 			expLoc = {85, 30};
			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
