// Warnsdorff's Rule.cpp
// - I mean yolo right?

#include "stdafx.h"

const int xMove[8] = { 1,  1, 2,  2, -1, -1, -2, -2 };
const int yMove[8] = { 2, -2, 1, -1,  2, -2,  1, -1 };

const int N = 8;
int board[N][N];

void initBoard(){
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			board[x][y] = -1;
}

bool isValid(int x, int y){
	if( x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1)
		return true;
	return false;
}

int getSingleCount(int x, int y){

	int tempX, tempY;
	int count = 0;

	for(int i = 0; i < 8; i++){

		int tempX = x + xMove[i];
		int tempY = y + yMove[i];

		if(isValid(tempX, tempY) == true)
			count++;
	}
	return count;
}

int getWarnsLowest(int count[8]){
	int index, s = count[0];
	for(int i = 0; i < 8; i++){
		if(count[i] < s) {
			s = count[i];
			index = i;
		}
	}
	return index;
}

int findValidCount(int x, int y){

	int count[8], tempX, tempY;

	for(int i = 0; i < 8; i++){

		int tempX = x + xMove[i];
		int tempY = y + yMove[i];

		if(isValid(tempX, tempY) == true)
			count[i] = getSingleCount(tempX, tempY);
	}
	return getWarnsLowest(count);
}

bool solveBoard(int x, int y, int index){
	if(index == N*N)
		return true;

	int yieldIndex = findValidCount(x,y);
	int tempX = x + xMove[yieldIndex];
	int tempY = y + yMove[yieldIndex];
	if(isValid(tempX, tempY) == true){
		board[tempX][tempY] = index;

		if(solveBoard(tempX, tempY, index+1) == true){
			return true;
		} else {
			board[tempX][tempY] = -1;
		}
	}
}

int main(){

	initBoard();
	solveBoard(0,0,1);
	getchar();
	return 0;
}

