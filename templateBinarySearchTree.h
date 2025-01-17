#pragma once
#include <iostream>
#include "TemplateQueue.h"
using namespace std;

template <typename T>
class NodoArbol {
public:
	T dato;
	NodoArbol<T>* left;
	NodoArbol<T>* right;
	NodoArbol(T dato) : dato(dato), left(nullptr), right(nullptr) {}
};

template <typename T>
class ArbolBinario {
private:
	NodoArbol<T>* root;

	T* buscarRecursivo(NodoArbol<T>* actual, T dato) {
		if (!actual) {
			return nullptr;
		}
		if (dato < actual->dato) {
			return buscarRecursivo(actual->left, dato);
		}
		else if (dato > actual->dato) {
			return buscarRecursivo(actual->right, dato);
		}
		return &actual->dato;
	}

	bool insertaRecursivo(NodoArbol<T>*& nodo, T dato) {
		if (!nodo) {
			nodo = new(nothrow) NodoArbol<T>(dato);
			if (!nodo) {
				return false;
			}
			return true;
		}
		if (dato < nodo->dato) {
			return insertaRecursivo(nodo->left, dato);
		}
		else if (dato > nodo->dato) {
			return insertaRecursivo(nodo->right, dato);
		}
		return false;
	}

	void recorridoInOrder(NodoArbol<T>* act) {   //IZQ -> RAIZ -> DER
		if (!act) {
			return;
		}
		recorridoInOrder(act->left);
		cout << act->dato << " ";
		recorridoInOrder(act->right);
	}

	void recorridoPreOrder(NodoArbol<T>* act) {   //RAIZ -> IZQ -> DER
		if (!act) {
			return;
		}
		cout << act->dato << " ";
		recorridoPreOrder(act->left);
		recorridoPreOrder(act->right);
	}

	void recorridoPostOrder(NodoArbol<T>* act) {    //IZQ -> DER -> RAIZ
		if (!act) {
			return;
		}
		recorridoPostOrder(act->left);
		recorridoPostOrder(act->right);
		cout << act->dato << " ";
	}

	NodoArbol<T>* buscaMinRight(NodoArbol<T>* nodo) {
		NodoArbol<T>* minRight = nullptr;
		NodoArbol<T>* parent = nullptr;
		parent = nodo;
		minRight = nodo->right;
		while (minRight->left) {
			parent = minRight;
			minRight = minRight->left;
		}
		nodo->dato = minRight->dato;
		if (parent == nodo) {
			parent->right = minRight->right;
		}
		else {
			parent->left = minRight->right;
		}
		return minRight;
	}

	bool eliminaRecursivo(NodoArbol<T>*& act, T dato) {   
		if (!act) {
			return false;
		}
		if (dato < act->dato) {
			return eliminaRecursivo(act->left, dato);
		}
		if (dato > act->dato) {
			return eliminaRecursivo(act->right, dato);
		}
		if (act->left && act->right) {
			NodoArbol<T>* sustituto = buscaMinRight(act);
			delete sustituto;
			sustituto = nullptr;
			return true;
		}
		else if (!act->left && act->right) {
			NodoArbol<T>* temp = act;
			act = act->right;
			delete temp;
			temp = nullptr;
			return true;
		}
		else if (!act->right && act->left) {
			NodoArbol<T>* temp = act;
			act = act->left;
			delete temp;
			temp = nullptr;
			return true;
		}
		delete act;
		act = nullptr;
		return true;
	}

public:
	ArbolBinario() {
		root = nullptr;
	}

	~ArbolBinario() {
		borrarArbol();
	}

	bool borrarArbol() {
		return deleteBST(&root);
	}

	bool deleteBST(NodoArbol<T>** nodo) {
		if (*nodo) {
			deleteBST(&(*nodo)->left);
			deleteBST(&(*nodo)->right);
			delete* nodo;
			*nodo = nullptr;
			return true;
		}
	}

	T* buscar(T dato) {
		return buscarRecursivo(root, dato);
	}

	bool inserta(T dato) {
		return insertaRecursivo(root, dato);
	}

	void printInOrder() {
		cout << endl;
		return recorridoInOrder(root);
		cout << endl;
	}

	void printPreOrder() {
		cout << endl;
		return recorridoPreOrder(root);
		cout << endl;
	}

	void printPostOrder() {
		cout << endl;
		return recorridoPostOrder(root);
		cout << endl;
	}

	bool eliminarNodo(T dato) {
		return eliminaRecursivo(root, dato);
	}

	void printBFS() {
		Queue<NodoArbol<T>*> colaImpresion;
		if (!root) {
			return;
		}
		colaImpresion.enqueue(root);
		while (!colaImpresion.isEmpty()) {
			NodoArbol** tmp = colaImpresion.peek_getFront();
			NodoArbol* act = *tmp;
			colaImpresion.dequeue();
			cout << act->dato << " ";
			if (act->left) {
				colaImpresion.enqueue(act->left);
			}
			if (act->right) {
				colaImpresion.enqueue(act->right);
			}

		}
		cout << endl;
	}

};