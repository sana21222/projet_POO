#include "Population.h"
#include "EtatVivante.h"
#include "EtatMorte.h"
#include <iostream>

namespace JeuVie {

Population::Population(int largeur, int hauteur) 
    : GridBase(largeur, hauteur), generation(0) {
    
    // Utilisation de vector (STL)
    grille.resize(hauteur);
    for (int i = 0; i < hauteur; i++) {
        grille[i].resize(largeur);
        for (int j = 0; j < largeur; j++) {
            grille[i][j] = new Cellule(j, i);
        }
    }
}

Population::~Population() {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            delete grille[i][j];
        }
    }
}

void Population::afficher() const {
    std::cout << "=== Génération " << generation << " ===" << std::endl;
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            std::cout << grille[i][j]->afficher() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Population::prochaine_generation() {
    // Création d'une grille temporaire pour stocker les nouveaux états
    std::vector<std::vector<Etat*>> nouveauxEtats(hauteur);
    
    for (int i = 0; i < hauteur; i++) {
        nouveauxEtats[i].resize(largeur);
        for (int j = 0; j < largeur; j++) {
            int nbVoisins = compterVoisinsVivants(j, i);
            nouveauxEtats[i][j] = grille[i][j]->getEtat()->evoluer(nbVoisins);
        }
    }
    
    // Mise à jour de la grille
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            grille[i][j]->changerEtat(nouveauxEtats[i][j]);
        }
    }
    
    generation++;
}

int Population::compterVoisinsVivants(int x, int y) const {
    int count = 0;
    
    // Parcours des 8 cellules adjacentes (voisinage de Moore)
    // Directions : horizontales, verticales et diagonales
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            // Ignorer la cellule elle-même
            if (dx == 0 && dy == 0) continue;
            
            int nx = x + dx;
            int ny = y + dy;
            
            // Vérification des limites de la grille
            if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                if (grille[ny][nx]->estVivante()) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

void Population::setCellule(int x, int y, bool vivante) {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        if (vivante) {
            grille[y][x]->changerEtat(new EtatVivante());
        } else {
            grille[y][x]->changerEtat(new EtatMorte());
        }
    }
}

Cellule* Population::getCellule(int x, int y) const {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        return grille[y][x];
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Population& p) {
    p.afficher();
    return os;
}

}
