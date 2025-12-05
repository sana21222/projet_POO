#include "EtatVivante.h"
#include "EtatMorte.h"
#include <iostream>

namespace JeuVie {
	bool EtatVivante::estVivante() const {
		return true;
	}

	Etat* EtatVivante::evoluer(int nbVoisinsVivants) const {
		if (nbVoisinsVivants == 2 || nbVoisinsVivants == 3) {
			return new EtatVivante();
		}
		else {
			return new EtatMorte();
		}
	}

	void EtatVivante::afficher() const {
		std::cout << "X";
	}

	Etat* EtatVivante::clone() const {
		return new EtatVivante();
	}
}
