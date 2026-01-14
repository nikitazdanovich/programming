#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
    string name;
    float damage;
    float weight;

public:
    Weapon(string n, float d, float w) {
        name = n;
        damage = d;
        weight = w;
    }

    // Конструктор без параметров
    Weapon() : Weapon("Меч", 7.5f, 3.5f) {}

    string getName() { return name; }
    float getDamage() { return damage; }
    float getWeight() { return weight; }
};

int main() {
    // Создаём 2 объекта
    Weapon weapon1("Нож", 5.0f, 0.5f);
    Weapon weapon2;
    
    // Выводим значения
    cout << "Оружие 1:" << endl;
    cout << "Название: " << weapon1.getName() << endl;
    cout << "Урон: " << weapon1.getDamage() << endl;
    cout << "Вес: " << weapon1.getWeight() << endl;
    
    cout << "\nОружие 2:" << endl;
    cout << "Название: " << weapon2.getName() << endl;
    cout << "Урон: " << weapon2.getDamage() << endl;
    cout << "Вес: " << weapon2.getWeight() << endl;
    
    return 0;
}
