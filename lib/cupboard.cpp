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

#include "cupboard.h"

Cupboard::Cupboard() {
	foodstuffs = {};
}

std::list<Item>* Cupboard::getFoods() {
	return &foodstuffs;
}

void Cupboard::insertItem(Item item) {
	std::list<Item>::iterator it;
	int daysLeft = item.daysLeft();
	for (it = foodstuffs.begin(); it != foodstuffs.end(); it++) {
		if (it->daysLeft() > daysLeft) {
			break;
		}
	}
	foodstuffs.insert(it, item);
}

bool Cupboard::save(const std::string& filename) {
	std::ofstream file;
	file.open(filename);
	if (!file.is_open()) {
		return false;
	}
	for (std::list<Item>::iterator it = foodstuffs.begin(); it != foodstuffs.end(); it++) {
		file << it->toString() << "\n";
	}
	file.close();
	return true;
}

bool Cupboard::read(const std::string& filename) {
	foodstuffs = {};
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		return false;
	}
	std::string line;
	while (getline(file, line)) {
		Item item(line);
		foodstuffs.push_back(item);
	}
	return true;
}
