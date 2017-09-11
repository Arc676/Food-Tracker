# Food-Tracker
C++ library and command line utility for keeping track of food and when it spoils

Project available under GPLv3. You can use the library separately in your own C++ applications if you wish.

## Available API calls:
`Cupboard`
- `std::list<Item>* getFoods()` - returns the list of food Items
- `void insertItem(Item)` - inserts the specified Item at the required location to keep it sorted by days until spoilage
- `bool save(const std::string& filename)` - saves the cupboard state to the specified file
- `bool read(const std::string& filename)` - reads cupboard state from file

`Food`
- `Food() : name("Unnamed food"), daysToSpoil(0) {}` - default constructor
- `Food(const std::string& name, int days) : name(name), daysToSpoil(days) {}` - constructor with name and days to spoilage
- `std::string& getName()` - returns the food name
- `int duration()` - returns the days to spoilage

`Item`
- `Item(Food food, time_t date) : food(food), purchaseDate(date) {}` - constructor with food and purchase date
- `Item(const std::string& line)` - constructor that parses data from text
- `Food getFood()` - returns the food
- `std::string toString()` - returns the string form of the Item for saving
- `int daysLeft()` - returns how many days are left before spoilage
- `static int daysBetween(time_t, time_t)` - utility function (uses difftime but returns days instead of seconds)
