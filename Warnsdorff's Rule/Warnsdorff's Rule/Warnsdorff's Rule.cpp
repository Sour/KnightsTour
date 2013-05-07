// Warnsdorff's Rule.cpp
// - I mean yolo, right?

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

const int xMove[8] = { 1,  1, 2,  2, -1, -1, -2, -2 };
const int yMove[8] = { 2, -2, 1, -1,  2, -2,  1, -1 };
const int N = 8;
int board[N][N][2];
int startX, startY;


void getSize(){

	string temp = "";

	cout << "Enter X: ";
	getline(cin, temp);
	startX = std::stoi(temp) - 1;

	cout << "Enter Y: ";
	getline(cin, temp);
	startY = std::stoi(temp) - 1;

}

bool isValid(int x, int y){
	if( x >= 0 && x < N && y >= 0 && y < N && board[x][y][0] == -1)
		return true;
	return false;
}

void findValidCount(int x, int y){
	int count = 0;
	for(int i = 0; i < 8; i++){

		int tempX = x + xMove[i];
		int tempY = y + yMove[i];

		if(isValid(tempX, tempY) == true){
			count++;
		}
	}
	board[x][y][1] = count;
}

void initBoard(){
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			board[x][y][0] = -1;

	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			findValidCount(x, y);

}

void initNewWarns(){

	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			int count = 0;
			for(int i = 0; i < 8; i++){

				int tempX = x + xMove[i];
				int tempY = y + yMove[i];

				if(isValid(tempX, tempY) == true)
					count++;
			}
			board[x][y][1] = count;
		}
	}
		
}

void printBoard(int i){
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			printf(" %2d ", board[x][y][i]);
		}
		printf("\n");
	}
	printf("\n");
}

void solveBoard(int x, int y, int index){
	
	int tempX, tempY;
	int low = 9;
	int lowIndex = 0;

	if(index == 1)
		board[x][y][0] = 0;

	if(index == N*N)
		return;

	initNewWarns();

	for(int i = 0; i < 8; i++){

		tempX = x + xMove[i];
		tempY = y + yMove[i];

		if(isValid(tempX, tempY) == true){

			if(board[tempX][tempY][0] != -1){
					board[tempX][tempY][1] = 9;
			}

			if(board[tempX][tempY][1] < low && board[tempX][tempY][1] != 9){
				lowIndex = i;
				low = board[tempX][tempY][1];
				board[tempX][tempY][1] = 9;
			}
	
		}
	}

	board[x+xMove[lowIndex]][y+yMove[lowIndex]][0] = index;
	printBoard(0);
	getchar();
	solveBoard(x+xMove[lowIndex], y+yMove[lowIndex], index+1);
	return;
}


int main(){

	initBoard();
	getSize();
	solveBoard(startX, startY, 1);
	printBoard(0);
	getchar();
	return 0;
}

