#include <iostream>

using namespace std;

enum class weaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NON
};

enum class weaponIdc {
    a,
    b
};

class weapon {
private:
    weaponType type;
    weaponIdc idc;
    string name;
    float damage, weight;
    
public:
    weapon(string tnam = "NON", float tdam = 0, float twei = 0, 
           weaponType ttyp = weaponType::NON, weaponIdc tidc = weaponIdc::a) {
        this->name = tnam;
        this->damage = tdam;
        this->weight = twei;
        this->type = ttyp;
        this->idc = tidc;
        cout << "\nWEAPON CREATED;\n";
    }

    ~weapon();
    
    string getName() const;
    float getWeight() const;
    virtual float getDamage() const;
    
    // 4. Операторы сравнения
    bool operator>(const weapon& other) const {
        return this->getDamage() > other.getDamage();
    }
    
    bool operator<(const weapon& other) const {
        return this->getDamage() < other.getDamage();
    }
    
    weaponType getType() const;
    weaponIdc getIdc() const;
    virtual void attack() = 0;
};

class magicWeapon : public weapon {
private:
    float addDamage;
    
public:
    magicWeapon(string tnam, float tdam, float twei, weaponType ttyp, 
                weaponIdc tidc, float tadd)
        : weapon(tnam, tdam, twei, ttyp, tidc), addDamage(tadd) {};
    
    magicWeapon() : magicWeapon("EXCALIBUR", 25.7, 237, 
                                weaponType::BOW, weaponIdc::b, 25) {};
    
    float getAddDamage() const;
    float getDamage() const override;
    void attack() override;
};

weapon::~weapon() {
    cout << "\nWEAPON DESTROYED;\n";
}

class shotWeapon : public weapon {
private:
    bool exists;
    
public:
    shotWeapon(string tnam = "NON", float tdam = 0, float twei = 0, 
               weaponType ttyp = weaponType::NON, weaponIdc tidc = weaponIdc::a, 
               bool texi = 0) 
        : weapon(tnam, tdam, twei, ttyp, tidc), exists(texi) {};
    
    bool getExists() const;
    void attack() override;
};

string weapon::getName() const {
    return name;
}

float weapon::getDamage() const {
    return damage;
}

float weapon::getWeight() const {
    return weight;
}

weaponType weapon::getType() const {
    return type;
}

weaponIdc weapon::getIdc() const {
    return idc;
}

float magicWeapon::getAddDamage() const {
    return addDamage;
}

float magicWeapon::getDamage() const {
    return weapon::getDamage() + addDamage;
}

bool shotWeapon::getExists() const {
    return exists;
}

void magicWeapon::attack() {
    cout << "\nMagic attack\n";
}

void shotWeapon::attack() {
    if (getExists() == false) {
        cout << "Single use attack" << endl;
        this->exists = true;
    }
    else {
        cout << "Already used" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    magicWeapon mw("Magic Sword", 30, 5, weaponType::ONEHANDED, 
                   weaponIdc::a, 15);
    
    cout << "Magic weapon: " << mw.getName() << endl;
    cout << "Base damage: " << mw.weapon::getDamage() << endl;
    cout << "Extra damage: " << mw.getAddDamage() << endl;
    cout << "Total damage: " << mw.getDamage() << endl;
    
    class TestWeapon : public weapon {
    public:
        TestWeapon(string n, float d) : weapon(n, d, 1, weaponType::ONEHANDED) {}
        void attack() override {}
    };
    
    TestWeapon sword("Sword", 35);
    magicWeapon magicAxe("Magic Axe", 25, 6, weaponType::TWOHANDED, 
                         weaponIdc::b, 20);  // Итого 45 урона
    
    cout << "Sword damage: " << sword.getDamage() << endl;
    cout << "Magic Axe total damage: " << magicAxe.getDamage() << endl;
    
    if (magicAxe > sword) {
        cout << magicAxe.getName() << " > " << sword.getName() 
             << " (" << magicAxe.getDamage() << " > " << sword.getDamage() << ")" << endl;
    } else {
        cout << magicAxe.getName() << " <= " << sword.getName() 
             << " (" << magicAxe.getDamage() << " <= " << sword.getDamage() << ")" << endl;
    }
    
    if (sword < magicAxe) {
        cout << sword.getName() << " < " << magicAxe.getName() 
             << " (" << sword.getDamage() << " < " << magicAxe.getDamage() << ")" << endl;
    }
    
    // Ещё тесты
    magicWeapon staff("Staff", 20, 3, weaponType::TWOHANDED, weaponIdc::a, 10);
    TestWeapon bow("Bow", 28);
    
    cout << "\nStaff total damage: " << staff.getDamage() << endl;
    cout << "Bow damage: " << bow.getDamage() << endl;
    
    if (staff > bow) {
        cout << "Staff stronger than Bow" << endl;
    }
    
    if (bow < staff) {
        cout << "Bow weaker than Staff" << endl;
    }
    
    return 0;
}
