#pragma once
#include "Weapon.h"

class Characteristic {
private:
    float strength;

public:
    Characteristic(float s);
    float GetDamage(Weapon w);
};
