#include "cupboard.h"

Cupboard::Cupboard() {
	foodstuffs = {};
}

std::list<Item>* Cupboard::getFoods() {
	return &foodstuffs;
}
