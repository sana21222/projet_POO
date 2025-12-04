#pragma once 
#include "ConfigBase.h"
#include <string>

namespace JeuVie {

class ConfigurationFichier : public ConfigBase {
private:
    std::string nomFichier;

public:
    ConfigurationFichier(const std::string& nomFichier);
    bool charger(Population& population) override;
};

}
