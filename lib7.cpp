#include "lib7.h"

void Library:: searchArr()
{	

	fstream logFile("logFile7.dat", std::fstream::in | std::fstream::out | std::fstream::app);
	logFile<<"\n----------You selected Linear search------------\n\n";
	for(int j = 0; j < S; j++) {
		int flag = 0;
		int ind;
		for(int i = 0; i < C; i++) {

			if(couples[i].getBoyname()[0] == boysList[j].getName()[0]){

				flag == 1;
				ind = i;		
				logFile<<"Boy b"<<boysList[j].getName()<<" is commited with Girl g"<<couples[ind].getGirlname()<<endl;	
			} 
		}
	}

}
void Library:: searchSortedArr()
{
	fstream logFile("logFile7.dat", std::fstream::in | std::fstream::out | std::fstream::app);
	logFile<<"\n--------You selected Binary Search in sorted Array---------\n\n";
	for(int j = 0; j < S; j++) {
		int flag = 0;
		int ind;
		for(int i = 0; i < C; i++) {

			if(sortedCouples[i].getBoyname()[0] == boysList[j].getName()[0]){

				flag == 1;
				ind = i;		
				logFile<<"Boy b"<<boysList[j].getName()<<" is commited with Girl g"<<sortedCouples[ind].getGirlname()<<endl;	
			} 
		}
	}
}
void Library:: searchHash()
{
	fstream logFile("logFile7.dat", std::fstream::in | std::fstream::out | std::fstream::app);
	logFile<<"\n-----------You selected Hash algorith-----------\n\n";
	for(int j = 0; j < S; j++) {
		int flag = 0;
		int ind;
		for(int i = 0; i < C; i++) {

			if(hashCouples[i].getBoyname()[0] == boysList[j].getName()[0]){

				flag == 1;
				ind = i;		
				logFile<<"Boy b"<<boysList[j].getName()<<" is commited with Girl g"<<hashCouples[ind].getGirlname()<<endl;	
			} 
		}
	}
}

