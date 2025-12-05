#include "Etat.h"

namespace JeuVie {
	class EtatMort : public Etat {
	class EtatMorte : public Etat {
	public:
		bool estVivant() const override;
		Etat* evoluer(int nbVoisinsVivants) const override;
		void afficher() const override;
		Etat* clone() const override;
	};
}
