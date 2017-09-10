#ifndef ITEM_H
#define ITEM_H

#include <sstream>
#include <ctime>
#include "food.h"

class Item {
		Food food;
		time_t purchaseDate;
	public:
		Item(Food food, time_t date) : food(food), purchaseDate(date) {}
		Item(const std::string& line);
		Food getFood();
		std::string toString();
};

#endif
