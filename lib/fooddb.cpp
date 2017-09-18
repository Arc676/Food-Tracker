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

#include "fooddb.h"

bool FoodDB::save(const std::string& filename) {
	std::ofstream file;
	file.open(filename);
	if (!file.is_open()) {
		return false;
	}
	for (std::map<std::string, Food>::iterator it = foodDB.begin(); it != foodDB.end(); it++) {
		file << it->second.getName() << "|" << it->second.duration() << "\n";
	}
	file.close();
	return true;
}

bool FoodDB::read(const std::string& filename) {
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		return false;
	}
	std::string line;
	while (getline(file, line)) {
		size_t pos = line.find('|');
		std::string name = line.substr(0, pos);
		int days = std::stoi(line.substr(pos + 1));
		foodDB[name] = Food(name, days);
	}
	file.close();
	return true;
}

Food* FoodDB::findFood(const std::string& name) {
	std::map<std::string, Food>::iterator it = foodDB.find(name);
	if (it == foodDB.end()) {
		return nullptr;
	}
	return &(it->second);
}

void FoodDB::insertFood(Food food) {
	foodDB[food.getName()] = food;
}
