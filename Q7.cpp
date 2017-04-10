#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "lib7.h"
#include "gift.h"
#include <cmath>

using namespace std;
#define CHOICE 2


void swapC(couple &a, couple &b) 
{
	couple temp = a;
	a = b;
	b = temp;
}

int main()
{
	ifstream boyPtr("boyrec.txt", ios::in);
	ifstream girlPtr("girlrec.txt", ios::in);
	ofstream opPtr("output.txt", ios::out);
	ifstream giftPtr("gifts.txt", ios::in);
	ofstream giftout("giftslog.txt", ios::out);
	ofstream logfile("logfile7.txt", ios::out);

	int noBoys = 9,noGirls = 6;
	Boy boy[noBoys];
	Girl girl[noGirls];
	couple couple[noGirls];
	Library ob;
	Gift gift[4*noGirls];
	int maint, budget,intelli,attr,i;
	string name,girlName,boyName,type;
	
	/*!< Read boys data */
	for( i = 0; i < noBoys; i++) {
		boyPtr >> name >> type >>attr >> intelli >> budget ;
		boy[i].init(name,type,attr,intelli,budget);
	}

	/*!< Read Girls Data */
	for( i = 0; i < noGirls; i++) {
		girlPtr >> name >> type >> attr >> intelli >> maint ;
		girl[i].init(name,type,attr,intelli,budget);
	}

	/*!< Make Couples */
	int j = 0,k = 0,ind = 0;
	for( i = 0; i < noGirls; i++) {
		maint = girl[i].getMaint();
		girlName = girl[i].getName();
		for( j = k; j < noBoys; j++) {
			budget = boy[j].getBudget();
			boyName = boy[j].getName();
			if(maint < budget && !(girl[i].getStatus() ) && !(boy[j].getStatus() ) ) {
					opPtr << girlName << "        " << boyName << endl;
					couple[i].init(boyName,boy[j].getType(), girlName,boy[j].getBudget(),girl[i].getMaint(),boy[j].getAttr(),girl[i].getAttr(),boy[j].getIntelli(),girl[i].getIntelli());
					girl[i].changeStatus();
					boy[j].changeStatus();
					k++;
					break;
			} else {
				j--;
			}
		}
	}

	int val,pr;
	std:: string ty;
	/*!< Read the gifts */
	for(i = 0; i < 14; i++) {
		giftPtr >> val >> pr >> ty;
		gift[i].init(val,pr,ty);
	}
	
	/*!< Copying couple Array*/
	ob.couples = couple;

	/*!< Create Hashtable */
	for(i = 0; i < noGirls; i++) {
		ob.hashCouples[i].init("",boy[j].getType(), "",boy[j].getBudget(),girl[i].getMaint(),boy[j].getAttr(),girl[i].getAttr(),boy[j].getIntelli(),girl[i].getIntelli())
	}
	for(i = 0; i < noGirls; i++) {
		int ind = (couple[i].getBoyname()[0] + 7)%noGirls;
		while( couple[ind].getBoyname() != "") ind = (ind + 1) % noGirls;
		ob.hashCouples[ind] = couple[i];
	}

	/*!< Sort Couples */
	for(i = 0; i < noGirls; i++) {
		for( j = i+1; j< noGirls; j++) {
			if( couple[i].getBoyname()[0] > couple[j].getBoyname()[0]) {
				swapC(couple[i],couple[j]);
			}
		}
	}

	ob.sortedcouples = couple;

	logFile<<"\n-----------List of Boys----------\n\n";
	/*!< Copying list of boys */
	for(i = 0; i< noBoys; i++) {
		ob.boysList[i] = boy[i];
		logFile<<"b"<<ob.boysList[i].getBoyname()<<" ";
	}	

	/*!< Selecting algo for searching */
	int choice = CHOICE;
	switch(choice) {
		case 1: 
			ob.searchArr();
			break;
		case 2:		//for binary search
			ob.searchSortedArr();
			break;
		case 3:		//for using hashtable
			cout<<choice<<endl;
			ob.searchHash();
			break;
	}

}
