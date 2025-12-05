#include "JeuDeLaVie.h"
#include "ConfigurationFichier.h"
#include "ConfigurationOption.h"
#include <iostream>
#include <map>
using namespace JeuVie;
int main() {
    // Utilisation de map (STL)
    std::map<std::string, ConfigBase*> configurations;
    configurations["glider"] = new ConfigurationOption("glider");
    configurations["blinker"] = new ConfigurationOption("blinker");
    JeuDeLaVie jeu;
    std::cout << "Choisissez une configuration:" << std::endl;
    std::cout << "1. Glider" << std::endl;
    std::cout << "2. Blinker" << std::endl;
    std::cout << "3. Fichier personnalisé" << std::endl;
    int choix;
    std::cin >> choix;
    ConfigBase* config = nullptr;
    switch(choix) {
        case 1:
            config = configurations["glider"];
            break;
        case 2:
            config = configurations["blinker"];
            break;
        case 3: {
            std::cout << "Nom du fichier: ";
            std::string nomFichier;
            std::cin >> nomFichier;
            config = new ConfigurationFichier(nomFichier);
            break;
        }
        default:
            std::cout << "Choix invalide, utilisation du glider par défaut" << std::endl;
            config = configurations["glider"];
            break;
    }

    jeu.initialiser(config);
    jeu.executer(20);
    
    if (configFromFile) {
        delete config;
    }
    
    for (auto& pair : configurations) {
        delete pair.second;
    }
    return 0;
}
