#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

char board[4][4] = {	{' ','1','2','3'},
			{'A',' ',' ',' '},
			{'B',' ',' ',' '},
			{'C',' ',' ',' '} };

void printboard() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			cout << board[i][k];
			cout << '|';
		}
		cout << endl;
		for (int k = 0; k < 8; k++) {
			cout << "-";
		}
		cout << endl;
	}
}
char input(int *row, int *col) {
	char R;
	int C;
	cin >> R >> C;
	*col = C;
	switch (R) {
	case 'A': *row = 1; break;
	case 'B': *row = 2; break;
	case 'C': *row = 3; break;
	default: cout << "You enter wrong, select a place (e.g. A 1) : "; input(col, row);
	}
	if (board[*row][*col] != ' ') {
		cout << "You enter wrong, select a place (e.g. A 1) : ";
		input(col, row);
	}
	return R;
}
void setboard(int row, int col,char sym) {
	board[row][col] = sym;
}
bool checkwin() {
	if ((board[1][1] == 'o' && board[1][2] == 'o' && board[1][3] == 'o') ||
		(board[2][1] == 'o' && board[2][2] == 'o' && board[2][3] == 'o') ||
		(board[3][1] == 'o' && board[3][2] == 'o' && board[3][3] == 'o') ||
		(board[1][1] == 'o' && board[2][1] == 'o' && board[3][1] == 'o') ||
		(board[1][2] == 'o' && board[2][2] == 'o' && board[3][2] == 'o') ||
		(board[1][3] == 'o' && board[2][3] == 'o' && board[3][3] == 'o') ||
		(board[1][1] == 'o' && board[2][2] == 'o' && board[3][3] == 'o') ||
		(board[3][1] == 'o' && board[2][2] == 'o' && board[1][3] == 'o')) {
		cout << "game end, player 1 win";
		return false;
	} else if 
		((board[1][1] == 'x' && board[1][2] == 'x' && board[1][3] == 'x') ||
		(board[2][1] == 'x' && board[2][2] == 'x' && board[2][3] == 'x') ||
		(board[3][1] == 'x' && board[3][2] == 'x' && board[3][3] == 'x') ||
		(board[1][1] == 'x' && board[2][1] == 'x' && board[3][1] == 'x') ||
		(board[1][2] == 'x' && board[2][2] == 'x' && board[3][2] == 'x') ||
		(board[1][3] == 'x' && board[2][3] == 'x' && board[3][3] == 'x') ||
		(board[1][1] == 'x' && board[2][2] == 'x' && board[3][3] == 'x') ||
		(board[3][1] == 'x' && board[2][2] == 'x' && board[1][3] == 'x')) {
		cout << "game end, player 2 win";
		return false;
	}
	else {
		return true;
	}
}
bool game(){
	cout << "Player 1 turn, select a place (e.g. A1) : ";
	int row = 0, col = 0;
	input(&row, &col);
	setboard(row, col, 'o');
	cout << endl;
	system("cls");
	printboard();
	if (!checkwin()) {
		return false;
	}
	cout << "player 2 turn, select a place (e.g. A1) : ";
	input(&row, &col);
	setboard(row, col, 'x');
	system("cls");
	printboard();
	if (!checkwin()) {
		return false;
	}
	game();
	return true;
}
int main() {

	cout << "Player 1 are \"o\"\n";
	cout << "Player 2 are \"x\"\n";
	printboard();
	game();
	return 0;
}
