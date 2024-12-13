#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
	T dato;
	Nodo<T>* next;

	Nodo(T dato): dato(dato), next(nullptr) {}
};

template <typename T>
class ListaLigada {
private:
	Nodo<T>* head;
public:
	ListaLigada() {
		head = nullptr;
	}

	~ListaLigada() {
		deleteLista();
	}

	bool insertaFinal(T dato) {
		Nodo<T>* nuevo = nullptr;
		nuevo = new (nothrow) Nodo<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			return true;
		}
		Nodo<T>* tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = nuevo;
		return true;
	}

	void imprimeLista() {
		Nodo<T>* tmp = nullptr;
		tmp = head;
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void deleteLista() {
		Nodo<T>* act = nullptr;
		act = head;
		while (act) {
			Nodo<T>* tmp = act->next;
			delete act;
			act = tmp;
		}
		head = nullptr;
	}

	bool deleteElemento(T dato) {
		if (!head) {
			return false;
		}
		Nodo<T>* actual = head;
		Nodo<T>* anterior = nullptr;
		while (actual) {
			if (actual->dato == dato) {
				if (anterior) {
					anterior->next = actual->next;
				}
				else {
					head = actual->next;
				}
				delete actual;
				actual = nullptr;
				return true;
			}
			anterior = actual;
			actual = actual->next;
		}
		cout << "No está el elemento " << dato << endl;
		return false;
	}

	bool insertaAlInicio(T dato) {
		Nodo<T>* nuevo = nullptr;
		nuevo = new(nothrow) Nodo<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (head) {
			nuevo->next = head;
		}
		head = nuevo;
		return true;
	}

	bool borrarInicial() {
		if (!head) {
			return false;
		}
		Nodo<T>* inicial = head;
		head = inicial->next;
		delete inicial;
		inicial = nullptr;
		return true;
	}

	bool borrarFinal() {
		if (!head) {
			return false;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			return true;
		}
		Nodo<T>* actual = head;
		Nodo<T>* anterior = nullptr;
		while (actual->next) {
			anterior = actual;
			actual = actual->next;
		}
		anterior->next = nullptr;
		delete actual;
		actual = nullptr;
		return true;
	}

	bool insertaEnOrden(T dato) {
		Nodo<T>* nuevo = nullptr;
		nuevo = new(nothrow) Nodo<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			return true;
		}
		if (head->dato > dato) {
			nuevo->next = head;
			head = nuevo;
			return true;
		}
		Nodo<T>* tmp = head;
		while (tmp->next && tmp->next->dato < dato) {
			tmp = tmp->next;
		}
		nuevo->next = tmp->next;
		tmp->next = nuevo;
		return true;
	}

	bool busqueda(T elemento) {
		if (!head) {
			cout << "Lista vacía" << endl;
			return false;
		}
		Nodo<T>* actual = head;
		while (actual) {
			if (actual->dato == elemento) {
				cout << "El nodo en el que se encuentra " << elemento << " es " << actual << endl;
				return true;
			}
			actual = actual->next;
		}
		cout << "Elemento " << elemento << " no encontrado en la lista." << endl;
		return false;
	}

	int cuentaMenores(T dato) {
		if (!head) {
			cout << "La lista esta vacia." << endl;
			return 0;
		}
		int cont = 0;
		Nodo<T>* actual = head;
		while (actual) {
			if (actual->dato < dato) {
				cont++;
			}
			actual = actual->next;
		}
		//cout << "Elementos menores a " << dato << " son: " << cont << endl;
		return cont;
	}

};
