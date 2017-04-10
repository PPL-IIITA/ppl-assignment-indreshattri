#include<iostream>
#include <fstream>
#include<string>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "gift.h"
#include <cmath>

using namespace std;

void swapBoys(Boy &a, Boy &b)
{
	Boy temp = a;
	a = b;
	b = temp;
}

void swapGirls(Girl &a, Girl &b)
{
	Girl temp = a;
	a = b;
	b = temp;
}

void swapCouple(couple &a, couple &b) 
{
	couple temp = a;
	a = b;
	b = temp;
}

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
	ofstream happiness("sortedHappiness.txt", ios::out);
	ofstream compatibility("sortedComaptibility.txt", ios::out);
	ofstream breakup("breakup.txt", ios::out);
	ofstream newCouples("couples.txt", ios::out);

	int noBoys = 9,noGirls = 6,max,ind,j;
	Boy boy[noBoys];
	Girl girl[noGirls];
	couple couple[noGirls];
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

	int val,pr;
	std:: string ty;
	/*!< Read the gifts */
	for(i = 0; i < 4*noGirls; i++) {
		giftPtr >> val >> pr >> ty;
		gift[i].init(val,pr,ty);
	}
	
	/*!< Sort boys according to their attractiveness */
	for( i = 0; i< noBoys; i++) {
		for( j = 0; j < noBoys; j++) {
			if( boy[i].getAttr() > boy[j].getAttr()) {
				swapBoys(boy[i],boy[j]);
			}
		}
	}

	/*!< Sort girls according to their maintenance */
	for( i = 0; i< noGirls; i++) {
		for( j = 0; j < noGirls; j++) {
			if( girl[i].getMaint() > girl[j].getMaint()) {
				swapGirls(girl[i],girl[j]);
			}
		}
	}

	int p;
	for(i = 0; i < noGirls; i++) {
		if( (i % 2) == 0) {
			p = i;
			while( girl[p].getStatus() && p < noGirls) {
				p++;
			}

			if( p == noGirls) break;
			max = 0;
			for(j = 0; j < noBoys; j++) {
				if( !(boy[j].getStatus()) && boy[j].getBudget() > max) {
					max = boy[j].getBudget();
					ind = j;
				}
			}

			couple[i].init(boy[ind].getName(),boy[ind].getType(), girl[p].getName(),boy[ind].getBudget(),girl[p].getMaint(),boy[ind].getAttr(),girl[p].getAttr(),boy[ind].getIntelli(),girl[p].getIntelli());
			girl[p].changeStatus();
			boy[ind].changeStatus();
		} else {
			p = i;
			while( boy[p].getStatus() && p < noBoys) {
				p++;
			}
			max = 0;
			for(j = 0; j < noGirls; j++){
				if( !(girl[j].getStatus()) && girl[j].getAttr() > max) {
					max = girl[j].getAttr();
					ind = j;
				}
			}

			couple[i].init(boy[p].getName(),boy[p].getType(), girl[ind].getName(),boy[p].getBudget(),girl[ind].getMaint(),boy[p].getAttr(),girl[ind].getAttr(),boy[p].getIntelli(),girl[ind].getIntelli());
			girl[ind].changeStatus();
			boy[p].changeStatus();
		}
	}

	for(i = 0; i < noGirls; i++) {
		newCouples << couple[i].getBoyname() << "   " << couple[i].getGirlname() << endl;
	}
}
