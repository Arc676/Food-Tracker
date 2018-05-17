//Foodtracker
//Written by Alessandro Vinciguerra <alesvinciguerra@gmail.com>
//Copyright (C) 2018  Arc676/Alessandro Vinciguerra

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

#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <map>

class Recipe {
	std::string name;
	std::map<std::string, float> ingredients;
public:
	/**
	 * Construct a new Recipe object
	 * @param name Name of recipe
	 * @param ingredients Map containing ingredients and required quantities
	 */
	Recipe(std::string name, std::map<std::string, float> ingredients);

	std::string getName();
};

#endif
