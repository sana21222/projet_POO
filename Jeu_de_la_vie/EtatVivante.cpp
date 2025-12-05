@@ -3,18 +3,21 @@
#include <iostream>

namespace JeuVie {
	bool EtatVivante::estVivante() {
	bool EtatVivante::estVivante() const {
		return true;
	}
	Etat* evoluer(int nbVoisins) {
	Etat* EtatVivante::evoluer(int nbVoisinsVivants) const {
		if (nbVoisins == 2 || nbVoisins == 3) {
			return new EtatVivante();
		}
		else {
			return new EtatMorte();
		}
	}
	void EtatVivante::afficher() {
	void EtatVivante::afficher() const {
		std::cout << "X";
	}
	Etat* EtatVivante::clone() const {
		return new EtatVivante();
	}
} 
