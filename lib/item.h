//Foodtracker
//Written by Alessandro Vinciguerra <alesvinciguerra@gmail.com>
//Copyright (C) 2017  Arc676/Alessandro Vinciguerra

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
