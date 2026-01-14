#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string name;
    float damage;
    float weight;

public:
    Weapon(std::string n, float d, float w);
    Weapon();
    
    ~Weapon();
    
    std::string getName();
    float getDamage();
    float getWeight();

    bool isTooHeavy(float maxWeight);
    float totalWeight(Weapon other);
    float totalWeight(float otherWeight);
};

#endif
