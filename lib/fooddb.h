#ifndef FOODDB_H
#define FOODDB_H

#include <map>
#include <string>
#include <fstream>
#include "food.h"

class FoodDB {
	public:
		std::map<std::string, Food> foodDB;
		FoodDB() : foodDB() {}
		bool save(const std::string&);
		bool read(const std::string&);
};

#endif
