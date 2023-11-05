#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<thread>
#include<chrono>

using namespace std;

HANDLE lethandle = GetStdHandle(STD_OUTPUT_HANDLE);

void txtcolor(string color){
	
	if(color == "blue"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE);
	}
	else if(color == "green"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_GREEN);
	}
	else if(color == "red"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_RED);
	}
	else if(color == "bright"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_INTENSITY);
	}
	else if(color == "cyan"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	else if(color == "magenta"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else if(color == "yellow"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if(color == "white"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	
}

int moves[3][3] = {{7,8,9},{4,5,6},{1,2,3}};
char board[3][3];

void GameBanner() {
	cout << endl;
	txtcolor("green");

	cout << "\t\t\t========================================================================" << endl;
	cout << "\t\t\t|                              Tic-Tac-Toe                             |" << endl;
	cout << "\t\t\t========================================================================" << endl;

	cout << endl;
	txtcolor("cyan");
}

void Welcmsg() {

	cout << "\t\t\t\t\t\t  😎 *--WELCOME--* 😎" << endl << endl;

}

void clearScreen() {
	system("cls");
}

void endmsg(){
	
	clearScreen();
	
	txtcolor("green");
	
	cout << endl;
	cout<<"\t\t\t\t*************************************************************"
	    <<endl<<endl;
	cout<<"\t\t\t\t  * * * * * * * * *   Thanks For Coming   * * * * * * * * * "<<endl<<endl;
	cout<<"\t\t\t\t*************************************************************"
	    <<endl;
	    
	txtcolor("white");
	
}

void refresh() {

	clearScreen();
	GameBanner();
	Welcmsg();

}

void instructions() {

	refresh();

	cout << "\t\t\t  Instructions To Play The Game:" << endl << endl
	     << "\t\t\t    1. The game is typically played by two players taking turns.\n"
	     << "\t\t\t       One player is 'X' and the other is 'O'.\n" << endl
	     << "\t\t\t    2. The 3x3 grid starts empty, and the players take turns placing\n"
	     << "\t\t\t       their symbols in empty cells.\n" << endl
	     << "\t\t\t    3. Players take turns selecting a cell by specifying the number(1 to 9)\n"
	     << "\t\t\t       of the cell they want to mark.\n" << endl
	     << "\t\t\t    4. The objective is to get three of your symbols in a row.This can be:\n" << endl
	     << "\t\t\t       (i)   Horizontal   (ii)   Vertical   (iii)   Diagonal\n" << endl
	     << "\t\t\t             O | O | O           O |   |            O |   |   \n"
	     << "\t\t\t            -----------         -----------        -----------\n"
	     << "\t\t\t               |   |             O |   |              | O |   \n"
	     << "\t\t\t            -----------         -----------        -----------\n"
	     << "\t\t\t               |   |             O |   |              |   | O \n" << endl
	     << "\t\t\t    5. The game ends when one player achieves three in a row, or if all\n"
	     << "\t\t\t       the cells are filled, resulting in a draw.\n" << endl
	     << "\t\t\t    6. 😁😎 Enjoy The Game 😎😁 " << endl << endl;

	cout << "\t\t\t\t Press Enter to get back ";
	getch();
	clearScreen();
}

void empty_board() {
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			board[i][j] = ' ';
		}
	}
}

void initial_board() {
	cout << endl;
	cout << "\t\t\t\t\t\t  The initial board : " << endl << endl;
	for(int i = 0; i<3; i++) {
		txtcolor("magenta");
		cout << "\t\t\t\t\t\t       |     |    " << endl;
		cout << "\t\t\t\t\t\t  ";
		for(int j = 0; j<3; j++) {
			txtcolor("yellow");
			cout << "  " << moves[i][j] << "  ";
			txtcolor("magenta");
			if(j != 2)
				cout << "|";
		}
		cout << endl;
		cout << "\t\t\t\t\t\t       |     |    " << endl;
		if(i != 2)
			cout << "\t\t\t\t\t\t  -----------------" << endl;
	}
	cout << endl;
	txtcolor("red");
	cout << "\t\t\t\t\t Note: Remember numbers of the cell " << endl << endl;
	empty_board();

}

int mark_symbol(string name) {

	clearScreen();
	GameBanner();
	Welcmsg();

	txtcolor("cyan");
	cout << "\t\t\t\t    " << name
	     << " what you want:" << endl << endl;
	cout << "\t\t\t\t        1. ";
	txtcolor("yellow");
	cout << "O" << endl;
	txtcolor("cyan");
	cout << "\t\t\t\t        2. ";
	txtcolor("yellow");
	cout << "X" << endl << endl;
	txtcolor("cyan");
	cout << "\t\t\t\t      Enter:";
	int temp;
	txtcolor("white");
	cin >> temp;

	return temp;
}

int toss(string player, int num) {

	txtcolor("yellow");
	cout << "\t\t\t\t\t\t    It's Toss Time" << endl << endl;

	txtcolor("cyan");
	cout << "\t\t\t\t\t\t   " << player << " choose one:" << endl << endl;
	cout << "\t\t\t\t\t\t     1. Head\n"
	     << "\t\t\t\t\t\t     2. Tail" << endl << endl;
	int toss;
	cout << "\t\t\t\t\t\t   Enter: ";
	txtcolor("white");
	cin >> toss;
	cout << endl;
	txtcolor("yellow");
	cout << "\t\t\t\t\t\t   Tossed Up!" << endl << endl;
	this_thread::sleep_for(chrono::seconds(1));
	int random = rand()%100;
		
	if(toss == 1) {
		if(random % 2 == 0) {
			cout << "\t\t\t\t\t\t   Head is Coming" << endl;
			if(num == 1)
				return 0;
			else
				return 1;
		} else {
			cout << "\t\t\t\t\t\t   Unlucky! Tail is Coming" << endl;
			if(num == 1)
				return 1;
			else
				return 0;
		}
	} else {
		if(random % 2 != 0) {
			cout << "\t\t\t\t\t\t   Tail is Coming" << endl;
			if(num == 1)
				return 0;
			else
				return 1;
		} else {
			cout << "\t\t\t\t\t\t   Unlucky! Head is Coming" << endl;
			if(num == 1)
				return 1;
			else
				return 0;
		}
	}
}

bool mark_cell(char mark, int move) {

	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			if(move == moves[i][j]) {
				if(board[i][j] == ' ') {
					board[i][j] = mark;
					return true;
				} else {
					txtcolor("red");
					cout << "\t\t\t\t\t   This cell is already filled" << endl << endl;
					return false;
				}
			}
		}
	}
	return true;
}

