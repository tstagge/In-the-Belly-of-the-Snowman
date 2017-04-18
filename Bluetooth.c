//ENGR 142: Project 3
//Team 57
//  Jillian Hestle, Emily Schott, Nicholas Vilbrandt, Tyler Stagge

//BLUETOOTH [Bluetooth.c]
//
//This file contains all of the functions nesscesary to connect
//via bluetooth to the NXT Brick.

/*----------------------------FUNCTION  PROTOTYPES----------------------------*/
void testMessage();

/*----------------------------FUNCTION DEFINITIONS----------------------------*/
void testMessage() {
	sendMessage(900);
}

void sendAMessage(int height) {
	sendMessage(height);

	ClearMessage();

	writeDebugStreamLine("Message Sent");

	sleep(1000);

	while (bQueuedMsgAvailable() == false) {
		sleep(250);
	}

	int error = messageParm[0];
	int x = messageParm[1];
	int y = messageParm[2];

	if (error == 1) {
		writeDebugStreamLine("Error %d: No Error", error);
	} else if (error == 2) {
		writeDebugStreamLine("Error %d: Manual Override Engaged", error);
	} else if (error == 4) {
		writeDebugStreamLine("Error %d: Out of Bounds Detected", error);
	} else if (error == 8) {
		writeDebugStreamLine("Error %d: No ALV Marker Seen", error);
	} else if (error == 16) {
		writeDebugStreamLine("Error %d: LSTS System Error", error);
	} else if (error == 32) {
		writeDebugStreamLine("Error %d: Busy - Request Again Later", error);
	}

	writeDebugStreamLine("Coordinates: %d, %d", x, y);
}
