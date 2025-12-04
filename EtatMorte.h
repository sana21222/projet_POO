#pragma once
#include "Etat.h"

namespace JeuVie {
	class EtatMort : public Etat {
	public:
		bool estVivant() const override;
		Etat* evoluer(int nbVoisinsVivants) const override;
	};
}
