#pragma once
#include "Population.h"

namespace JeuVie {

class ConfigBase {
public:
    virtual ~ConfigBase() = default;
    virtual bool charger(Population& population) = 0;
};

}
