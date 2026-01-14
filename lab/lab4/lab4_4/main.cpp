#include <iostream>
#include "Weapon.h"
#include "Characteristic.h"
#include "MyMath.h"

int main()
{
    Weapon sword("Меч", 7.0f, 3.5f);
    std::cout << "Оружие: " << sword.getName() 
              << ", Урон: " << sword.getDamage() 
              << ", Вес: " << sword.getWeight() << std::endl;
    
    sword.setDamage(18.0f);
    std::cout << "Новый урон: " << sword.getDamage() << std::endl;
    
    Characteristic hero(25.0f);
    std::cout << "Общий урон героя: " << hero.GetDamage(sword) << std::endl;
    
    std::cout << "\nMyMath:" << std::endl;
    std::cout << "Add(5, 3) = " << MyMath::Add(5, 3) << std::endl;
    std::cout << "Sub(8, 2) = " << MyMath::Sub(8, 2) << std::endl;
    std::cout << "Mult(4, 6) = " << MyMath::Mult(4, 6) << std::endl;
    std::cout << "Div(9, 3) = " << MyMath::Div(9, 3) << std::endl;
    std::cout << "Div(5, 0) = " << MyMath::Div(5, 0) << std::endl; // защита от 0
    
    MyMath::Add(10, 20);
    
    return 0;
}
