#include "food.h"

std::string& Food::getName() {
	return name;
}

int Food::duration() {
	return daysToSpoil;
}
