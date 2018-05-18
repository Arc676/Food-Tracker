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

		/**
		 * Add a new item to the cupboard
		 * @param item Item to add
		 */
		void insertItem(Item item);

		/**
		 * Save the cupboard contents to disk
		 * @param filename Filename to which to save contents
		 * @return Whether the save succeeded
		 */
		bool save(const std::string& filename);

		/**
		 * Read cupboard state from disk
		 * @param filename Filename from which to read contents
		 * @param Whether the load succeeded
		 */
		bool read(const std::string& filename);
};

#endif
