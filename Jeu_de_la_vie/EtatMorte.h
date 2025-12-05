#pragma once
#include "Etat.h"
namespace JeuVie {
	class EtatMorte : public Etat {
	public:
		bool estVivante() const override;
		Etat* evoluer(int nbVoisinsVivants) const override;
		void afficher() const override;
		Etat* clone() const override;
	};
}
