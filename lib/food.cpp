#include "food.h"

Food::Food(const std::string& name, int days) : name(name), daysToSpoil(days) {}

std::string& Food::getName() {
	return name;
}

int Food::duration() {
	return daysToSpoil;
}
