#include <iostream>
#include "Cuarto.h"
using namespace std;

void Cuarto::setMonstruo(Monstruo monster1) {
	monster = monster1;
}

Monstruo Cuarto::getMonstruo() {
	return monster;
}
