#include <iostream>
#include <string>

using namespace std;

enum class weaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NON
};

class weapon {
private:
    weaponType type;
    string name;
    float damage, weight;
    
public:
    weapon(string tnam = "NON", float tdam = 0, float twei = 0, weaponType ttyp = weaponType::NON) {
        name = tnam;
        damage = tdam;
        weight = twei;
        type = ttyp;
    }

    ~weapon() {
        cout << "Weapon destroyed\n";
    }
    
    string getName() { return name; }
    float getDamage() { return damage; }
    float getWeight() { return weight; }
    weaponType getType() { return type; }
    
    virtual void attack() = 0;
};

struct Player {
    int id;
    string login;
    string password;
    
    void printInfo() {
        cout << "ID: " << id << endl;
        cout << "Login: " << login << endl;
        cout << "Password: " << password << endl;
    }
};

class magicWeapon : public weapon {
private:
    float addDamage; 
public:
    magicWeapon(string n, float d, float w, weaponType t, float add)
        : weapon(n, d, w, t), addDamage(add) {}
    
    magicWeapon() : magicWeapon("Magic Sword", 20, 3, weaponType::ONEHANDED, 10) {}
    
    float getAddDamage() { return addDamage; }
    
    void testParentMethods() {
        cout << "Name from parent: " << getName() << endl;
        cout << "Damage from parent: " << getDamage() << endl;
        cout << "Weight from parent: " << getWeight() << endl;
    }
    
    void attack() override {
        cout << "Magic attack!\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    magicWeapon mw;
    weaponType wt = mw.getType();
    
    cout << "Weapon type: ";
    if (wt == weaponType::ONEHANDED) {
        cout << "One-handed weapon" << endl;
    } else if (wt == weaponType::TWOHANDED) {
        cout << "Two-handed weapon" << endl;
    } else if (wt == weaponType::BOW) {
        cout << "Bow" << endl;
    } else if (wt == weaponType::CROSSBOW) {
        cout << "Crossbow" << endl;
    } else {
        cout << "Unknown type" << endl;
    }

    Player player1;
    player1.id = 1;
    player1.login = "warrior";
    player1.password = "12345";
    player1.printInfo();

    cout << "\nTesting magicWeapon:" << endl;
    magicWeapon custom("Staff", 15, 2, weaponType::TWOHANDED, 12);
    
    cout << "Custom magic weapon:" << endl;
    cout << "Name: " << custom.getName() << endl;
    cout << "Base damage: " << custom.getDamage() << endl;
    cout << "Extra damage: " << custom.getAddDamage() << endl;
    cout << "Total damage: " << (custom.getDamage() + custom.getAddDamage()) << endl;

    custom.testParentMethods();
    custom.attack();

    magicWeapon defaultMW;
    cout << "\nDefault magic weapon:" << endl;
    cout << "Name: " << defaultMW.getName() << endl;
    cout << "Extra damage: " << defaultMW.getAddDamage() << endl;
    
    return 0;
}
