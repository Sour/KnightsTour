// KT
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>

using namespace std;

const int N = 8;
const int N2 = N*N;
const int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int board[N][N];

bool isValid(int x, int y){
	//Checks to see if the coords exist within the chess board.
	if (board[x][y] == -1 && y >= 0 && y < N && x >= 0 && x < N){
		return true;
	}
	return false;
}

bool solve(int x, int y, int index){
	if(index == N2)
		return true;

	int testX, testY;
	for(int i = 0; i < 8; i++){
		testX = x + xMove[i];
		testY = y + yMove[i];
		if(isValid(testX, testY) == true){
			board[testX][testY] = index;
		}
		if(solve(testX, testY, index + 1) == true)
			return true;
		else
			board[testX][testY] = -1;
		return false;
	}
}

void printComplete(){
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			printf(" %2d ", board[x][y]); //%2d is two digit number
		}
		printf("\n"); //\n is a new line.
	}
}

void initBoard(){

	//initilizes '-1' to every spot in our array.
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			board[x][y] = -1;
		}
	}
	
	//sets our start position.
	board[0][0] = 0;
}

bool initSolve(){
	if(solve(0,0,1)){
		return false;
	} 
	printComplete();
	return true;
}



int main(){

	initBoard();
	initSolve();
	getchar();
	return 0;
}

