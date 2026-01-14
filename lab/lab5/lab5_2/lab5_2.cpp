#include <iostream>

using namespace std;

enum class Type {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NONE
};

enum class Id {
    A,
    B
};

class Arm {
private:
    Type typ;
    Id id;
    string title;
    float power, mass;
public:
    Arm(string t = "NONE", float p = 0, float m = 0, Type ty = Type::NONE, Id i = Id::A) {
        this->title = t;
        this->power = p;
        this->mass = m;
        this->typ = ty;
        this->id = i;
        cout << "\nWEAPON CREATED;\n";
    }

    ~Arm();
    string getTitle();
    float getMass();
    virtual float getPower();
    Type getTyp();
    Id getId();

    virtual void hit() = 0;
};

class MagicArm : public Arm {
private:
    float extraPower;
public:
    MagicArm(string t, float p, float m, Type ty, Id i, float ep)
        : Arm(t, p, m, ty, i), extraPower(ep) {};
    MagicArm() : MagicArm("EXCALIBUR", 25.7, 237, Type::BOW, Id::B, 25) {};
    float getExtraPower();
    float getPower();
    void hit() override;
};

Arm::~Arm() {
    cout << "\nWEAPON DESTROYED;\n";
}

class SingleUseArm : public Arm {
private:
    bool used;
public:
    SingleUseArm(string t = "NONE", float p = 0, float m = 0, Type ty = Type::NONE, Id i = Id::A, bool u = false) :
        Arm(t, p, m, ty, i), used(u) {};
    bool getUsed();
    void hit() override;
};

string Arm::getTitle() {
    return title;
}
float Arm::getPower() {
    return power;
}
float Arm::getMass() {
    return mass;
}
Type Arm::getTyp() {
    return typ;
}
Id Arm::getId() {
    return id;
}
float MagicArm::getExtraPower() {
    return MagicArm::extraPower;
}
float MagicArm::getPower() {
    return Arm::getPower() + extraPower;
}
bool SingleUseArm::getUsed() {
    return used;
}
float compare(float dam1, float dam2) {
    return dam1 > dam2 ? dam1 : dam2;
}
void MagicArm::hit() {
    cout << "\nMagic attack\n";
}
void SingleUseArm::hit() {
    if (getUsed() == false) {
        cout << "Single use attack" << endl;
        this->used = true;
    }
    else {
        cout << "Already used" << endl;
    }
};


template <class T>

class Hand
{
private:
    T left;
    T right;
public:
    Hand(T l, T r) : left(l), right(r) {};
    T getLeft()
    {
        return left;
    }
    T getRight()
    {
        return right;
    }
    void setLeft(T t)
    {
        left = t;
    }
    void setRight(T t)
    {
        right = t;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    MagicArm x;
    SingleUseArm y;
    SingleUseArm z = {"NONE", 12, 200, Type::ONEHANDED, Id::A, 1};
    x.hit();
    y.hit();
    y.hit();

    Hand<int> h1(11, 12);
    Hand<Type> h2(Type::CROSSBOW, Type::ONEHANDED);
    cout << h1.getLeft() << " " << h1.getRight() << endl;

    Type t1 = h2.getLeft();
    if (t1 == Type::CROSSBOW) {
        cout << "Type in left hand - CROSSBOW" << endl;
    }
}
