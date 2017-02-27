#include "girl.h"
#include <string>

void Girl:: init(std::string girlname, std::string girltype, int girlattr, int girlintelli, int girlmaint){
	name = girlname;
	type = girltype;
	attr = girlattr;
	intelli = girlintelli;
	maint = girlmaint;
	committed = 0;
}

int Girl:: getMaint(){
	return maint;
}

int Girl:: getIntelli(){
	return intelli;
}

int Girl:: getAttr(){
	return attr;
}
	
int Girl:: getStatus(){
	return committed;
}

int Girl:: getIntelligence(){
	return intelli;
}

std::string  Girl:: getName(){
	return name;
}

std::string Girl:: getType() {
	return type;
}
	
void Girl::changeStatus() {
	if(committed == 0) {
		committed = 1;
	} else {
		committed = 1;
	}
}
