#pragma once
#include "etat.h"

namespace JeuVie {
	class EtatVivant : public Etat {
	public:
		bool estVivant() const override;
		Etat* evoluer(int nbVoisinsVivants) const override;
	};
} 
