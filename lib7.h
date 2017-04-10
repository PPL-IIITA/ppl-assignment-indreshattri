#ifndef lib7_h
#define lib7_h

#include<iostream>
#include<fstream>
#include<sstream>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"

int noBoys = 9,noGirls = 6,S = 9;
int C = 6;

using namespace std;

class Library
{
	public:
	couple * couples ;
	couple * sortedCouples;
	couple hashCouples[6];
	Boy boysList[9];
	ofstream logFile;	

	public:
	void searchArr();
	void searchSortedArr();
	void searchHash();
};


#endif
