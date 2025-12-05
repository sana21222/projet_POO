#include "EtatMorte.h"
#include "EtatVivante.h"
#include <iostream>

namespace JeuVie {
	bool EtatMorte::estVivante() {
	bool EtatMorte::estVivante() const {
		return false;
	}
	Etat* EtatMorte::evoluer(int nbVoisinsVivants) const {
		if (nbVoisinsVivants == 3) {
			return new EtatVivante();
		}
		else {
			return new EtatMorte();
		}
	}
	void EtatMorte::afficher() const {
		std::cout << ".";
	}
	Etat* EtatMorte::clone() const {
		return new EtatMorte();
	}
}
