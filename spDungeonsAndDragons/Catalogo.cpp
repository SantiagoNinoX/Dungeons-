#include <iostream>
#include <ctime>
#include "Catalogo.h"
using namespace std;

unsigned int Catalogo:: contarMonstruosenCSV(const string& fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de creaturas: " << fileName << endl;
        return -1;
    }

    if (!getline(file, line)) {
        cerr << "El archivo de creaturas no tiene header" << endl;
        file.close();
        return -1;
    }

    while (getline(file, line)) {
        lineCount++;
    }

    file.close();
    return lineCount;
}

bool Catalogo::loadFromCSV(const string& filename) {
    ifstream        file(filename);
    string          line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de creaturas: " << filename << endl;
        return false;
    }

    if (!getline(file, line)) {
        cerr << "El archivo de creaturas no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo de creaturas: " << filename << endl;

    while (getline(file, line)) {
        Monstruo        nMonstruo;   //Obj monstruo auxiliar
        stringstream    ss(line);
        string          cell;
        int             campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.length())
                errores++;

            switch (campo) {
            case 0:
                nMonstruo.setName(cell);
                break;
            case 1:
                nMonstruo.setCr(stod(cell));
                break;
            case 2:
                nMonstruo.setType(cell);
                break;
            case 3:
                nMonstruo.setSize(cell);
                break;
            case 4:
                nMonstruo.setAc(stoi(cell));
                break;
            case 5:
                nMonstruo.setHp(stoi(cell));
                break;
            case 6:
                nMonstruo.setAlign(cell);
                break;
            default:
                errores++;
                break;
            }
            campo++;
        }

        if (errores) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();
            return false;
        }

        if (!catalog.inserta(nMonstruo)) {
            cerr << "Error al generar el catalogo" << endl;
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

Monstruo* Catalogo::getRandomMonster() {
    unsigned int indiceAleatorio = rand() % contadorDeMonstruos;
    return catalog.buscarPorIndice(indiceAleatorio);  
}