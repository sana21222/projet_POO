#pragma once
#include "Etat.h"

namespace JeuVie {
	class Cellule {
	private:
		Etat* etat;
		int x;
		int y;
	public:
		Cellule(int x, int y);
		~Cellule();
		Cellule(const Cellule& other);
		Cellule& operator=(const Cellule& other);
		bool estVivante() const;
		void changerEtat(Etat* nouvelEtat);
		Etat* getEtat() const;
		void evoluer(int nbVoisinsVivants);
		void afficher() const;
		int getX() const;
		int getY() const;
	};
}