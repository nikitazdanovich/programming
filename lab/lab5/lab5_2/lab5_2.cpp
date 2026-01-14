#include <iostream>

using namespace std;

enum class WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NONE
};

enum class WeaponId {
    A,
    B
};

class Weapon {
private:
    WeaponType type;
    WeaponId id;
    string name;
    float damage, weight;
public:
    Weapon(string n = "NONE", float d = 0, float w = 0, WeaponType t = WeaponType::NONE, WeaponId i = WeaponId::A) {
        this->name = n;
        this->damage = d;
        this->weight = w;
        this->type = t;
        this->id = i;
        cout << "\nWEAPON CREATED;\n";
    }

    ~Weapon();
    string getName();
    float getWeight();
    virtual float getDamage();
    WeaponType getType();
    WeaponId getId();

    virtual void Attack() = 0;
};

class MagicWeapon : public Weapon {
private:
    float extraDamage;
public:
    MagicWeapon(string n, float d, float w, WeaponType t, WeaponId i, float ed)
        : Weapon(n, d, w, t, i), extraDamage(ed) {};
    MagicWeapon() : MagicWeapon("Greatbow", 25.7, 237, WeaponType::BOW, WeaponId::B, 25) {};
    float getExtraDamage();
    float getDamage();
    void Attack() override;
};

Weapon::~Weapon() {
    cout << "\nWEAPON DESTROYED;\n";
}

class SingleUseWeapon : public Weapon {
private:
    bool used;
public:
    SingleUseWeapon(string n = "NONE", float d = 0, float w = 0, WeaponType t = WeaponType::NONE, WeaponId i = WeaponId::A, bool u = false) :
        Weapon(n, d, w, t, i), used(u) {};
    bool isUsed();
    void Attack() override;
};

string Weapon::getName() {
    return name;
}
float Weapon::getDamage() {
    return damage;
}
float Weapon::getWeight() {
    return weight;
}
WeaponType Weapon::getType() {
    return type;
}
WeaponId Weapon::getId() {
    return id;
}
float MagicWeapon::getExtraDamage() {
    return MagicWeapon::extraDamage;
}
float MagicWeapon::getDamage() {
    return Weapon::getDamage() + extraDamage;
}
bool SingleUseWeapon::isUsed() {
    return used;
}
float compare(float dam1, float dam2) {
    return dam1 > dam2 ? dam1 : dam2;
}
void MagicWeapon::Attack() {
    cout << "\nАтакуем магическим оружием\n";
}
void SingleUseWeapon::Attack() {
    if (isUsed() == false) {
        cout << "Атакуем одноразовым оружием" << endl;
        this->used = true;
    }
    else {
        cout << "Оружие уже было использовано" << endl;
    }
};

template <class T>
class WeaponHand {
private:
    T leftWeapon;
    T rightWeapon;
public:
    WeaponHand(T left, T right) : leftWeapon(left), rightWeapon(right) {};
    T getLeftWeapon() {
        return leftWeapon;
    }
    T getRightWeapon() {
        return rightWeapon;
    }
    void setLeftWeapon(T weapon) {
        leftWeapon = weapon;
    }
    void setRightWeapon(T weapon) {
        rightWeapon = weapon;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    MagicWeapon magicWeapon;
    SingleUseWeapon singleUseWeapon;
    SingleUseWeapon anotherWeapon = {"NONE", 12, 200, WeaponType::ONEHANDED, WeaponId::A, 1};
    
    magicWeapon.Attack();
    singleUseWeapon.Attack();
    singleUseWeapon.Attack();

    WeaponHand<int> weaponIds(11, 12);
    WeaponHand<WeaponType> weaponTypes(WeaponType::CROSSBOW, WeaponType::ONEHANDED);
    
    cout << weaponIds.getLeftWeapon() << " " << weaponIds.getRightWeapon() << endl;

    WeaponType leftType = weaponTypes.getLeftWeapon();
    if (leftType == WeaponType::CROSSBOW) {
        cout << "Type in left hand - CROSSBOW" << endl;
    }
}
