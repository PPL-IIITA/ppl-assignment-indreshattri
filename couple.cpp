#include "couple.h"
#include <string>
#include <cmath>

void couple:: init(std:: string boy, std:: string type, std:: string girl, int bud, int maint, int boyattr, int girlattr, int boyintelli, int girlintelli) {
	boyname = boy;
	girlname = girl;
	boybudget = bud;
	girlmaint = maint;
	curBudget = bud;
	giftPrice = 0;
	boyattr = boyattr;
	boyintelli = boyintelli;
	girlattr = girlattr;
	girlintelli = girlintelli;
	boyType = type;
}

int couple:: getCurrBudget() {
	return curBudget;
}

void couple:: changeCurrBudget(int val) {
	curBudget = curBudget - val;
	giftPrice += val;
}

int couple:: getCost() {
	return giftPrice;
}

std::string couple:: getBoyType() {
	return boyType;
}

int couple:: getBudget(){
	return boybudget;
}

std:: string couple:: getBoyname() {
	return boyname;
}

std:: string couple:: getGirlname(){
	return girlname;
}

void couple:: setBoyHappiness(int hap) {
	boyHappiness = hap;
}

void couple:: setGirlHappiness(int hap) {
	girlHappiness = hap;
}

int couple:: getGirlHappiness() {
	return girlHappiness;
}

int couple:: getHappiness() {
	return happiness;
}

void couple:: setHappiness() {
	happiness = girlHappiness + boyHappiness;
}

void couple:: setCompatibility() {
	compatibility = std::abs(boybudget - girlmaint) + std::abs(girlattr - boyattr) + std::abs(girlintelli - boyintelli);
}

int couple:: getCompatibility() {
	return compatibility;
}