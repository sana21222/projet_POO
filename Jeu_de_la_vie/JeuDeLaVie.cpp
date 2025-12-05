#include "JeuDeLaVie.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace JeuVie {

    JeuDeLaVie::JeuDeLaVie() : population(nullptr), config(nullptr) {}

    JeuDeLaVie::~JeuDeLaVie() {
        delete population;
        // Note: config est géré par l'appelant dans le cas des configurations pré-définies
        // et créé dynamiquement pour les fichiers personnalisés
    }

    void JeuDeLaVie::initialiser(ConfigBase* cfg) {
        config = cfg;
        population = new Population(20, 10);
        if (config) {
            config->charger(*population);
        }
    }

    void JeuDeLaVie::executer(int nbGenerations) {
        for (int i = 0; i < nbGenerations; i++) {
            afficher();
            population->prochaineGeneration();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        afficher(); // Afficher la dernière génération
    }

    void JeuDeLaVie::afficher() const {
        if (population) {
            population->afficher();
        }
    }

}
