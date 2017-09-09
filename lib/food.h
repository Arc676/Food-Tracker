#include <string>

class Food {
		std::string name;
		int daysToSpoil;
	public:
		Food(const std::string&, int);
		std::string& getName();
		int duration();
};
