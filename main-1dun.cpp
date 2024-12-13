#include <iostream>
#include "catalogo.h"
#include "dungeon.h"

using namespace std;

int main() {
    Catalogo    miCatalogo;
    Dungeon     miDungeon;

    if(!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    cout << "Creando Dungeon..." << endl;
    if(!miDungeon.createDungeon("dungeon.txt")) {
        cout << "No se pudo crear el Dungeon" << endl;
        return 0;
    }

    for(unsigned int c = 0; c < miDungeon.getSize(); c ++) {
        Monster *pMonster = nullptr, copiaMonstruo;

        pMonster = miCatalogo.getRandomMonster();
        if(!pMonster) {
            cout << "No se pudo obtener un monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if(!miDungeon.createRoom(c, copiaMonstruo)) {
            cout << "No se pudo insertar cuarto con monstruo al calabozo" << endl;
            return 0;
        }
    }

    miDungeon.imprimeCuartos();
    
    return 0;
}