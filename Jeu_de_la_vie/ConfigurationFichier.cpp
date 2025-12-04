#include "ConfigurationFichier.h"
#include <fstream>
#include <iostream>

namespace JeuVie {

ConfigurationFichier::ConfigurationFichier(const std::string& nomFichier) 
    : nomFichier(nomFichier) {}

bool ConfigurationFichier::charger(Population& population) {
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur: impossible d'ouvrir " << nomFichier << std::endl;
        return false;
    }

    int x, y;
    while (fichier >> x >> y) {
        population.setCellule(x, y, true);
    }

    fichier.close();
    return true;
}

}
