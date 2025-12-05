#include "ConfigurationOption.h"

namespace JeuVie {

    ConfigurationOption::ConfigurationOption(const std::string& option)
        : option(option) {
    }

    bool ConfigurationOption::charger(Population& population) {
        if (option == "glider") {
            chargerGlider(population);
            return true;
        }
        else if (option == "blinker") {
            chargerBlinker(population);
            return true;
        }
        return false;
    }

    void ConfigurationOption::chargerGlider(Population& population) {
        // Pattern Glider
        population.setCellule(1, 0, true);
        population.setCellule(2, 1, true);
        population.setCellule(0, 2, true);
        population.setCellule(1, 2, true);
        population.setCellule(2, 2, true);
    }

    void ConfigurationOption::chargerBlinker(Population& population) {
        // Pattern Blinker (oscillateur période 2)
        population.setCellule(1, 1, true);
        population.setCellule(2, 1, true);
        population.setCellule(3, 1, true);
    }

}