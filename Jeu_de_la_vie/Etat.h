#pragma once

namespace JeuVie {
	class Etat {
	public: 
		virtual bool estVivante(int x, int y) const = 0;
		virtual int getLargeur() const = 0;
		virtual int getHauteur() const = 0;
		virtual ~Etat() {}
	};
}

// pour etat on a qu'un .h car c'est une classe abstraite
