//Begun 9/21/2023 by Ethan Larson, finished 9/27/2023
#include <iostream>
/*
TO DO LIST:
COMPLETED!
 */

using namespace std;


char board[3][3];

char player = 'X';
bool isPlaying = true;
bool isRunning = true;

char input[5];
char input2;

bool checkTie(char board[3][3]);
bool checkWin(char board[3][3], char player);
void printboard();
int xwins = 0;
int owins = 0;

int main() {

  while (isRunning) {
    
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++) {
	board[i][j] = ' ';
      }
    }
    
    while (isPlaying) {
      
      printboard();
      
      cout << "It is Player " << player << " turn." << endl;
      cin.get(input, 5);
      cin.get();
      
      /*if (input == "end") { <-- used for debug
	cout << "ended" <<endl;
	return 0;
	}
	else if (input == "xwins") {
	cout << "x wins";
	isPlaying = false;
	}
	else if (input == "owins") {
	cout << "o wins";
	isPlaying = false;
	}
      */
      
      while (board[input[0]-97][input[1]-49] == 'X' || board[input[0]-97][input[1]-49] == 'O') {
	cout << "Invalid input." << endl;
	printboard();
	cout << "It is Player " << player << " turn." << endl;
	cin >> input;
      }
      
      board[input[0]-97][input[1]-49] = player;
      
      if (checkWin(board, player) == true) {
	cout << "Player " << player << " wins!" << endl;
	if (player == 'X') {
	  xwins++;
	}
	if (player == 'O') {
	  owins++;
	}
	isPlaying = false;
      }
      
      if (checkTie(board)) {
	cout << "No more moves" << endl;
	isPlaying = false;
      }
      if (player == 'X') {
	player = 'O';
      }
      else {
	player = 'X';
      }
      
    }
    
    cout << "X wins: " << xwins << endl;
    cout << "O wins: " << owins << endl;
    input2 = '0';
    while (input2 != 'y' && input2 != 'n') {
      cout << "Would you like to play again? (y/n)" << endl;
      cin >> input2;
    }
    if (input2 == 'n') {
      cout << "Thanks for playing!" << endl;
      return 0;
    }
    if (input2 == 'y') {
      player = 'X';
      isPlaying = true;
    }
    cin.ignore(5, '\n');
    
  }
  
}

void printboard() {
  cout << "  1 2 3" << '\n';
  cout << "a " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
  cout << "b " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
  cout << "c " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}

bool checkTie(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
	//cout << "not a tie";  <- used for debug
	return false;
      } 
    }
  }
  //cout << "is a tie"; <- used for debug
  return true;
}

bool checkWin(char board[3][3], char player) {

  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) { //horizontal and vertical wins
      return true;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { //diagonal wins
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  
  //cout << "Player " << player << " did not win." << endl; <- used for debug
  return false;
}
