#include "foodtracker.h"

void FoodTracker::run() {
	using namespace std;
	cout << "Welcome to Food Tracker!\n";
	cout << "Enter food name: ";
	string name;
	getline(cin, name);
	cout << "How many days until " << name << " spoils? ";
	string days;
	getline(cin, days);
	int d = stoi(days, nullptr, 0);
	Food food(name, d);
	Cupboard* cupboard = new Cupboard();
	list<Item>* foods = cupboard->getFoods();
	Item item(food, time(nullptr));
	foods->push_back(item);
	for (list<Item>::iterator it = foods->begin(); it != foods->end(); it++){
		cout << "Food: " << it->getFood().getName() << "\nDays to spoilage: " << it->getFood().duration() << "\n";
	}
	cout << "No more foods\n";
}

int main(int argc, char * argv[]){
	FoodTracker().run();
}
