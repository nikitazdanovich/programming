#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
    string name;
    float damage;
    float weight;

public:
    // Конструкторы
    Weapon(string n, float d, float w) {
        name = n;
        damage = d;
        weight = w;
    }

    Weapon() : Weapon("Меч", 7.5f, 3.5f) {}

    // Деструктор
    ~Weapon() {
        cout << "Удаление оружия: " << name 
             << " (Урон: " << damage 
             << ", Вес: " << weight << ")" << endl;
    }

    string getName() { return name; }
    float getDamage() { return damage; }
    float getWeight() { return weight; }

    bool isTooHeavy(float maxWeight) {
        return weight > maxWeight;
    }

    float totalWeight(Weapon other) {
        return totalWeight(other.weight);
    }

    float totalWeight(float otherWeight) {
        return weight + otherWeight;
    }
};

int main() {
    Weapon weapon1("Топор", 12.0f, 6.0f);
    
    cout << "Оружие 1:" << endl;
    cout << "Название: " << weapon1.getName() << endl;
    cout << "Урон: " << weapon1.getDamage() << endl;
    cout << "Вес: " << weapon1.getWeight() << endl;

    // Динамический объект
    Weapon* weapon2 = new Weapon("Лук", 8.0f, 2.5f);
    
    cout << "Динамическое оружие:" << endl;
    cout << "Название: " << weapon2->getName() << endl;
    cout << "Урон: " << weapon2->getDamage() << endl;
    cout << "Вес: " << weapon2->getWeight() << endl;
    
    // Проверка веса
    float maxWeight = 5.0f;
    cout << "Может ли персонаж поднять " << weapon1.getName() 
         << " (вес " << weapon1.getWeight() << ")? " 
         << (weapon1.isTooHeavy(maxWeight) ? "Нет, слишком тяжело" : "Да, может") 
         << endl;

    float extraWeight = 2.0f;
    cout << "Общий вес " << weapon1.getName() 
         << " и " << extraWeight << " кг: " 
         << weapon1.totalWeight(extraWeight) << " кг" << endl;

    Weapon weapon3("Щит", 3.0f, 4.0f);
    cout << "Общий вес " << weapon1.getName() 
         << " и " << weapon3.getName() << ": " 
         << weapon1.totalWeight(weapon3) << " кг" << endl;
    
    delete weapon2;
    return 0;
}
