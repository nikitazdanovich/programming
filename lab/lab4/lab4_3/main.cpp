#include <iostream>
#include "Weapon.h"

int main() {
    Weapon weapon1("Топор", 12.0f, 6.0f);
    Weapon weapon2;
    
    std::cout << "Оружие 1: " << weapon1.getName() 
              << ", Урон: " << weapon1.getDamage() 
              << ", Вес: " << weapon1.getWeight() << std::endl;
    
    std::cout << "Оружие 2: " << weapon2.getName() 
              << ", Урон: " << weapon2.getDamage() 
              << ", Вес: " << weapon2.getWeight() << std::endl;
    
    float maxWeight = 5.0f;
    std::cout << "Топор слишком тяжел для веса " << maxWeight 
              << "? " << (weapon1.isTooHeavy(maxWeight) ? "Да" : "Нет") 
              << std::endl;
    
    float extra = 2.0f;
    std::cout << "Сумма весов Топора и " << extra 
              << " кг: " << weapon1.totalWeight(extra) << " кг" << std::endl;
    
    std::cout << "Сумма весов Топора и Меча: " 
              << weapon1.totalWeight(weapon2) << " кг" << std::endl;

    Weapon* dynamicWeapon = new Weapon("Лук", 8.0f, 2.5f);
    std::cout << "Динамическое оружие: " << dynamicWeapon->getName() << std::endl;

    delete dynamicWeapon;
    
    std::cout << "\nВыход из программы..." << std::endl;
    return 0;
}
