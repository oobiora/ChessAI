

#include <iostream>
#include <cstdlib>

using namespace std;
/*int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;
int led8 = 8;
int led9 = 9;
*/

int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;
int led5 = 0;
int led6 = 0;
int led7 = 0;
int led8 = 0;
int led9 = 0;

int i;
int x = 225;
int o = -255;
int num;
int randNum;

int board[10] = { 0, led1, led2, led3,led4, led5, led6, led7, led8, led9 };
int cornerMoves[5] = { 0, board[1], board[3], board[7], board[9] };
int edgeMoves[5] = { 0, board[2], board[4], board[6], board[8] };
int center = { board[5] };
int checkWin = 0;
int choice;
int RandNum; 
int compRes;
bool b;
bool c;

int cornerAI(int choice) {

	if (board[9] == o) {
		compRes = 7;
		//checkValid(compRes);
	}
	else {
		compRes = (5 * 2) - choice;
		//checkValid(compRes);
	}
	
	return compRes;
}

int firstEdge(int choice) {

	if (choice == 2 || choice == 4 || choice == 6 || choice == 8)
		compRes = 5;
	

	return compRes;
}




bool checkValid(int choice) {
	bool b = false;

	for (int i = 0; i < 10; i++)
		c = b || board[choice] == 0;

	

	return c;
}

bool posWin() {

	int x; 
	int y;

	int y = 3;
	int x = -y;


	if (choice + x || choice + y)

}

int main() {

//Pick Corner
board[1] = x;

cout << "computer moves first\n";
board[1] = x;
cout << "Board 1: " << board[1];

for (int i = 0; checkWin == 0; i++) {

	cout << "Your turn:\t";
	cin >> choice;
	checkValid(choice);

	if (c) {
		cout << choice;
		board[choice] = o;
	}
	else {
		cout << "Bad Choice";
	}

	//CHECK FOR CORNER MOVE
	for (int i = 0; i < 1; i++) {

		if (choice == 1 || choice == 3 || choice == 7 || choice == 9) 
			cornerAI(choice);

		board[compRes] = x;
		cout << "ComputerMoves " << compRes;
		break;
	}

	
	//CHECK FOR BlOCK
	// Block determined when win possible and player interrupts;

	for (int i = 0; i < 1; i++) {

		if (choice == 2 || choice == 4 || choice == 5 || choice == 6)
			firstEdge(choice);

		board[compRes] = x;
		cout << "ComputerMoves " << compRes;
		break;
	}

	//NEW CHOICE INITIATED  
	cin >> choice;
	checkValid(choice);

	board[choice] = o;
	cout << "Your Choice: " << choice;



	






	/*
	if (board[choice] == 0) {
		board[choice] = o;
	}
	else {
		cout << "Bad Suggestion";
	}

	cout << "computer moves\n";

	checValid;

	if (b)
		cornerAI;



	checkWin*/
}

system("PAUSE");


	}
	
	

	


//randNum == 1 || randNum == 3 || randNum == 7 ||