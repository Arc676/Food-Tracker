#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
		std::string name;
		int daysToSpoil;
	public:
		Food() : name("Unnamed food"), daysToSpoil(0) {}
		Food(const std::string& name, int days) : name(name), daysToSpoil(days) {}
		std::string& getName();
		int duration();
};

#endif
