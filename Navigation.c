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

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
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

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
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

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
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

		int error = messageParm[0];
		int x = messageParm[1];
		int y = messageParm[2];
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
