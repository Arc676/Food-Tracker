#ifndef FOODDB_H
#define FOODDB_H

#include <map>
#include <string>
#include <fstream>
#include "food.h"

class FoodDB {
		std::map<std::string, Food> foodDB;
	public:
		FoodDB() : foodDB() {}

		void insertFood(Food);
		Food* findFood(const std::string&);

		bool save(const std::string&);
		bool read(const std::string&);
};

#endif
