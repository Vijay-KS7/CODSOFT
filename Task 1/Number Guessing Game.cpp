#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<windows.h>
#include<conio.h>
#include<chrono>
#include<thread>

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

void GameBanner() {

	cout << endl;
	txtcolor("green");

	cout << "\t\t\t========================================================================" << endl;
	cout << "\t\t\t|                         Number Guessing Game                         |" << endl;
	cout << "\t\t\t========================================================================" << endl;

	cout << endl;
	txtcolor("cyan");
}

void Welcmsg() {

	cout << "\t\t\t\t\t\t  😎 *--WELCOME--* 😎" << endl << endl;

}

void clearScreen() {
	system("cls");  // For Windows
	//system("clear"); For Linux
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

void instructions() {

	clearScreen();
	GameBanner();
	Welcmsg();

	cout << "\t\t\t   Instructions To Play The Game:" << endl << endl
	     << "\t\t\t    1. A random number is generated between 0 To 100 automatically.\n"
	     << "\t\t\t    2. The player will 🤔 guess the number that is generated.\n"
	     << "\t\t\t    3. The player gets 10 attempts to guess the number.\n"
	     << "\t\t\t    4. The player score will be calculated on behalf of how many attempts\n"
	     << "\t\t\t       left after guess the number correctly.\n"
	     << "\t\t\t    5. The ranks will decide on the behalf of the score of each player.\n"
	     << "\t\t\t    6. Hints will given to the player to guess the number more accurately.\n"
	     << "\t\t\t    7. Maximum 5 players play this game.\n"
	     << "\t\t\t    8. 😁😎 Enjoy The Game 😎😁 " << endl << endl;

	cout << "\t\t\t\t Press Enter to get back ";
	getch();
	clearScreen();
}

int play() {

	srand(time(0));
	int actual_number = rand() % 100 + 1;
	int guess_number;
	int i;

	for(i = 11; i>=1; i--) {

		txtcolor("cyan");
		cout << "\t\t\t\t Guess a number between 0 to 100: ";
		txtcolor("white");
		cin >> guess_number;
		cout << endl;

		if(guess_number == actual_number) {
			txtcolor("cyan");
			cout << "\t\t\t\t You played well";
			if(i == 11) {
				return 10;
			} else if(i == 1) {
				return 1;
			} else {
				return i-1;
			}
		}

		else if(i > 1) {
			txtcolor("yellow");
			if(guess_number > actual_number+10) {
				cout << "\t\t\t\t Too High! and Too Far!" << endl;
			} else if(guess_number < actual_number-10) {
				cout << "\t\t\t\t Too Low! and Too Far!" << endl;
			} else if(guess_number > actual_number) {
				cout << "\t\t\t\t High! but Too Close!" << endl;
			} else if(guess_number < actual_number) {
				cout << "\t\t\t\t Low! but Too Close!" << endl;
			}
			txtcolor("magenta");  
			cout << "\t\t\t\t Try again you have " << i-1 << " attempts left" << endl << endl;
		}
	}
	txtcolor("red");
	cout << "\t\t\t\t Oops! you have 0 attempts so your game is over now" << endl;
	cout << "\t\t\t\t *Better Luck Next Time " << endl;

	return 0;
}

void single_player() {

	clearScreen();
	GameBanner();
	Welcmsg();

	string player;
	cout << "\t\t\t\t Enter your first name: ";
	txtcolor("white");
	cin >> player;
	cout << endl;

	while(true) {

		clearScreen();
		GameBanner();
		Welcmsg();

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

		clearScreen();
		GameBanner();
		Welcmsg();

		int score = play();
		txtcolor("cyan");
		if(score == 0) {
			cout << "\t\t\t\t " << player << " your score is: " << score << endl << endl;
		} else {
			cout << " " << player << " your score is: " << score << endl << endl;
		}
		cout << "\t\t\t\t You want to play again (y/n): ";
		char Y_N;
		txtcolor("white");
		cin >> Y_N;

		if(Y_N == 'y') {
			continue;
		} else {
			break;
		}
	}
	clearScreen();
	GameBanner();
	Welcmsg();
}

void multi_player() {

	clearScreen();
	GameBanner();
	Welcmsg();

	int no_of_players;
	cout << "\t\t\t\t Enter number of players: ";
	txtcolor("white");
	cin >> no_of_players;
	cout << endl;

	if(no_of_players == 1) {
		single_player();
	} else if(no_of_players>5 || no_of_players<1) {
		cout << "\t\t\t\t Please! Enter number of players in between 1 To 5." << endl << endl;
	} else {

		string player[no_of_players];
		int i;
		int score[no_of_players];
		int j = no_of_players - 1;
		int k;
		string rank[5] = {"1st","2nd","3rd","4th","5th"};

		txtcolor("cyan");
		cout << "\t\t\t\t Enter your first name:\n" << endl;
		for(i = 0; i<no_of_players; i++) {
			txtcolor("cyan");
			cout << "\t\t\t\t\tPlayer " << i+1 <<": ";
			txtcolor("white");
			cin >> player[i];
		}

		clearScreen();
		GameBanner();
		Welcmsg();

		txtcolor("cyan");
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

		clearScreen();
		GameBanner();
		Welcmsg();

		for(i = 0; i<no_of_players; i++) {
			txtcolor("cyan");
			cout << "\t\t\t\t Player " << i+1 <<": " << player[i] << endl;
			score[i] = play();
			this_thread::sleep_for(chrono::seconds(1));
			clearScreen();
			GameBanner();
			Welcmsg();
		}

		for(i = 0; i<no_of_players; i++) {

			if(score[i] == 0) {
				swap(score[i],score[j]);
				swap(player[i],player[j]);
				rank[j] = "Loser";
				j--;
			} else {
				for(k = 0; k<no_of_players; k++) {
					if(k == i) {
						continue;
					}
					if(score[i] > score[k]) {
						swap(score[i],score[k]);
						swap(player[i],player[k]);
					}
				}
			}
		}

		for(i = 0; i<no_of_players-1; i++) {
			for(int j = i+1; j<no_of_players; j++) {
				if(score[i] == score[j]) {
					string temprank = rank[j];
					rank[j] = rank[i];
					for(int k = j+1; k<no_of_players; k++) {
						string temp = rank[k];
						rank[k] = temprank;
						temprank = temp;
					}
				}
			}
		}

		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\tCalculating the result.";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";

		clearScreen();
		GameBanner();
		Welcmsg();

		int maxlen = player[0].size();
		for(i = 1; i<no_of_players; i++) {
			if(player[i].size() > maxlen) {
				maxlen = player[i].size();
			}
		}

		cout << endl;
		cout << "\t\t\t\t\t     The result is: " << endl;
		cout << "\t\t\t\t\t     -----------------------------" << endl;
		cout << "\t\t\t\t\t       Rank" << "\t"
		     << "Name";

		for(i = 1; i<=maxlen; i++) {
			cout << " ";
		}
		maxlen += 6;

		cout << " Score" << endl;
		for(i = 0; i<no_of_players; i++) {
			cout << "\t\t\t\t\t       " << rank[i] << "\t"
			     << player[i];
			int namelen = maxlen - (player[i].size());
			while(namelen >= 1) {
				cout << " ";
				namelen--;
			}
			cout << " ";
			cout << score[i] << endl;
		}
		cout << "\t\t\t\t\t     -----------------------------" << endl;

		cout << "\t\t\t\t\t     --------* Game Over *--------" << endl << endl;
		
		cout << "\t\t\t\t\t Enter to get back";
		getch();

	}

}

void players() {

	clearScreen();
	GameBanner();
	Welcmsg();

	while(true) {

		cout << "\t\t\t\t\t\t  1. SinglePlayer" << endl
		     << "\t\t\t\t\t\t  2. MultiPlayer" << endl
		     << "\t\t\t\t\t\t  3. Back" << endl << endl;

		int no_of_players;
		cout << "\t\t\t\t\t\t   Enter: ";
		txtcolor("white");
		cin >> no_of_players;
		cout << endl;

		if(no_of_players == 1) {
			single_player();
		} else if(no_of_players == 2) {
			multi_player();

			clearScreen();
			GameBanner();
			Welcmsg();
		} else {
			clearScreen();
			break;
		}

	}

}

int main() {

	SetConsoleOutputCP(CP_UTF8);

	while(true) {

		GameBanner();
		Welcmsg();

		cout << "\t\t\t\t\t\t    1. Start Game\n"
		     << "\t\t\t\t\t\t    2. Read Instructions\n"
		     << "\t\t\t\t\t\t    3. Exit" << endl << endl;

		int key;
		cout << "\t\t\t\t\t\tEnter: ";
		txtcolor("white");
		cin >> key;
		cout << endl;

		if(key == 3) {

			txtcolor("cyan");
			clearScreen();
			GameBanner();
			Welcmsg();

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