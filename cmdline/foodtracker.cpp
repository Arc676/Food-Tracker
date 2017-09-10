#include "foodtracker.h"

void FoodTracker::run() {
	using namespace std;
	Cupboard* cupboard = new Cupboard();
	list<Item>* foods = cupboard->getFoods();
	cout << "Welcome to Food Tracker!\n";
	string cmd;
	while (true) {
		cout << "Enter command: ";
		getline(cin, cmd);
		if (cmd == "new") {
			cout << "Enter food name: ";
			string name;
			getline(cin, name);
			cout << "How many days until " << name << " spoils? ";
			int d;
			cin >> d;
			Food food(name, d);
			Item item(food, time(nullptr));
			foods->push_back(item);
		} else if (cmd == "save" || cmd == "read") {
			string filename;
			cout << "Enter filename: ";
			getline(cin, filename);
			if (cmd == "save") {
				if (cupboard->save(filename)) {
					cout << "Save successful\n";
				} else {
					cout << "Save failed\n";
				}
			} else {
				if (cupboard->read(filename)) {
					cout << "Read successful\n";
				} else {
					cout << "Read failed\n";
				}
			}
		} else if (cmd == "print") {
			for (list<Item>::iterator it = foods->begin(); it != foods->end(); it++){
				cout << "Food: " << it->getFood().getName() << "\n\tDays to spoilage: " << it->getFood().duration() << "\n";
			}
		} else if (cmd == "exit") {
			break;
		} else if (cmd == "help") {
			cout << "new, save, read, print, exit";
		}
	}
}

int main(int argc, char * argv[]){
	FoodTracker().run();
}
