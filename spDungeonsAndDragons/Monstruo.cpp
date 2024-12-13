#include <iostream>
#include "Monstruo.h"
using namespace std;

void Monstruo::setName(string nombre) {
	name = nombre;
}

string Monstruo::getName() {
	return name;
}

void Monstruo::setCr(double Cr) {
	cr = Cr;
}

double Monstruo::getCr() {
	return cr;
}

void Monstruo::setType(string tipo) {
	type = tipo;
}

string Monstruo::getType() {
	return type;
}

void Monstruo::setSize(string tamano) {
	size = tamano;
}

string Monstruo::getSize() {
	return size;
}

void Monstruo::setAc(int Ac) {
	ac = Ac;
}

int Monstruo::getAc() {
	return ac;
}

void Monstruo::setHp(int Hp) {
	hp = Hp;
}

int Monstruo::getHp() {
	return hp;
}

void Monstruo::setAlign(string Align) {
	align = Align;
}

string Monstruo::getAlign() {
	return align;
}

void Monstruo::imprimirMonstruo() {
	cout << "Name: " << name << endl;
	cout << "cr: " << cr << endl;
	cout << "type: " << type << endl;
	cout << "size: " << size << endl;
	cout << "ac: " << ac << endl;
	cout << "hp: " << hp << endl;
	cout << "align: " << align << endl;
}

