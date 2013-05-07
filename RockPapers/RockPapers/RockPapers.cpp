// RockPapers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;


int startTime = 0;
int endTime = 0;
//sr (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2

bool isDildos(){
	return true;
}

int getDimRange(int par1, int par2){
	return (par1 - par2)*(par1 - par2);
}

int addDimRange(int par1, int par2, int par3){
	return (par1 + par2 + par3);
}

double getSquareRoot(double par1){
	return sqrt(par1);
}



int main(){
	if(isDildos())
		cout << "LOL" << endl;
	cout << getSquareRoot(addDimRange(getDimRange(1,0), getDimRange(2,0), getDimRange(3,0))) << endl;
	cout << "√" << addDimRange(getDimRange(1,0), getDimRange(2,0), getDimRange(3,0)) << endl;
	getchar();
	return 0;
}

