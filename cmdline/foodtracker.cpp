#include "foodtracker.h"

void FoodTracker::run() {
	using namespace std;
	Cupboard cupboard = Cupboard();
	FoodDB foodDB = FoodDB();
	cout << "Welcome to Food Tracker!\n";
	string cmd;
	while (true) {
		cout << "Enter command: ";
		getline(cin, cmd);
		if (cmd == "new" || cmd == "load") {
			time_t now = time(nullptr);
			string name;
			Food food;
			cout << "Enter food name: ";
			getline(cin, name);
			if (cmd == "new") {
				cout << "Enter (d)ays or d(a)te? (default date): ";
				int d;
				string days;
				getline(cin, days);
				if (days == "d") {
					cout << "How many days until " << name << " spoils? ";
					getline(cin, days);
					d = std::stoi(days, nullptr, 0);
				} else {
					cout << "Enter spoilage date (YYYY-MM-DD format): ";
					getline(cin, days);
					struct tm timeptr;
					strptime(days.c_str(), "%F", &timeptr);
					d = Item::daysBetween(mktime(&timeptr), now);
				}
				food = Food(name, d);
				string inp;
				cout << "Save " << name << " to database? [Y/n]: ";
				getline(cin, inp);
				if (inp != "n" && inp != "N") {
					foodDB.insertFood(food);
					cout << "Saved to database\n";
				}
			} else {
				Food* fd = foodDB.findFood(name);
				if (fd == nullptr) {
					cerr << "Failed to find the given food. Use 'new' instead.\n";
					continue;
				}
				food = *fd;
			}
			Item item(food, now);
			cupboard.insertItem(item);
		} else if (cmd == "save" || cmd == "read") {
			string filename, filename2;
			cout << "Enter cupboard filename: ";
			getline(cin, filename);
			cout << "Enter database filename: ";
			getline(cin, filename2);
			if (cmd == "save") {
				if (cupboard.save(filename)) {
					cout << "Save cupboard successful\n";
				} else {
					cout << "Save cupboard failed\n";
				}
				if (foodDB.save(filename2)) {
					cout << "Save database successful\n";
				} else {
					cout << "Save database failed\n";
				}
			} else {
				if (cupboard.read(filename)) {
					cout << "Read cupboard successful\n";
				} else {
					cout << "Read cupboard failed\n";
				}
				if (foodDB.read(filename2)) {
					cout << "Read database successful\n";
				} else {
					cout << "Read database failed\n";
				}
			}
		} else if (cmd == "print") {
			list<Item>* foods = cupboard.getFoods();
			for (list<Item>::iterator it = foods->begin(); it != foods->end(); it++){
				cout << "Food: " << it->getFood().getName() << "\n\tDays to spoilage: " << it->getFood().duration() << "\n";
			}
		} else if (cmd == "exit") {
			break;
		} else if (cmd == "help") {
			cout << "new, load, save, read, print, exit";
		}
	}
}

int main(int argc, char * argv[]){
	FoodTracker().run();
}
