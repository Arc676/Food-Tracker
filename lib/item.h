#include <ctime>
#include "food.h"

class Item {
		Food food;
		time_t purchaseDate;
	public:
		Item(Food food, time_t date) : food(food), purchaseDate(date) {}
		Food getFood();
};
