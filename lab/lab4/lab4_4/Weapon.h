#pragma once
#include <string>

class Characteristic;

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

    void setDamage(float newDamage);
    
    friend class Characteristic;
};
