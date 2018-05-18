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

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "libfood.h"

int getTime(std::string &name, time_t now) {
	std::cout << "Enter (d)ays or d(a)te? (default date): ";
	std::string days;
	std::getline(std::cin, days);
	if (days == "d") {
		std::cout << "How many days until " << name << " spoils? ";
		std::getline(std::cin, days);
		return std::stoi(days, nullptr, 0);
	} else {
		std::cout << "Enter spoilage date (YYYY-MM-DD format): ";
		std::getline(std::cin, days);
		struct tm timeptr;
		strptime(days.c_str(), "%F", &timeptr);
		return Item::daysBetween(mktime(&timeptr), now);
	}
}

void run() {
	Cupboard cupboard = Cupboard();
	FoodDB foodDB = FoodDB();
	std::cout << "Welcome to Food Tracker!\n";
	std::string cmd;
	while (true) {
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		if (cmd == "new" || cmd == "load") {
			time_t now = time(nullptr);
			std::string name;
			Food food;
			std::cout << "Enter food name: ";
			std::getline(std::cin, name);
			if (cmd == "new") {
				food = Food(name, getTime(name, now));
				std::string inp;
				std::cout << "Save " << name << " to database? [Y/n]: ";
				std::getline(std::cin, inp);
				if (inp != "n" && inp != "N") {
					foodDB.insertFood(food);
					std::cout << "Saved to database\n";
				}
			} else {
				Food* fd = foodDB.findFood(name);
				if (fd == nullptr) {
					std::cerr << "Failed to find the given food. Use 'new' instead.\n";
					continue;
				}
				food = *fd;
				std::string input;
				std::cout << "Use default spoilage time (" << food.duration() << ")? [Y/n]: ";
				std::getline(std::cin, input);
				if (input == "n" || input == "N") {
					food.setDuration(getTime(name, now));
				}
			}
			std::cout << "Enter quantity of food stored: ";
			float qty;
			std::cin >> qty;
			Item item(food, now, qty);
			cupboard.insertItem(item);
		} else if (cmd == "save" || cmd == "read") {
			std::string filename, filename2;
			std::cout << "Enter cupboard filename: ";
			std::getline(std::cin, filename);
			std::cout << "Enter database filename: ";
			std::getline(std::cin, filename2);
			if (cmd == "save") {
				if (cupboard.save(filename)) {
					std::cout << "Save cupboard successful\n";
				} else {
					std::cout << "Save cupboard failed\n";
				}
				if (foodDB.save(filename2)) {
					std::cout << "Save database successful\n";
				} else {
					std::cout << "Save database failed\n";
				}
			} else {
				if (cupboard.read(filename)) {
					std::cout << "Read cupboard successful\n";
				} else {
					std::cout << "Read cupboard failed\n";
				}
				if (foodDB.read(filename2)) {
					std::cout << "Read database successful\n";
				} else {
					std::cout << "Read database failed\n";
				}
			}
		} else if (cmd == "print") {
			std::list<Item>* foods = cupboard.getFoods();
			for (std::list<Item>::iterator it = foods->begin(); it != foods->end(); it++) {
				std::cout << "Food: " << it->getFood().getName() << "\n\tDays to spoilage: " << it->daysLeft() << "\n";
			}
		} else if (cmd == "exit") {
			break;
		} else if (cmd == "help") {
			std::cout << "new, load, remove, save, read, print, exit\n";
		} else if (cmd == "remove") {
			std::string name;
			std::cout << "Enter food name: ";
			std::getline(std::cin, name);
			std::list<std::list<Item>::iterator> items = {};
			std::list<Item>* foods = cupboard.getFoods();
			for (std::list<Item>::iterator it = foods->begin(); it != foods->end(); it++) {
				if (it->getFood().getName() == name) {
					items.push_back(it);
				}
			}
			if (items.size() == 0) {
				std::cout << "Food not found\n";
				continue;
			}
			int i = 0;
			std::list<std::list<Item>::iterator>::iterator it;
			for (it = items.begin(); it != items.end(); it++) {
				std::cout << i << ": " << (*it)->getFood().getName() << " (" << (*it)->daysLeft() << " days left)\n";
				i++;
			}
			if (i > 1) {
				std::cout << "Enter index of food to remove: ";
				std::getline(std::cin, name);
				i = std::stoi(name, nullptr, 0);
				if (i >= items.size()) {
					std::cout << "Invalid index\n";
					continue;
				}
			} else {
				i--;
			}
			it = items.begin();
			std::advance(it, i);
			foods->erase(*it);
		}
	}
}

int main(int argc, char * argv[]) {
	std::cout << "foodtracker  Copyright (C) 2017  Arc676/Alessandro Vinciguerra\n\
This program comes with ABSOLUTELY NO WARRANTY and is available under the General\n\
Public License version 3; you are welcome to redistribute it\n\
under certain conditions. See LICENSE for full GPL text." << std::endl;
	run();
}
