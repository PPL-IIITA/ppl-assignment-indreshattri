#ifndef BOY_H
#define BOY_H
#include<string>

class Boy{
	public:
		void init(std::string boyname, std:: string boytype, int boyattr, int boyintelli, int boybud);
		int getStatus();
		void changeStatus();
		void changeBudget(int price);
		int getBudget();
		int getIntelli();
		int getAttr();
		std::string getName();
		std:: string getType();
	private:
		std::string name;
		std::string girlfriend;
		std:: string type;
		int attr;
		int intelli;
		int budget;
		int committed;
		
};

#endif
