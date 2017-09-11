#ifndef CUPBOARD_H
#define CUPBOARD_H

#include <list>
#include <fstream>
#include "item.h"

class Cupboard {
		std::list<Item> foodstuffs;
	public:
		Cupboard();
		std::list<Item>* getFoods();
		void insertItem(Item);
		bool save(const std::string& filename);
		bool read(const std::string& filename);
};

#endif
