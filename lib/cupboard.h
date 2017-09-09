#include <list>
#include "item.h"

class Cupboard {
		std::list<Item> foodstuffs;
	public:
		Cupboard();
		std::list<Item>* getFoods();
};
