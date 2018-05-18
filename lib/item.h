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

#ifndef ITEM_H
#define ITEM_H

#include <sstream>
#include <ctime>
#include <cmath>

#include "food.h"

class Item {
		Food food;
		float quantity;
		time_t purchaseDate;
	public:
		/**
		 * Construct a new Item
		 * @param food Type of food for this item
		 * @param date Purchase date of this item
		 * @param quantity Quantity of food for this item
		 */
		Item(Food food, time_t date, float quantity);

		/**
		 * Construct a new Item from a string
		 * representation of properties
		 * @param line String representation of the item
		 */
		Item(const std::string& line);

		Food getFood();
		std::string toString();

		void updateQuantity(float);
		float getQuantity();

		/**
		 * Gets the number of days left before the item expires
		 * @return Number of days before spoilage
		 */
		int daysLeft();

		/**
		 * Utility function for determining the number of
		 * days between two given dates
		 * @param t1 Later time
		 * @param t2 Earlier time
		 * @return Number of days between the given dates
		 */
		static int daysBetween(time_t t1, time_t t2);
};

#endif
