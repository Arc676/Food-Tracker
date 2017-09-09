#include <list>
#include "item.h"

class Cupboard {
		std::list<Item> foodstuffs;
	public:
		std::list<Item>* getFoods();
};
