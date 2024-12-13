#pragma once
#include <iostream>
#include "Monstruo.h"   //Cuartos contienen monstruos
using namespace std;

class Cuarto {
public:
	Cuarto() {
	}

	~Cuarto() {
	}

	void setMonstruo(Monstruo monster1);  //Complejidad de los metodos: O(1)
	Monstruo getMonstruo();

	friend ostream& operator<<(ostream& os, const Cuarto& room) {
		os << "Cuarto con " << room.monster;   //Sobrecarga para imprimir el monstruo de un cuarto
		return os;
	}

	bool operator<(const Cuarto& hab) {   //Sobrecargas para comparar cuartos segun el monstruo
		return monster < hab.monster;      //que contengan (a su vez estan comparados por nombre).
	}

	bool operator>(const Cuarto& hab) {
		return monster > hab.monster;   //Va a imprimir los cuartos en orden alfabetico
	}
	
private:
	Monstruo monster;   
};
