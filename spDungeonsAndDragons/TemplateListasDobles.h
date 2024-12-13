#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodoDoble {
public:
	T dato;
	NodoDoble<T>* next;
	NodoDoble<T>* prev;

	NodoDoble(T dato) : dato(dato), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
	NodoDoble<T>* head;
	NodoDoble<T>* tail;

public:
	ListaDoble() {
		head = nullptr;
		tail = nullptr;
	}

	~ListaDoble() {
		deleteListaDoble();
	}

	unsigned int getSize() {
		unsigned int size = 0;
		NodoDoble<T>* tmp = head;
		while (tmp) {
			size++;
			tmp = tmp->next;
		}
		return size;
	}

	bool insertaFinalDoble(T dato) {
		NodoDoble<T>* nuevo = nullptr;
		nuevo = new(nothrow) NodoDoble<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			tail = nuevo;
			return true;
		}
		else {
			tail->next = nuevo;
			nuevo->prev = tail;
			tail = nuevo;
		}
		return true;
	}

	void imprimeListaDoble() {
		NodoDoble<T>* tmp = head;
		if (!tmp) {
			cout << "No hay lista" << endl;
			return;
		}
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void imprimeListaAlRevesDoble() {
		NodoDoble<T>* tmp = tail;
		if (!tmp) {
			cout << "No hay lista" << endl;
			return;
		}
		while (tmp) {
			cout << tmp->dato << " ";
			tmp = tmp->prev;
		}
		cout << endl;
	}

	void deleteListaDoble() {
		NodoDoble<T>* actual = head, * tmp = nullptr;
		while (actual) {
			tmp = actual->next;
			delete actual;
			actual = tmp;
		}
		head = nullptr;
		tail = nullptr;
	}

	bool deleteElementoDoble(T elemento) {
		if (!head) {
			return false;
		}
		NodoDoble<T>* actual = head;
		NodoDoble<T>* anterior = nullptr;
		NodoDoble<T>* siguiente = nullptr;
		while (actual) {
			if (actual->dato == elemento) {
				anterior = actual->prev;
				siguiente = actual->next;
				if (anterior && siguiente) {
					anterior->next = siguiente;
					siguiente->prev = anterior;
				}
				else if (!anterior) {
					head = siguiente;
					if (head) {
						head->prev = nullptr;
					}
				}
				else if (!siguiente) {
					tail = anterior;
					tail->next = nullptr;
				}
				delete actual;
				actual = nullptr;
				return true;
			}
			actual = actual->next;
		}
		return false;
	}

	bool insertaInicioDoble(T dato) {
		NodoDoble<T>* nuevo = nullptr;
		nuevo = new(nothrow) NodoDoble<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			tail = nuevo;
			return true;
		}
		else {
			nuevo->next = head;
			head->prev = nuevo;
			head = nuevo;
		}
		return true;
	}

	bool borrarInicialDoble() {
		if (!head) {
			return false;
		}
		NodoDoble<T>* inicial = head;
		head = inicial->next;
		if (head) {
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete inicial;
		inicial = nullptr;
		return true;
	}

	bool borrarFinalDoble() {
		if (!head) {
			return false;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		NodoDoble<T>* final = tail;
		tail = final->prev;
		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete final;
		final = nullptr;
		return true;
	}

	bool insertaEnOrdenDoble(T elemento) {
		NodoDoble<T>* tmp = nullptr, * nuevo = nullptr;
		nuevo = new(nothrow) NodoDoble<T>(elemento);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			tail = nuevo;
			return true;
		}
		if (head->dato > elemento) {
			nuevo->next = head;
			head->prev = nuevo;
			head->prev = nuevo;
			head = nuevo;
			return true;
		}
		tmp = head;
		while (tmp->next && tmp->next->dato < elemento) {
			tmp = tmp->next;
		}
		nuevo->next = tmp->next;
		nuevo->prev = tmp;
		if (tmp->next) {
			tmp->next->prev = nuevo;
		}
		else {
			tail = nuevo;
		}
		tmp->next = nuevo;
		return true;
	}

	T* busquedaDoble(T elemento) {
		if (!head) {
			return nullptr;
		}
		NodoDoble<T>* actual = head;
		while (actual) {
			if (actual->dato == elemento) {
				return &(actual->dato);
			}
			actual = actual->next;
		}
		return nullptr;
	}

	class iterator {      //Iterador para respetar encapsulamiento de Listas Dobles.
	private:
		NodoDoble<T>* current;

	public:
		iterator() : current(nullptr) {}
		iterator(NodoDoble<T>* nodo) : current(nodo) {}

		T& operator*() {
			return current->dato;
		}

		iterator& operator++() {
			if (current) {
				current = current->next;
			}
			return *this;
		}

		bool operator==(const iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const iterator& other) const {
			return current != other.current;
		}
	};

	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		return iterator(nullptr);
	}
};
