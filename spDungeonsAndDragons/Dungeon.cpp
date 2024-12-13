#include <iostream>
#include "Dungeon.h"
using namespace std;

bool Dungeon::createDungeon(const string& fileName) {
	return rooms.cargarArchivo(fileName);
}

void Dungeon::imprimeCuartos() {
	rooms.imprimirGrafo();
}

bool Dungeon::createRoom(unsigned int indexCuarto, Monstruo monster) {
	Cuarto recamara;
	recamara.setMonstruo(monster);
	return rooms.setVertex(indexCuarto, recamara);
}

unsigned int Dungeon::getSize() {
	return rooms.getSizeGrafo();
}

bool Dungeon::trazaRuta(unsigned int inicio, unsigned int final) {
	if (rooms.printPathBFS(inicio, final, path)) {
		act = path.begin();   //Se posiciona en el primer cuarto de la lista (ruta)
		return true;
	}
	return false;
}

Cuarto* Dungeon::cuartoActualRuta() {
	if (&act) {
		return &(*act); //Act es el iterador de mi lista
	}
	else {
		return nullptr;
	}
}

bool Dungeon::avanzaRuta() {
	if (cuartoActualRuta()) {
		++act;    //Operador sobrecargado en iterador de la lista
		return true;
	}
	return false;
}
