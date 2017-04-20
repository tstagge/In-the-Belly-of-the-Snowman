void executeOperation(byte op, byte pow, short startTurnToNorth, short* expLoc)
{
	switch(op)
	{
		case 1:
			if((startTurnToNorth + 90) != 0)
			{
				pointTurn(pow, startTurnToNorth + 90);			}
R90
			moveForward(61);
 			expLoc = {24, 30};
			pointTurn(pow, -90);			moveForward(110);
 			expLoc = {24, 140};
			dropAC();
			break;
			moveForward(37);
 			expLoc = {24, 177};
			pointTurn(pow, -90);			moveForward(98);
 			expLoc = {122, 177};
			pointTurn(pow, 90);			moveForward(72);
 			expLoc = {122, 249};
			pointTurn(pow, -90);			moveForward(50);
 			expLoc = {172, 249};
			dropAC();
			break;
			moveForward(56);
 			expLoc = {228, 249};
			pointTurn(pow, -90);			moveForward(208);
 			expLoc = {228, 41};
			pointTurn(pow, 90);			moveForward(29);
 			expLoc = {257, 41};
			dropAC();
			break;
		default:
			printf('Error. Not a valid operation: %d', op);
	}
}
