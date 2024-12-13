#pragma once
#include <iostream>
using namespace std;

template <typename T>
class NodoCola {
public:
	T dato;
	NodoCola<T>* next;

	NodoCola(T dato): dato(dato), next(nullptr) {}
};

template <typename T>
class Queue {
public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	~Queue() {
	}

	bool enqueue(T dato) {
		NodoCola<T>* nuevo = nullptr;
		nuevo = new(nothrow) NodoCola<T>(dato);
		if (!nuevo) {
			return false;
		}
		nuevo->dato = dato;
		if (!rear) {
			front = nuevo;
			rear = nuevo;
			return true;
		}
		rear->next = nuevo;
		rear = nuevo;
		return true;
	}

	bool dequeue() {
		if (!front) {
			return false;
		}
		NodoCola<T>* tmp = front;
		front = front->next;
		if (!front) {
			rear = nullptr;
		}
		tmp->next = nullptr;
		delete tmp;
		return true;
	}

	T* peek_getFront() {
		if (!front) {
			return nullptr;
		}
		else {
			return &front->dato;
		}
	}

	bool isEmpty() {
		return front == nullptr;
	}

	void imprimir() {
		NodoCola<T>* act = front;
		while (act) {
			cout << act->dato << " ";
			act = act->next;
		}
		cout << endl;
	}

private:
	NodoCola<T>* front;
	NodoCola<T>* rear;
};
