#include "item.h"

Food Item::getFood() {
	return food;
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
