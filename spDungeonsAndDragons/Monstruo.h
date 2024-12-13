#pragma once
#include <iostream>
using namespace std;

class Monstruo {

public:
	Monstruo() : name(""), cr(0), type(""), size(""), ac(0), hp(0), align("") {}

	~Monstruo() {
	}

	void setName(string nombre); // Complejidad de todos los metodos: O(1)
	string getName();
	void setCr(double Cr);
	double getCr();
	void setType(string tipo);
	string getType();
	void setSize(string tamano);
	string getSize();
	void setAc(int Ac);
	int getAc();
	void setHp(int Hp);
	int getHp();
	void setAlign(string Align);
	string getAlign();
	void imprimirMonstruo();
	
	friend ostream& operator<<(ostream& os, const Monstruo& monster) {  
		os << monster.name;    //Sobrecarga << para imprimir el nombre del monstruo
		return os;
	}

	bool operator<(const Monstruo& monster) {   //Sobrecargas para comparar monstruos por su nombre
		return name < monster.name;            //en orden alfabetico (valor ASCII del primer char)
	}

	bool operator>(const Monstruo& monster) {
		return name > monster.name;
	}
	
private:
	string name;
	double cr;
	string type;
	string size;
	int ac;
	int hp;
	string align;
};
