//ENGR 142: Project 3
//Team 57
//	Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//SATELLITE NAVIGATIONAL ALGORITHM MODULE [SatelliteNavigation.c]

/*----------------------------FUNCTION	PROTOTYPES----------------------------*/

/*----------------------------FUNCTION DEFINITIONS----------------------------*/

void task2(int height) {
	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	int error = messageParm[0];
	int x = messageParm[1];
	int y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		error = messageParm[0];
		x = messageParm[1];
		y = messageParm[2];
	}

	int startX = x;
	int startY = y;

	if( y >= 6 ) {
		pointTurn(100, -90);
		moveForward((80-(y*10), 100);
		pointTurn(100, 90)
	}

	sleep(5000);

	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		error = messageParm[0];
		x = messageParm[1];
		y = messageParm[2];
	}

	moveForward((135 - (x * 10)), 100);

	sleep(5000);

	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		error = messageParm[0];
		x = messageParm[1];
		y = messageParm[2];
	}

	if ((x*10) > 135) {
		pointTurn(180, 100);
		moveForward((x*10) - 135);
		pointTurn(-90, 100);
	}
	if ((x*10) < 135) {
		moveForward(135 - (x*10));
		pointTurn(90, 100);
	}

	sleep(5000);

	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
	}

	moveForward((75 - (y*10)), 100);

	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15); //Sound does not play, brick only plays three sounds with 4 calls

	pointTurn(180, 100);
	moveForward(50,100);
	pointTurn(90,100);

	sleep(2000);

	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		error = messageParm[0];
		x = messageParm[1];
		y = messageParm[2];
	}

	moveForward(((x*10)-(startX*10)), 100);

	sleep(2000);

	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
	}

	if(x < startX) {
		pointTurn(180,100);
		moveForward(((startX*10)-(x*10)),100);
		pointTurn(90,100);
	}

	else if(x > startX) {
		moveForward(((x*10)-(startX*10)),100);
		pointTurn(-90,100);
	}

	else{
		pointTurn(-90,100);
	}

	moveForward(((startY*10)-(y*10)), 100);

	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15);
}

void POC2(int height) {
	//Store our Robots Current Position
	short robot_x, robot_y;
	short x;
	short y;
	short startX;
	short startY;
	short error;

	short map[9][18] = {
		{20,19,18,17,16,15,14,13,1,1,1,1,4,3,4,5,6,7},
		{19,18,17,16,15,14,13,12,1,1,1,1,3,2,3,4,5,6},
		{18,17,16,15,14,13,12,11,1,1,1,1,4,3,4,5,6,7},
		{17,16,15,14,13,12,11,10,9,8,7,6,5,4,5,6,7,8},
		{18,17,16,15,14,13,12,11,10,9,8,7,6,5,6,7,8,9},
		{19,18,17,16,15,14,13,12,11,10,9,8,7,6,7,8,9,10},
		{20,19,18,17,16,15,14,13,12,11,10,9,8,7,8,9,10,11},
		{21,20,19,18,17,16,15,14,13,12,11,10,9,8,9,10,11,12},
		{22,21,20,19,18,17,16,15,14,13,12,11,10,9,10,11,12,13},
	};

	short x_size = 18;
	short y_size = 10;

	//First - Find Goal and Target Locations
	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable()==FALSE) {
		sleep(250);
	}

	error = messageParm[0];
	x = messageParm[1];
	y = messageParm[2];

	while(error > 4) {
		sleep(5000);

		sendMessage(height);

		ClearMessage();

		writeDebugStreamLine("Message Sent");

		sleep(1000);

		while (bQueuedMsgAvailable()==FALSE) {
			sleep(250);
		}

		error = messageParm[0];
		x = messageParm[1];
		y = messageParm[2];
	}

	startX = x;
	startY = y;

	robot_x = x;
	robot_y = y;

	//Found Goal and Target, start deciding our next path
	int current_x = robot_x;
	int current_y = robot_y;
	int current_facing = 0;
	int next_Direction = 0;
	int current_low = 99;

	while(current_low > 2)
	{
		current_low = 99; //Every time, reset to highest number (robot)
		next_Direction = current_facing;
		int Next_X = 0;
		int Next_Y = 0;

		//Check Array Bounds West
		if(current_x > 0)
			if(map[current_x-1][current_y] < current_low && map[current_x-1][current_y] != 1) //Is current space occupied?
		{
			current_low = map[current_x-1][current_y];  //Set next number
			next_Direction = 3; //Set Next Direction as West
			Next_X = current_x-1;
			Next_Y = current_y;
		}

		//Check Array Bounds East
		if(current_x < (x_size -1))
			if(map[current_x+1][current_y] < current_low && map[current_x+1][current_y] != 1) //Is current space occupied?
		{
			current_low = map[current_x+1][current_y];  //Set next number
			next_Direction = 1; //Set Next Direction as East
			Next_X = current_x+1;
			Next_Y = current_y;
		}

		//Check Array Bounds South
		if(current_y > 0)
			if(map[current_x][current_y-1] < current_low && map[current_x][current_y-1] != 1)
		{
			current_low = map[current_x][current_y-1];  //Set next number
			next_Direction = 2; //Set Next Direction as South
			Next_X = current_x;
			Next_Y = current_y-1;
		}

		//Check Array Bounds North
		if(current_y < (y_size - 1))
			if(map[current_x][current_y+1] < current_low && map[current_x][current_y+1] != 1) //Is current space occupied?
		{
			current_low = map[current_x][current_y+1];  //Set next number
			next_Direction = 0; //Set Next Direction as North
			Next_X = current_x;
			Next_Y = current_y+1;
		}

		//Okay - We know the number we're heading for, the direction and the coordinates.
		current_x = Next_X;
		current_y = Next_Y;
		map[current_x][current_y] = '*';

		int current_Direction = next_Direction;
		int move = 0;

		//Loop to determine how far robot can move forward
		while (current_Direction == next_Direction){
			move = move + 1;

			//Check Array Bounds West
			if(current_x > 0)
				if(map[current_x-move][current_y] < current_low && map[current_x-move][current_y] != 1) //Is current space occupied?
			{
				current_low = map[current_x-move][current_y];  //Set next number
				current_Direction = 3;
			}

			//Check Array Bounds East
			if(current_x < (x_size -move))
				if(map[current_x+move][current_y] < current_low && map[current_x+move][current_y] != 1) //Is current space occupied?
			{
				current_low = map[current_x+move][current_y];  //Set next number
				current_Direction = 1;
			}

			//Check Array Bounds South
			if(current_y > 0)
				if(map[current_x][current_y-move] < current_low && map[current_x][current_y-move] != 1)
			{
				current_low = map[current_x][current_y-move];  //Set next number
				current_Direction = 2;
			}

			//Check Array Bounds North
			if(current_y < (y_size - move))
				if(map[current_x][current_y+move] < current_low && map[current_x][current_y+move] != 1) //Is current space occupied?
			{
				current_low = map[current_x][current_y+move];  //Set next number
				current_Direction = 0; //Set Next Direction as North
			}
		}

		//Track the robot's heading
		while(current_facing != next_Direction)
		{
			if (current_facing > next_Direction)
			{
				pointTurn(90,100);
				current_facing--;
			}
			else if(current_facing < next_Direction)
			{
				pointTurn(-90,100);
				current_facing++;
			}
		}
		moveForward((10*move),100);
		wait1Msec(500);
	}

	sleep(300);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(500);
	playTone(800, 15);
	sleep(800);
	playTone(800, 15);
}
