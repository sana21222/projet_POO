#include "EtatVivante.h"
#include "EtatMorte.h"
#include <iostream>

namespace JeuVie {
	bool EtatVivante::estVivante() {
		return true;
	}
	Etat* evoluer(int nbVoisins) {
		if (nbVoisins == 2 || nbVoisins == 3) {
			return new EtatVivante();
		}
		else {
			return new EtatMorte();
		}
	}
	void EtatVivante::afficher() {
		std::cout << "X";
	}
} 
