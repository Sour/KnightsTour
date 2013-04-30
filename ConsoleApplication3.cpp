// KT
//

#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

const int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
const int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
const int N = 8;
int startX, startY;
int board[N][N];

void getSize(){

	string temp = "";

	cout << "Enter X: ";
	getline(cin, temp);
	startX = std::stoi(temp);

	cout << "Enter Y: ";
	getline(cin, temp);
	startY = std::stoi(temp);

}

void printBoard(){
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			printf(" %2d ", board[x][y]);
		}
		printf("\n");
	}
}

bool isValid(int x, int y){
	if ( x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1)
		return true;
	return false;
}

int solveBoard(int x, int y, int index){
	int tempX, tempY;
	if(index == N*N){
		return true;
	}

	for(int i = 0; i < 8; i++){
		tempX = x + xMove[i];
		tempY = y + yMove[i];

		if(isValid(tempX, tempY) == true){
			board[tempX][tempY] = index;

			if(solveBoard(tempX, tempY, index+1) == true){
				return true;
			} else {
				board[tempX][tempY] = -1;
			}
		}
	}
	return false;
}

bool initBoard(){
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			board[x][y] = -1;
		}
	}
	board[startX][startY] = 0;

	if(solveBoard(startX, startY, 1) == false){
		printf("failed");
		return false;
	} else {printBoard();}
	return true;
}





int main(){
	
	getSize();
	initBoard();
	getchar();
	return 0;
}

