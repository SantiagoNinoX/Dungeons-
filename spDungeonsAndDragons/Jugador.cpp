#include <iostream>
#include "Jugador.h"
using namespace std;

void Jugador::setUser(string user) {
	username = user;
}

string Jugador::getUser() {
	return username;
}

void Jugador::setRace(string raza) {
	race = raza;
}

string Jugador::getRace() {
	return race;
}

void Jugador::setHp(int Hp) {
	hp = Hp;
}

int Jugador::getHp() {
	return hp;
}

void Jugador::setMp(int Mp) {
	mp = Mp;
}

int Jugador::getMp() {
	return mp;
}

void Jugador::imprimirJugador() {
	cout << "hp: " << hp << endl;
	cout << "race: " << race << endl;
	cout << "username: " << username << endl;
	cout << "mp: " << mp << endl;
}

void Jugador::ganarBatallaHp() {  //Al ganar batalla incrementa hp
	setHp(hp + 1);
}

void Jugador::usarHechizoMp() {  //Al usar hechizo decrementa mp
	setMp(mp - 1);
}

bool Jugador::insertaMonstruosDerrotados(Monstruo& derrotado) {  //Referenciados del catalogo
	monstruosDerrotados.insertaEnOrden(derrotado);
	return true;
}

void Jugador::imprimirDerrotados() {
	monstruosDerrotados.imprimeLista();
}
