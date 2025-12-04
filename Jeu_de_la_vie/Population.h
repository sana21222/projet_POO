#pragma once
#include "GridBase.h"
#include "Cellule.h"
#include <vector>
#include <iostream>

namespace JeuVie {
	class Population : public GridBase {
	private:
		std::vector<std::vector<Cellule*>> grille;
		int generation;
		int CompterVoisinsVivants(int x, int y) const;
	public:
		Population(int largeur, int hauteur);
		~Population();
		Cellule* getCellule(int x, int y) const;
		void setCellule(int x, int y, bool vivante);
		void afficher() const override;
		void prochaineGeneration();
		int getGeneration() const;
	};
}