void mark_board() {

	for(int i = 0; i<3; i++) {
		txtcolor("magenta");
		cout << "\t\t\t\t\t\t       |     |    " << endl;
		cout << "\t\t\t\t\t\t  ";
		for(int j = 0; j<3; j++) {
			txtcolor("yellow");
			cout << "  " << board[i][j] << "  ";
			txtcolor("magenta");
			if(j != 2)
				cout << "|";
		}
		cout << endl;
		cout << "\t\t\t\t\t\t       |     |    " << endl;
		if(i != 2)
			cout << "\t\t\t\t\t\t  -----------------" << endl;
	}

}

bool row_wise(char mark) {

	for(int i = 0; i<3; i++) {
		if((board[i][0] == mark) && (board[i][1] == mark) && (board[i][2] == mark))
			return true;
	}

	return false;
}

bool column_wise(char mark) {

	for(int j = 0; j<3; j++) {
		if((board[0][j] == mark) && (board[1][j] == mark) && (board[2][j] == mark))
			return true;
	}

	return false;
}

bool diagonal_wise(char mark) {

	if((board[0][0] == mark) && (board[1][1] == mark) && (board[2][2] == mark))
		return true;
	else if((board[0][2] == mark) && (board[1][1] == mark) && (board[2][0] == mark))
		return true;

	return false;
}

bool check_result(char mark) {

	if(row_wise(mark))
		return true;
	else if(column_wise(mark))
		return true;
	else if(diagonal_wise(mark))
		return true;

	return false;
}

