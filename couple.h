#ifndef COUPLE_H
#define COUPLE_H
#include <string>

class couple{
	private:
		std:: string boyname;
		std:: string girlname;
		float happiness;
		int boybudget;
		int girlmaint;
		int boyHappiness;
		int girlHappiness;
		int curBudget;
		int giftPrice;
		int boyintelli;
		int boyattr;
		int girlintelli;
		int girlattr;
		int compatibility;
		std:: string boyType;
	public:
		void setHappiness();
		void setCompatibility();
		int getCompatibility();
		int getHappiness();
		void init(std:: string boy, std:: string type, std:: string girl, int bud, int maint, int boyattr, int girlattr, int boyintelli, int girlintelli) ;
		int getBudget();
		std:: string getBoyname();
		std:: string getGirlname();
		void setBoyHappiness(int hap);
		void setGirlHappiness(int hap);
		int getGirlHappiness();
		void changeCurrBudget(int val);
		int getCurrBudget();
		int getCost();
		std:: string getBoyType();
};

#endif