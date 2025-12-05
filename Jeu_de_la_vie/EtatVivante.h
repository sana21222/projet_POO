#include "etat.h"

namespace JeuVie {
	class EtatVivante : public Etat {
	class EtatVivante : public Etat {
	public:
		bool estVivant() const override;
		Etat* evoluer(int nbVoisinsVivants) const override;
		void afficher() const override;
		Etat* clone() const override;
	};
} 
