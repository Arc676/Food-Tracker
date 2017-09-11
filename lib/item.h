#ifndef ITEM_H
#define ITEM_H

#include <sstream>
#include <ctime>
#include <cmath>
#include "food.h"

class Item {
		Food food;
		time_t purchaseDate;
	public:
		Item(Food food, time_t date) : food(food), purchaseDate(date) {}
		Item(const std::string& line);
		Food getFood();
		std::string toString();

		int daysLeft();
		static int daysBetween(time_t, time_t);
};

#endif
