#include<iostream>
#include <fstream>
#include<string>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "gift.h"
#include <cmath>

#define T 5

using namespace std;

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
	ofstream newCouples("couples.txt", ios::out);

	int noBoys = 9,noGirls = 6;
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
	for(i = 0; i < 14; i++) {
		giftPtr >> val >> pr >> ty;
		gift[i].init(val,pr,ty);
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

	int counter;
	for( counter = 0; counter < T; counter++) {
		/*!< Allocate Gifts */
		int currbud;
		j = 0;
		for(i = 0; i < noGirls; i++) {
			currbud = couple[i].getCurrBudget() ;
			while(currbud > gift[j].getPrice() && j < 14) {
				pr = gift[j].getPrice();
				giftout << couple[i].getBoyname() << "  " << couple[i].getGirlname() << "  " <<  pr << endl;
				couple[i].changeCurrBudget(pr);
				j++;
				currbud = couple[i].getCurrBudget() ;
			}
		}

			/*
		* Calculate Happiness of Girls
		*/
		int bh,gh,cost;
		for( i = 0; i< noGirls; i++) {
			type = girl[i].getType();
			cost = couple[i].getCost();
			if(type == "Choosy") {
				gh = log10(cost / girl[i].getMaint());
			} else if(type == "Normal") {
				gh = cost / girl[i].getMaint();
			} else if(type == "Desperate") {
				gh = exp(cost / girl[i].getMaint());
			}
			couple[i].setGirlHappiness(gh);
		}

		/*!< Calculate Happiness of Boys and set happiness of couple */ 
		for(i = 0; i < noGirls; i++) {
			type = couple[i].getBoyType();
			cost = couple[i].getCost();
			if(type == "Miser") {
				bh = couple[i].getBudget() - cost;
			} else if(type == "Generous") {
				bh = couple[i].getGirlHappiness();
			} else {
				bh = girl[i].getIntelligence();
			}
			couple[i].setBoyHappiness(bh);
			couple[i].setHappiness();
		}

		int h1,h2,p;
		k = 3;
		/*!< Sort couples according to their happiness */
		for(i = 0; i < noGirls; i++) {
			h1 = couple[i].getHappiness();
			for(j = i+1; j < noGirls; j++) {
				h2 = couple[j].getHappiness();
				if(h1 > h2) {
					swapCouple(couple[i], couple[j]);
				}
			}
		}

		for( i = 0; i < noGirls ;i++) {
			girl[i].changeStatus();
			boy[i].changeStatus();
		//	cout << couple[i].getHappiness() << endl;
			if(couple[i].getHappiness() > T*10) {
				p = i;
				break;
			}	
		}

		cout << p <<endl; 

		/*!< Make Couples */
		int j = 0,k = 0;
		for( i = 0; i < p; i++) {
			maint = girl[i].getMaint();
			girlName = girl[i].getName();
			for( j = k; j < noBoys; j++) {
				budget = boy[j].getBudget();
				boyName = boy[j].getName();
				cout << maint << "   " << budget << endl;
				if(maint < budget   ) {
						cout << girlName << "        " << boyName << endl;
						newCouples << girlName << "        " << boyName << endl;
						couple[i].init(boyName,boy[j].getType(), girlName,boy[j].getBudget(),girl[i].getMaint(),boy[j].getAttr(),girl[i].getAttr(),boy[j].getIntelli(),girl[i].getIntelli());
						girl[i].changeStatus();
						boy[j].changeStatus();
						k++;
						break;
				}
			}
		}

		newCouples << endl;


	}

	

	

}
