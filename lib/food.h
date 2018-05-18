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

#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
		std::string name;
		int daysToSpoil;
	public:
		/**
		 * Default constructor
		 */
		Food() : name("Unnamed food"), daysToSpoil(0) {}

		/**
		 * Construct a new food object
		 * @param name Food name
		 * @param days Days until food spoils
		 */
		Food(const std::string& name, int days) : name(name), daysToSpoil(days) {}

		std::string& getName();

		int duration();
		void setDuration(int);
};

#endif
