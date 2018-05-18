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

#include "recipe.h"

Recipe::Recipe(std::string name, std::map<std::string, float> ingredients) : name(name), ingredients(ingredients) {}

std::string Recipe::getName() {
	return name;
}

std::map<std::string, float> Recipe::possiblePortions(Cupboard cupboard) {
	std::map<std::string, float> portions;
	for (auto item : *(cupboard.getFoods())) {
		std::string name = item.getFood().getName();
		if (ingredients.find(name) != ingredients.end()) {
			portions[name] += item.getQuantity();
		}
	}
	for (auto& it : portions) {
		it.second /= ingredients[it.first];
	}
	return portions;
}
