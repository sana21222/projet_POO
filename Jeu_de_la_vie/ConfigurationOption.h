#pragma once 
#include "ConfigBase.h"
#include <string>

namespace JeuVie {

    class ConfigurationOption : public ConfigBase {
    private:
        std::string option;

        void chargerGlider(Population& population);
        void chargerBlinker(Population& population);

    public:
        ConfigurationOption(const std::string& option);
        bool charger(Population& population) override;
    };

}