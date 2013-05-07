// rps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <random>
#include <ctime>

using namespace std;

int games[2];

void addWinLoss(bool par1){
	if(par1)
		games[0] += 1;
	else
		games[1] += 1;
}

int aiChoice(){
	srand(time(0));
	return rand() % 3 + 1;
}

int userChoice(){

	system("CLS");

	string temp;
	cout << "Rock, Paper, Scissors" << endl;
	getline(cin, temp);

	transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	
	if(temp == "ROCK") return 1;
	if(temp == "SCISSORS") return 2;
	if(temp == "PAPER") return 3;
	if(temp != "ROCK" || "PAPER" || "SCISSORS") cout << "You have not entered a correct choice" << endl;
	getchar();
	userChoice();
}

bool tierList(int par1, int par2){

	addWinLoss(false);
	if((par1 == 1 && par2 == 3) || (par2 == 1 && par1 == 1)) return false;
	if((par1 == 2 && par2 == 1) || (par2 == 2 && par1 == 2)) return false;
	if((par1 == 3 && par2 == 2) || (par2 == 3 && par1 == 3)) return false;

	addWinLoss(true);
	return true;

}


void play(){
	if(tierList(userChoice(), aiChoice()))
		cout << "You Won!";
	else
		cout << "You Suck FAGGOT";

	getchar();

	system("CLS");

	string temp;
	cout << "Would you like to play again?" << "you have played: " << games[1] << " games and won: " << games[0] << endl;
	getline(cin, temp);

	transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	if(temp == "YES") play();
}

int main()
{
	play();

	return 0;
}

