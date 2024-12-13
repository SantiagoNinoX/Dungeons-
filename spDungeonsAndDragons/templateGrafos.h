#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TemplateListasDobles.h"   //Grafo contiene ListasDobles
#include "TemplateStack.h"
#include "TemplateQueue.h"
#define UINT_MAX 0xFFFFFFFF

using namespace std;


template <typename T>
class Vertice {
public:
	T dato;
	ListaDoble<unsigned int> edges;
	bool visited;
	Vertice() : dato(T()), visited(false) {}  // Inicializar dato con su valor predeterminado

};

template <typename T>
class Grafo {
public:
	Grafo() { vertices = nullptr; size = 0, previous = nullptr; }

	~Grafo() { borrarGrafo(); }

	bool crearGrafo(unsigned int nSize) {
		if (nSize == 0 || vertices || previous) {
			return false;
		}
		vertices = new(nothrow) Vertice<T>[nSize];
		if (!vertices) {
			return false;
		}
		size = nSize;
		previous = new(nothrow) unsigned int[nSize];
		if (!previous) {
			return false;
		}
		for (unsigned int o = 0; o < nSize; o++) {
			previous[o] = UINT_MAX;
		}
		return true;
	}

	bool setVertex(unsigned int vertex, T data) {   //Asignar dato al vertice de cierto index
		if (!size || vertex >= size) {
			return false;
		}
		vertices[vertex].dato = data;
		return true;
	}

	T* getVertexData(unsigned int index) {
		if (index >= size) {
			return nullptr;
		}
		return &vertices[index].dato; 
	}

	bool insertarArista(unsigned int fuente, unsigned int destino) {
		if (!vertices) {
			return false;
		}
		if (fuente >= size || destino >= size) {
			return false;
		}
		if (vertices[fuente].edges.busquedaDoble(destino)) {
			return false;
		}
		if (!vertices[fuente].edges.insertaFinalDoble(destino)) {
			return false;
		}
		return true;
	}

	bool eliminarArista(unsigned int fuente, unsigned int destino) {
		if (!vertices) {
			return false;
		}
		if (fuente >= size || destino >= size) {
			return false;
		}
		if (!vertices[fuente].edges.busquedaDoble(destino)) {
			return false;
		}
		if (vertices[fuente].edges.deleteElementoDoble(destino)) {
			return true;
		}
		return false;
	}

	void borrarGrafo() {
		if (!size) {
			return;
		}
		if (vertices) {
			delete[] vertices;
			vertices = nullptr;
			size = 0;
		}
		if (previous) {
			delete[] previous;
			previous = nullptr;
		}
	}

	void imprimirGrafo() {
		for (unsigned int i = 0; i < size; i++) {
			cout << "[" << i << "]" << vertices[i].dato << ": ";
			vertices[i].edges.imprimeListaDoble();
		}
		cout << endl;
	}

	bool cargarArchivo(const string& filename) {
		ifstream        file;
		string          line;
		unsigned int vertex = 0, nSize = 0;

		file.open(filename, ios::in);
		if (!file.is_open()) {
			cerr << "Error al abrir el archivo: " << filename << endl;
			return false;
		}
		if (!getline(file, line)) {
			cout << "Sin header" << endl;
			file.close();
			return false;
		}
		if (line != "Grafo") {
			file.close();
			return false;
		}
		if (!getline(file, line)) {  //Cantidad de vertices
			cout << "Sin tamaño de grafo" << endl;
			file.close();
			return false;
		}
		if (!isValidNumeric(line)) {
			cout << "Tamaño de grafo no es numerico" << endl;
			file.close();
			return false;
		}
		nSize = stoi(line);
		if (nSize <= 0) {
			cout << "Tamaño de grafo incorrecto" << endl;
			file.close();
			return false;
		}
		borrarGrafo();   //Borrar grafo actual
		if (!crearGrafo(nSize)) {   //Crear nuevos vertices, nuevo grafo
			cout << "No se pudo crear el grafo" << endl;
			file.close();
			return false;
		}
		for (vertex = 0; vertex < size; vertex++) {
			if (!getline(file, line)) {  //Aristas
				cout << "Sin aristas" << endl;
				file.close();
				return false;
			}
			if (line.length()) {    //Si hay contenido en el vertice
				stringstream ss(line);
				string cell;
				while (getline(ss, cell, ' ')) {
					int destino = 0;
					if (!isValidNumeric(cell)) {
						file.close();
						return false;
					}
					destino = stoi(cell);
					if (!insertarArista(vertex, destino)) {
						file.close();
						return false;
					}
				}
			}
		}
		file.close();
		return true;
	}

