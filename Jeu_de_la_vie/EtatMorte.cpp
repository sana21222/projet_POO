#include "EtatMorte.h"
#include "EtatVivante.h"
#include <iostream>

namespace JeuVie {
	bool EtatMorte::estVivante() {
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
}
