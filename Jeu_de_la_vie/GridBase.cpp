#include "GridBase.h"
#include <iostream>

namespace JeuVie {
	GridBase::GridBase(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {}
	int GridBase::getLargeur() const {
		return largeur;
	}
	int GridBase::getHauteur() const {
		return hauteur;
	}
}
