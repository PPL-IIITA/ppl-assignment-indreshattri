#include "gift.h"
#include <string>

void Gift:: init(int val, int pr, std::string ty ){
	price = pr;
	value = val;
	type = ty;
}

int Gift:: getPrice(){
	return price;
}