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

void sendMessage(int height) {
	sendMessage(height);
	writeDebugStreamLine("Message Sent");
}
