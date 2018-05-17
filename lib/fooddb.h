//Foodtracker
//Written by Alessandro Vinciguerra <alesvinciguerra@gmail.com>
//Copyright (C) 2017-8 Arc676/Alessandro Vinciguerra

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3).

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//See README.md and LICENSE for more details

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