void _1vs1() {

	refresh();

	string player1;
	string player2;
	txtcolor("cyan");
	cout << "\t\t\t\t   Enter your first name: " << endl << endl;
	cout << "\t\t\t\t     Player 1: ";
	txtcolor("white");
	cin >> player1;
	cout << endl;
	txtcolor("cyan");
	cout << "\t\t\t\t     Player 2: ";
	txtcolor("white");
	cin >> player2;
	cout << endl;

	int mark = mark_symbol(player1);

	txtcolor("cyan");

	char player1_mark;
	char player2_mark;
	if(mark == 1) {
		player1_mark = 'O';
		player2_mark = 'X';
	} else {
		player1_mark = 'X';
		player2_mark = 'O';
	}

	int bit = 0;

	while(true) {

		refresh();

		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t   Starting the game";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";

		refresh();

		bit = !bit;
		int toss_result;

		if(bit)
			toss_result = toss(player1,1);
		else
			toss_result = toss(player2,2);

		if(toss_result == 0) {
			cout << "\t\t\t\t\t\t   " << player1 << " won the toss" << endl;
		} else {
			cout << "\t\t\t\t\t\t   " << player2 << " won the toss" << endl;
		}

		this_thread::sleep_for(chrono::seconds(2));

		refresh();

		initial_board();
		int turn;
		char mark_for_result;

		if(toss_result == 0) {
			txtcolor("yellow");
			cout << "\t\t\t\t\t   " << player1 << "'s turn" << endl;
			txtcolor("cyan");
			cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player1_mark << " : ";
			turn = 0;
			mark_for_result = player1_mark;
		} else {
			txtcolor("yellow");
			cout << "\t\t\t\t\t   " << player2 << "'s turn" << endl;
			txtcolor("cyan");
			cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player2_mark << " : ";
			turn = 1;
			mark_for_result = player2_mark;
		}

		int count = 0;

		while(true) {
			txtcolor("cyan");
			if(toss_result == 2) {
				if(turn == 0) {
					txtcolor("yellow");
					cout << "\t\t\t\t\t   " << player1 << "'s turn" << endl;
					txtcolor("cyan");
					cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player1_mark << " : ";
					mark_for_result = player1_mark;
				} else {
					txtcolor("yellow");
					cout << "\t\t\t\t\t   " << player2 << "'s turn" << endl;
					txtcolor("cyan");
					cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player2_mark << " : ";
					mark_for_result = player2_mark;
				}
			}

			int move;
			txtcolor("white");
			cin >> move;
			txtcolor("cyan");

			if(!mark_cell(mark_for_result, move)) {
				continue;
			}

			count++;
			turn = !turn;
			toss_result = 2;

			refresh();

			cout << endl;
			cout << "\t\t\t\t\t " << player1 << " symbol: '" << player1_mark << "'  "
			     << player2 << " symbol: '" << player2_mark << "'" << endl << endl;

			mark_board();

			cout << endl;

			if(count > 4) {
				if(check_result(mark_for_result)) {
					if(mark_for_result == player1_mark) {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   Congratulations🎉🥳" << player1 << endl;
						cout << "\t\t\t\t\t   You won the game" << endl << endl;
						break;
					} else {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   Congratulations🎉🥳" << player2 << endl;
						cout << "\t\t\t\t\t   You won the game" << endl << endl;
						break;
					}
				} else {
					if(count == 9) {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   👊Tough Fight! " << player1 << " Vs " << player2 << endl;
						cout << "\t\t\t\t\t    It's a draw" << endl << endl;
						break;
					}
				}
			}
		}
		char again;
		txtcolor("cyan");
		cout << "\t\t\t\t\t   Do you both want to play again(y/n): ";
		txtcolor("white");
		cin >> again;
		if(again == 'y') {
			count = 0;
			continue;
		} else {
			break;
		}
	}

}