	bool guardarArchivo(const string& filename) {
		ofstream file;
		if (!size) {
			return false;
		}
		file.open(filename, ios::out);
		if (!file.is_open()) {
			cerr << "Error al guardar el archivo: " << filename << endl;
			return false;
		}
		file << "Grafo" << endl;    //Encabezado
		file << size << endl;       //Cantidad de vertices
		for (unsigned int i = 0; i < size; i++) {
			ListaDoble<unsigned int>::iterator j(nullptr);
			for (j = vertices[i].edges.begin(); j != vertices[i].edges.end(); ++j) {
				file << *j << " ";
			}
			file << endl;
		}
		file.close();
		return true;
	}

	void DFS_recursivo(unsigned int vertex) {
		vertices[vertex].visited = true;
		cout << vertex << " ";    //Segun el orden del stack y como lo quiero imprimir
		ListaDoble<unsigned int>::iterator i(nullptr);
		for (i = vertices[vertex].edges.begin(); i != vertices[vertex].edges.end(); ++i) {
			if (!vertices[*i].visited) {
				DFS_recursivo(*i);
			}
		}
		//cout << vertex << " ";

	}

	bool DFS_iterativo(unsigned int vertex) {
		if (!size || vertex >= size) {
			return false;
		}
		inicializarVisited();
		Stack<unsigned int> pila;
		pila.push(vertex);
		cout << "DFS (" << vertex << "): ";
		while (!pila.isEmpty()) {
			unsigned int verticeactual = *pila.getTop();
			pila.pop();
			if (!vertices[verticeactual].visited) {
				vertices[verticeactual].visited = true;
				cout << verticeactual << " ";
				ListaDoble<unsigned int>::iterator it = vertices[verticeactual].edges.begin();
				while (it != vertices[verticeactual].edges.end()) {
					if (!vertices[*it].visited) {
						pila.push(*it);
					}
					++it;
				}
			}
		}
		cout << endl;
		return true;
	}

	bool BFS(unsigned int vertexInicio) {
		Queue<unsigned int> cola;
		if (!size || vertexInicio >= size) {
			return false;
		}
		inicializarVisited();
		//cout << "BFS (" << vertexInicio << "): ";   //Ahorita mejor no imprimimos para el proyecto
		if (!cola.enqueue(vertexInicio)) {
			return false;
		}
		vertices[vertexInicio].visited = true;   //Optimizacion
		while (!cola.isEmpty()) {
			unsigned int verticeAct = *cola.peek_getFront();
			//cout << verticeAct << " ";
			cola.dequeue();
			for (auto arista : vertices[verticeAct].edges) {
				if (!vertices[arista].visited) {
					if (!cola.enqueue(arista)) {
						return false;
					}
					vertices[arista].visited = true;
					previous[arista] = verticeAct;

				}
			}
		}
		cout << endl;
		return true;
	}

	void printPath(unsigned int vertexFinal) {   //para BFS entre 2 vertices
		ListaDoble<unsigned int> camino;
		unsigned int act = vertexFinal;
		while (act != UINT_MAX) {
			if (!camino.insertaInicioDoble(act)) {
				return;
			}
			act = previous[act];
		}
		camino.imprimeListaDoble();
	}

	bool printPathBFS(unsigned int vertexInicial, unsigned int vertexFinal, ListaDoble<T> &path) { 
		ListaDoble<unsigned int> camino;  //Lista para los indices de vertices, solo la uso al imprimir
		if (!BFS(vertexInicial)) {   //Inicializar recorrido BFS
			return false;
		}
		unsigned int curr = vertexFinal;
		while (curr != UINT_MAX) {
			T* dato = getVertexData(curr);
			if (!dato) {
				return false;
			}
			if (!path.insertaInicioDoble(*dato)) {  //path es la ruta de objetos
				return false;
			}
			if (!camino.insertaInicioDoble(curr)) {
				return false;
			}
			curr = previous[curr];
		}
		//path.imprimeListaDoble();    //Ahorita no necesitamos imprimir los objetos cuarto
		camino.imprimeListaDoble();   //Imprimo indices
		return true;
	}

	unsigned int getSizeGrafo() {
		return size;
	}

private:
	Vertice<T>* vertices;
	unsigned int size;
	unsigned int* previous;

	bool isValidNumeric(const string& str) {
		for (char c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

	void inicializarVisited() {
		for (unsigned int i = 0; i < size; i++) {
			vertices[i].visited = false;
		}
	}
};
