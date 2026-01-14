#include "Weapon.h"
#include <iostream>

Weapon::Weapon(std::string n, float d, float w) : name(n), damage(d), weight(w) {}

Weapon::Weapon() : Weapon("Меч", 10.0f, 3.5f) {}

Weapon::~Weapon() {
    std::cout << "Удаление оружия: " << name << std::endl;
}

std::string Weapon::getName() {
    return name;
}

float Weapon::getDamage() {
    return damage;
}

float Weapon::getWeight() {
    return weight;
}

void Weapon::setDamage(float newDamage) {
    if (newDamage >= 0) {
        damage = newDamage;
    }
}
