#include "boy.h"
#include <string>

void Boy:: init(std::string boyname, std:: string boytype, int boyattr, int boyintelli, int boybud){
	name = boyname;
	type = boytype;
	attr = boyattr;
	intelli = boyintelli;
	budget = boybud;
	committed = 0;
}

int Boy:: getBudget() {
	return budget;
}

int Boy:: getIntelli() {
	return intelli;
}

int Boy:: getAttr() {
	return attr;
}


void Boy:: changeBudget(int price) {
	budget = budget + price;
}

std::string Boy:: getName() {
	return name;
}
	
int Boy:: getStatus(){
	return committed;
}

std::string Boy:: getType() {
	return type;
}
	
void Boy::changeStatus() {
	if(committed == 0) {
		committed = 1;
	} else {
		committed = 0;
	}
}
