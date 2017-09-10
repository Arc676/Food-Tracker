#include "cupboard.h"

Cupboard::Cupboard() {
	foodstuffs = {};
}

std::list<Item>* Cupboard::getFoods() {
	return &foodstuffs;
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
