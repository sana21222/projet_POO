#pragma once
#include "Population.h"
#include "ConfigBase.h"

namespace JeuVie {

    class JeuDeLaVie {
    private:
        Population* population;
        ConfigBase* config;

    public:
        JeuDeLaVie();
        ~JeuDeLaVie();

        void initialiser(ConfigBase* config);
        void executer(int nbGenerations);
        void afficher() const;
    };

}
