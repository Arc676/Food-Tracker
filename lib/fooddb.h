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

		/**
		 * Adds a new food to the database
		 * @param food Food to add to database
		 */
		void insertFood(Food food);

		/**
		 * Searches database for data regarding
		 * food with a given name
		 * @param name Name of food
		 * @return Pointer to food object (null if not found)
		 */
		Food* findFood(const std::string& name);

		/**
		 * Save database to disk
		 * @param filename Filename to which to save database
		 * @return Whether the save succeeded
		 */
		bool save(const std::string&);

		/**
		 * Read database from disk
		 * @param filename Filename from which to read database
		 * @return Whether the load succeeded
		 */
		bool read(const std::string&);
};

#endif
