#include "Cellule.h"
#include "EtatMorte.h"
#include <iostream>

namespace JeuVie {
	Cellule::Cellule(int x, int y) : x(x), y(y) {
		etat = new EtatMorte();
	}
	Cellule::~Cellule() {
		delete etat;
	}
	Cellule::Cellule(const Cellule& other) : x(other.x), y(other.y) {
		etat = other.etat->clone();
	}
	Cellule& Cellule::operator=(const Cellule& other) {
		if (this != &other) {
			delete etat;
			x = other.x;
			y = other.y;
			etat = other.etat->clone();
		}
		return *this;
	}
	bool Cellule::estVivante() const {
		return etat->estVivante();
	}
	void Cellule::changerEtat(Etat* nouvelEtat) {
		delete etat;
		etat = nouvelEtat;
	}
	Etat* Cellule::getEtat() const {
		return etat;
	}
	int Cellule::getX() const {
		return x;
	}
	int Cellule::getY() const {
		return y;
	}
	void Cellule::afficher() const {
		etat->afficher();
	}
	Cellule Cellule::evoluer(int nbVoisinsVivants) const {
		Cellule nouvelleCellule(x, y);
		nouvelleCellule.changerEtat(etat->evoluer(nbVoisinsVivants));
		return nouvelleCellule;
	}
}