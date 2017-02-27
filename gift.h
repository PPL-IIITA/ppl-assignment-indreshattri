#ifndef GIFT_H
#define GIFT_H
#include <string>

class Gift{
	private:
		int value;
		int price;
		std:: string type;
	public:
		void init(int val, int pr, std::string ty );
		int getPrice();
};

#endif