#pragma once
#include <iostream>
#include "templateGrafos.h"   //Calabozo es un Grafo de cuartos
#include "Cuarto.h"    //Calabozo contiene cuartos
using namespace std;

class Dungeon {
private:
	Grafo<Cuarto> rooms;
	ListaDoble<Cuarto> path;
	ListaDoble<Cuarto>::iterator act;

public:
	Dungeon() {
	}

	~Dungeon() {
		rooms.borrarGrafo();
		path.deleteListaDoble();
	}

	bool createDungeon(const string& fileName);  //Complejidad de los metodos: O(n) 
	bool createRoom(unsigned int indexCuarto, Monstruo monster);  
	void imprimeCuartos();
	unsigned int getSize();   //Complejidad: O(1)
	bool trazaRuta(unsigned int inicio, unsigned int final);  //Complejidad: O(n)
	bool avanzaRuta();    //Complejidad: O(1)
	Cuarto* cuartoActualRuta();    //Complejidad: O(1)
};
