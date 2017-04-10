#include "lib8.h"

void GiftAllocation::swap(Gift& a, Gift& b)
{
    Gift temp = a;
    a = b;
    b = temp;
}

void GiftAllocation::sortingGifts()
{
	//sorting gifts	
	for(int i = 0  ; i< Gf-1; i++) {
		for(int j = i+1; j < Gf; j++) {
			if(gifts[j].getprice() < gifts[i].getprice()) {
				swap(gifts[j],gifts[i]);
			}
		}
	}
}

void GiftAllocation::takeInput()
{
	int c = 0;
	int x = 0;
	string line;
	ifstream giftInp("gift.dat");
	while(getline(giftInp,line)) {
		if(c++ == 0) continue;
		istringstream iss(line);
		int id,p,v;
		char ty;
		if((iss>>id>>p>>ty>>v)){
			gifts[x++].setDetail(id,p,ty,0);
		} else {
			break;
		}
	}

	ifstream giftPtr("gifts.txt", ios::in);

	int pr,val;
	std::string ty;
	for(i = 0; i < 2*noGirls; i++) {
		giftPtr >> val >> pr >> ty;
		gift[i].init(val,pr,ty);
	}
	
}

void GiftAllocation::printingGifts(Couple *couples)
{
	
	//printing assigned gifts
	fstream logFile("logFile8.dat", std::fstream::in | std::fstream::out | std::fstream::app);
	logFile<<"\n\n-----------------GIFTS ALLOCATION-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" gives Girl g"<<couples[i].getGirl()<<" the following Gifts\n";
		
		int * arr =	couples[i].getGifts();
		for(int j = 0; j < couples[i].getNum(); j++) {
			logFile<<"G"<<gift[arr[j]-1].getId()<<" of worth Rs "<<gift[arr[j]-1].getprice()<<"\n";
		}
		logFile<<endl;
	}
}


void method1:: allocate(Couple *couples, Boy *boys, Girl *girls)
{
	//Assigning gifts to couples
	for(int i  = 0 ;i < C; i++) {
		int boy = couples[i].getBoy()[0] - 48;
		int girl = couples[i].getGirl()[0] - 48;
		int mc = girls[girl-1].getMaintenance();
		int bud = boys[boy-1].getBudget();
		int x = bud - mc;
		char bt = boys[boy-1].getType();	
	
		if(bt == 'M') {
			for(int j = 0 ; j < Gf; j++) {
				
				if(gift[j].getprice() <= mc && gift[j].getStatus() == 0) {
					couples[i].setGifts(j+1);
					gift[j].setStatus(1);
					mc = mc - gift[j].getprice();
				} else if( gift[j].getprice() <= x +mc ) {
					if( gift[j].getStatus() == 0)	{				
						couple[i].setGifts(j+1);
						gift[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			} 
		} else  if(bt == 'N') {
			for(int j = Gf-1 ; j >= 0; j--) {
				if(gift[j].getprice() <= bud && gift[j].getStatus() == 0) {
					couple[i].setGifts(j+1);
					gift[j].setStatus(1);
					bud = bud- gift[j].getprice();
				}
			}
		} else {
			for(int j = 0 ; j < Gf; j++) {
				if(gift[j].getprice() <= mc && gift[j].getStatus() == 0) {
					couple[i].setGifts(j+1);
					gift[j].setStatus(1);
					mc = mc - gift[j].getprice();
				}else if(gift[j].getprice() <= x +mc) {
					if( gift[j].getStatus() == 0)	{				
						couple[i].setGifts(j+1);
						gift[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			}
		}
	}

	for(int j = 0 ; j < Gf; j++) {
		gift[j].setStatus(0);
	}

}

void method2:: allocate(Couple *couples, Boy *boys, Girl *girls)
{
	//Assigning gifts to couples
	for(int i  = 0 ;i < C; i++) {
		int boy = couple[i].getBoy()[0] - 48;
		int girl = couple[i].getGirl()[0] - 48;
		int mc = girl[girl-1].getMaintenance();
		int bud = boy[boy-1].getBudget();
		int x = bud - mc;
		char bt = boy[boy-1].getType();	
	
		if(bt == 'N') {
			for(int j = 0 ; j < Gf; j++) {
				
				if(gift[j].getprice() <= mc && gift[j].getStatus() == 0) {
					couple[i].setGifts(j+1);
					gift[j].setStatus(1);
					mc = mc - gift[j].getprice();
				} else if( gift[j].getprice() <= x +mc ) {
					if( gift[j].getStatus() == 0)	{				
						couple[i].setGifts(j+1);
						gift[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			} 
		} else  if(bt == 'K') {
			for(int j = Gf-1 ; j >= 0; j--) {
				if(gift[j].getprice() <= bud && gift[j].getStatus() == 0) {
					couple[i].setGifts(j+1);
					gift[j].setStatus(1);
					bud = bud- gift[j].getprice();
				}
			}
		} else {
			for(int j = 0 ; j < Gf; j++) {
				if(gift[j].getprice() <= mc && gift[j].getStatus() == 0) {
					couple[i].setGifts(j+1);
					gift[j].setStatus(1);
					mc = mc - gift[j].getprice();
				}else if(gift[j].getprice() <= x +mc) {
					if( gift[j].getStatus() == 0)	{				
						couple[i].setGifts(j+1);
						gift[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			}
		}
	}

	for(int j = 0 ; j < Gf; j++) {
		gift[j].setStatus(0);
	}

}

