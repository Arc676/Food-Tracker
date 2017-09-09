#include "foodtracker.h"

void FoodTracker::run() {
	using namespace std;
	cout << "Welcome to Food Tracker!\n";
	cout << "Enter food name: ";
	string name;
	getline(cin, name);
	Food food(name, 10);
	cout << "Food: " << food.getName() << "\nDays: " << food.duration() << endl;
}

int main(int argc, char * argv[]){
	FoodTracker().run();
}
