#include<iostream>
#include <fstream>
#include<string>
#include "boy.h"
#include "girl.h"

using namespace std;

int main()
{
	ifstream boyPtr("boyrec.txt", ios::in);
	ifstream girlPtr("girlrec.txt", ios::in);
	ofstream opPtr("output.txt", ios::out);
	int noBoys = 7,noGirls = 4;
	Boy boy[noBoys];
	Girl girl[noGirls];
	int maint, budget,intelli,attr,i;
	string name,girlName,boyName,type;
	
	/*!< Read boys data */
	for( i = 0; i < noBoys; i++) {
		boyPtr >> name >> type >> attr >> intelli >> budget ;
		boy[i].init(name,type,attr,intelli,budget);
	}

	/*!< Read Girls Data */
	for( i = 0; i < noGirls; i++) {
		girlPtr >> name >> type >> attr >> intelli >> maint ;
		girl[i].init(name,type,attr,intelli,budget);
	}

	int j = 0,k = 0;
	/*!< Make Couples */
	for( i = 0; i < noGirls; i++) {
		maint = girl[i].getMaint();
		girlName = girl[i].getName();
		for( j = k; j < noBoys; j++) {
			budget = boy[j].getBudget();
			boyName = boy[j].getName();
			if(maint < budget && !(girl[i].getStatus() ) && !(boy[j].getStatus() ) ) {
					opPtr << girlName << "        " << boyName << endl;
					girl[i].changeStatus();
					boy[j].changeStatus();
					k++;
					break;
			} else {
				j--;
			}
		}
	}
}
