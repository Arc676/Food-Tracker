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