void _1vsComputer() {

	refresh();

	string player;
	cout << "\t\t\t\t   Enter your first name: ";
	txtcolor("white");
	cin >> player;
	cout << endl;

	int mark = mark_symbol(player);

	txtcolor("cyan");
	char player_mark;
	char computer_mark;
	if(mark == 1) {
		player_mark = 'O';
		computer_mark = 'X';
	} else {
		player_mark = 'X';
		computer_mark = 'O';
	}

	while(true) {
		refresh();

		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t   Starting the game";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";

		refresh();

		int toss_result = toss(player, 1);

		if(toss_result == 0) {
			cout << "\t\t\t\t\t\t   " << player << " won the toss" << endl;
		} else {
			cout << "\t\t\t\t\t\t   Computer won the toss" << endl;
		}

		this_thread::sleep_for(chrono::seconds(2));

		refresh();

		initial_board();
		int turn;
		char mark_for_result;

		if(toss_result == 0) {
			txtcolor("yellow");
			cout << "\t\t\t\t\t   " << player << "'s turn" << endl;
			txtcolor("cyan");
			cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player_mark << " : ";
			turn = 0;
			mark_for_result = player_mark;
		} else {
			txtcolor("yellow");
			cout << "\t\t\t\t\t   Computer's turn" << endl;
			txtcolor("cyan");
			cout << "\t\t\t\t\t   Enter cell number to mark cell with " << computer_mark << " : ";
			turn = 1;
			mark_for_result = computer_mark;
		}

		int count = 0;

		while(true) {
			txtcolor("cyan");
			if(toss_result == 2) {
				if(turn == 0) {
					txtcolor("yellow");
					cout << "\t\t\t\t\t   " << player << "'s turn" << endl;
					txtcolor("cyan");
					cout << "\t\t\t\t\t   Enter cell number to mark cell with " << player_mark << " : ";
					mark_for_result = player_mark;
				} else {
					txtcolor("yellow");
					cout << "\t\t\t\t\t   Computer's turn" << endl;
					txtcolor("cyan");
					cout << "\t\t\t\t\t   Enter cell number to mark cell with " << computer_mark << " : ";
					mark_for_result = computer_mark;
				}
			}

			int move;
			if(turn == 1) {
				while(true) {
					bool flag = true;
					move = rand()%10;
					for(int i = 0; i<3; i++) {
						for(int j = 0; j<3; j++) {
							if(move == moves[i][j]) {
								if(board[i][j] == ' ') {
									flag = false;
									break;
								} else {
									break;
								}
							}
						}
					}
					if(!flag) {
						cout << move;
						this_thread::sleep_for(chrono::seconds(2));
						break;
					}
				}
			} else {
				txtcolor("white");
				cin >> move;
				txtcolor("cyan");
			}

			if(!mark_cell(mark_for_result, move)) {
				continue;
			}

			count++;
			turn = !turn;
			toss_result = 2;

			refresh();

			cout << endl;
			cout << "\t\t\t\t\t " << player << " symbol: '" << player_mark << "'"
			     << "   Computer symbol: '" << computer_mark << "'" << endl << endl;

			mark_board();

			cout << endl;

			if(count > 4) {
				if(check_result(mark_for_result)) {
					if(mark_for_result == player_mark) {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   Congratulations🎉🥳" << player << endl;
						cout << "\t\t\t\t\t   You won the game" << endl << endl;
						break;
					} else {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   Congratulations🎉🥳 Computer" << endl;
						cout << "\t\t\t\t\t   You won the game" << endl << endl;
						break;
					}
				} else {
					if(count == 9) {
						txtcolor("yellow");
						cout << "\t\t\t\t\t   👊Tough Fight! " << player << " Vs Computer" << endl;
						cout << "\t\t\t\t\t    It's a draw" << endl << endl;
						break;
					}
				}
			}
		}
		char again;
		txtcolor("cyan");
		cout << "\t\t\t\t\t   Do you want to play again(y/n): ";
		txtcolor("white");
		cin >> again;
		if(again == 'y') {
			count = 0;
			continue;
		} else {
			break;
		}
	}
}

void players() {

	refresh();

	while(true) {
		
		txtcolor("cyan");
		
		cout << "\t\t\t\t\t\t  1. Player🚹 Vs 🚹Player" << endl
		     << "\t\t\t\t\t\t  2. Player🚹 Vs 💻Computer" << endl
		     << "\t\t\t\t\t\t  3. Back" << endl << endl;

		int option;
		cout << "\t\t\t\t\t\t   Enter: ";
		txtcolor("white");
		cin >> option;
		cout << endl;

		if(option == 1) {
			_1vs1();
			refresh();
		} else if(option == 2) {
			_1vsComputer();
			refresh();
		} else {
			clearScreen();
			break;
		}

	}

}

int main() {

	SetConsoleOutputCP(CP_UTF8);
	srand(time(0));

	while(true) {

		GameBanner();
		Welcmsg();

		cout << "\t\t\t\t\t\t    1. Start Game\n"
		     << "\t\t\t\t\t\t    2. Read Instructions\n"
		     << "\t\t\t\t\t\t    3. Exit" << endl << endl;

		int key;
		cout << "\t\t\t\t\t\t    Enter: ";
		txtcolor("white");
		cin >> key;
		cout << endl;

		if(key == 3) {

			txtcolor("cyan");

			refresh();

			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t       Exiting.";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			break;
		}
		switch(key) {
			case 1:
				clearScreen();
				GameBanner();
				players();
				break;
			case 2:
				instructions();
				break;
			default:
				clearScreen();
				continue;
		}
	}

	endmsg();

	return 0;
}
