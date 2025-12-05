#pragma once
namespace JeuVie {
	class GridBase {
	protected:
		int largeur;
		int hauteur;
	public:
	GridBase(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {}
	virtual ~GridBase() = default;
	int getLargeur() const;
	int getHauteur() const;
	void afficher() const;
	void prochaineGeneration();
	virtual void afficher() const = 0;
	};
}
