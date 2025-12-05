#pragma once
namespace JeuVie {
	class Etat {
	public:
		virtual bool estVivante() const = 0;
		virtual Etat* evoluer(int nbVoisinsVivants) const = 0;
		virtual void afficher() const = 0;
		virtual Etat* clone() const = 0;
		virtual ~Etat() {}
	};
}
