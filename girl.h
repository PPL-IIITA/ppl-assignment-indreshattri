#ifndef GIRL_H
#define GIRL_H
#include<string>

class Girl{
	public:
		void init(std::string girlname, std::string girltype, int girlattr, int girlintelli, int girlmaint);
		int getStatus();
		int getIntelligence();
		void changeStatus();
		int getMaint();
		int getIntelli();
		int getAttr();
		std::string getName();
		std:: string getType();
	private:
		std::string name;
		std::string boyfriend;
		std::string type;
		int attr;
		int intelli;
		int maint;
		int committed;
};

#endif
