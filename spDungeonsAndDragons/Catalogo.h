#pragma once
#include <iostream>
#include "templateBinarySearchTree.h" //Catalogo es un BST
#include "Monstruo.h"  //Catalogo contiene monstruos
#include <fstream>
#include <sstream>
using namespace std;
#define ARCHIVO "monsters.csv"   

class Catalogo {
public: 
    Catalogo() {
        srand(time(0));   //Semilla para generar numeros rand
        contadorDeMonstruos = contarMonstruosenCSV(ARCHIVO);
    }

    ~Catalogo() {
        catalog.borrarArbol();
    }

    bool loadFromCSV(const string& filename);  //Complejidad de los metodos: O(n)
    Monstruo* getRandomMonster();  
    unsigned int contarMonstruosenCSV(const string& filename);  

private:
    ArbolBinario<Monstruo> catalog;
    unsigned int contadorDeMonstruos; 
};