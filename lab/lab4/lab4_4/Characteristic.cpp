#include "Characteristic.h"

Characteristic::Characteristic(float s) : strength(s) {}

float Characteristic::GetDamage(Weapon w)
{
    return w.getDamage() + strength;
}
