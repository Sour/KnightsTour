// Warnsdorff's Rule.cpp
// - I mean yolo right?

#include "stdafx.h"

const int xMove[8] = { 1,  1, 2,  2, -1, -1, -2, -2 };
const int yMove[8] = { 2, -2, 1, -1,  2, -2,  1, -1 };


const int N = 8;
int board[N][N][2];

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

		if(isValid(tempX, tempY) == true && board[tempX][tempY][1] != 9){
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

	board[0][0][0] = 0;
}

void initNewWarns(){
		for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			findValidCount(x, y);
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
	solveBoard(x+xMove[lowIndex], y+yMove[lowIndex], index+1);
	return;
}


int main(){

	initBoard();
	printBoard(0);
	printBoard(1);
	solveBoard(0, 0, 1);
	
	getchar();
	return 0;
}

