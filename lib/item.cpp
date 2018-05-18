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

#include "item.h"

Item::Item(Food food, time_t time, float quantity) : food(food), purchaseDate(time), quantity(quantity) {}

void Item::updateQuantity(float delta) {
	quantity += delta;
}

float Item::getQuantity() {
	return quantity;
}

Food Item::getFood() {
	return food;
}

int Item::daysBetween(time_t t1, time_t t2) {
	return (int)floor(difftime(t1, t2) / (60 * 60 * 24));
}

int Item::daysLeft() {
	return food.duration() - Item::daysBetween(time(nullptr), purchaseDate);
}

Item::Item(const std::string& line) {
	size_t pos = line.find('|');
	std::string name = line.substr(0, pos);

	size_t pos2 = line.find('|', pos + 1);
	int days = std::stoi(line.substr(pos + 1, pos2));

	food = Food(name, days);

	purchaseDate = (time_t)std::stoi(line.substr(pos2 + 1));
}

std::string Item::toString() {
	std::stringstream ss;
	ss << food.getName() << "|" << food.duration() << "|" << purchaseDate;
	return ss.str();
}
