#include "Weapon.h"
#include <iostream>

Weapon::Weapon(std::string n, float d, float w) {
    name = n;
    damage = d;
    weight = w;
}

Weapon::Weapon() : Weapon("Меч", 7.5f, 3.5f) {}

Weapon::~Weapon() {
    std::cout << "Удаление оружия: " << name 
              << " (Урон: " << damage 
              << ", Вес: " << weight << ")" << std::endl;
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

bool Weapon::isTooHeavy(float maxWeight) {
    return weight > maxWeight;
}

float Weapon::totalWeight(Weapon other) {
    return totalWeight(other.weight);
}

float Weapon::totalWeight(float otherWeight) {
    return weight + otherWeight;
}
