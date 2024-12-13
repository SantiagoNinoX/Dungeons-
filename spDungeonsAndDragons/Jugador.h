#pragma once
#include <iostream>
#include "TemplateListasSimples.h"  //Jugador tiene una lista ligada de monstruos derrotados
#include "Monstruo.h"   //La lista ligada del jugador contiene monstruos
using namespace std;

class Jugador {
public:
	Jugador() {
		hp = 100;
		race = " ";
		username = " ";
		mp = 100;
	}

	~Jugador() {
		monstruosDerrotados.deleteLista();
	}

	void setRace(string raza);   //Complejidades de getters y setters: O(1)
	string getRace();
	void setUser(string user);
	string getUser();
	void setHp(int Hp);
	int getHp();
	void setMp(int Mp);
	int getMp();
	void imprimirJugador(); //O(1)
	void ganarBatallaHp(); //O(1)
	void usarHechizoMp();   //O(1)
	bool insertaMonstruosDerrotados(Monstruo& derrotado);  //O(n)
	void imprimirDerrotados();  //O(n)
	
private:
	int hp;
	string race;    //elf, human, dwarf
	string username;
	int mp;
	ListaLigada<Monstruo> monstruosDerrotados;
};
